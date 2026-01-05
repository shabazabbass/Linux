# wait(), waitpid() — Quick Notes (Linux/Unix)

The **wait family** of system calls lets a parent process:

- Collect the **termination status** of a child process
- Prevent zombie processes
- Optionally wait for a **specific child**

After a child exits → it becomes a **zombie** until the parent calls `wait()` / `waitpid()`.

---

## ✔️ Core Behavior

```text
fork()   → creates child
child    → finishes / exits
temporarily becomes ZOMBIE
parent   → calls wait()/waitpid() to collect status
```

Once collected → the entry is removed from the process table.

---

## 🧩 Function Prototypes

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
```

Return value:
- child PID on success
- `-1` on error (and sets `errno`)

`wstatus` may be `NULL` if status is not required.

---

# ✅ wait()

Waits for **any terminated child**.

- Blocks until *one* child finishes
- Does **not** choose which child

```c
pid_t child = wait(&status);
```

---

# ✅ waitpid()

Supports **selective & non‑blocking waiting**.

```c
pid_t waitpid(pid_t pid, int *status, int options);
```

| pid value | Meaning |
|---------|--------|
| `> 0` | Wait for that specific child PID |
| `-1` | Wait for **any child** (like wait()) |
| `0` | Any child in same process group |
| `< -1` | Any child in process group = `abs(pid)` |

**options flags** (bit‑wise OR):

| Option | Meaning |
|------|--------|
| `0` | Blocking wait |
| `WNOHANG` | Non‑blocking → return immediately |
| `WUNTRACED` | Report stopped children |
| `WCONTINUED` | Report resumed children |

---

## 🧮 Status Inspection Macros

Used on `status` returned by wait/waitpid.

```c
WIFEXITED(status)     // child terminated normally
WEXITSTATUS(status)   // exit() status code

WIFSIGNALED(status)   // child killed by signal
WTERMSIG(status)      // signal number

WIFSTOPPED(status)    // child stopped
WSTOPSIG(status)      // signal that stopped it

WIFCONTINUED(status)  // child resumed (SIGCONT)
```

> Use these macros instead of manually decoding bits.

---

# ✅ Example 1 — Basic wait()

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child running...\n");
        sleep(2);
        printf("Child exiting with status 5\n");
        exit(5);
    }

    int status;
    pid_t c = wait(&status);

    printf("Parent: collected child %d\n", c);

    if (WIFEXITED(status))
        printf("Exit status = %d\n", WEXITSTATUS(status));
}
```

Output → child exit code printed, no zombie remains.

---

# ✅ Example 2 — waitpid() for a Specific Child

```c
pid_t p1 = fork();
if (p1 == 0) { sleep(3); exit(10); }

pid_t p2 = fork();
if (p2 == 0) { sleep(1); exit(20); }

int status;

// wait only for p2 first
waitpid(p2, &status, 0);
printf("Collected p2 → %d\n", WEXITSTATUS(status));

// now collect remaining child
waitpid(p1, &status, 0);
printf("Collected p1 → %d\n", WEXITSTATUS(status));
```

Parent chooses which child to reap first.

---

# ✅ Example 3 — Non‑Blocking waitpid() (WNOHANG)

```c
int status;
pid_t r = waitpid(-1, &status, WNOHANG);

if (r == 0)
    printf("No child exited yet\n");
else if (r > 0)
    printf("Child %d exited\n", r);
else
    perror("waitpid");
```

Useful in **event loops / servers**.

---

# 🧱 Zombie vs Orphan Quick Notes

| Term | Meaning |
|------|--------|
| Zombie | Child exited, parent **did not** call wait() |
| Orphan | Parent exited → child adopted by `init`/`systemd` |

`init/systemd` automatically reaps orphans → no zombies.

---

## 🚩 Common Errors & Fixes

| Issue | Reason | Fix |
|------|--------|-----|
| `ECHILD` | No child processes | Ensure fork() succeeded |
| Child stays zombie | Parent didn’t call wait | Call wait()/waitpid() |
| Wrong status reading | Not using macros | Use WIF* / WEXITSTATUS |

---

## 💡 Usage Patterns

- Use **wait()** → simple case, any child
- Use **waitpid()** →
  - when multiple children exist
  - when you need **non‑blocking** behavior
  - when you must reap a **specific process**

---

If you want, I can also export these notes as **PDF / DOCX / PPT / TXT** for download.


---

# 🔧 Additional Examples (Advanced Scenarios)

## ✅ Example 4 — Reaping Multiple Children in a Loop

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Child %d exiting
", i);
            exit(10 + i);
        }
    }

    int status;
    pid_t pid;

    while ((pid = wait(&status)) > 0) {
        if (WIFEXITED(status))
            printf("Reaped child %d → status %d
", pid, WEXITSTATUS(status));
    }

    printf("No more children (wait returned -1)
");
}
```

> Pattern used by shells & servers to reap all children.

---

## ✅ Example 5 — Detecting Signal‑Termination (WIFSIGNALED)

```c
pid_t pid = fork();

if (pid == 0) {
    printf("Child will be killed by SIGKILL
");
    raise(SIGKILL);
}

int status;
waitpid(pid, &status, 0);

if (WIFSIGNALED(status)) {
    printf("Child killed by signal %d
", WTERMSIG(status));
}
```

Useful when debugging crashes.

---

## ✅ Example 6 — Non‑Blocking Polling Loop (WNOHANG)

```c
int status;
while (1) {
    pid_t r = waitpid(-1, &status, WNOHANG);

    if (r > 0) {
        printf("Child %d exited (%d)
", r, WEXITSTATUS(status));
    } else if (r == 0) {
        printf("Working… child not finished yet
");
        sleep(1);
    } else {
        perror("waitpid");
        break;
    }
}
```

Pattern for **event‑driven daemons**.

---

## ✅ Example 7 — Waiting for Stopped & Continued Processes

```c
int status;
pid_t pid = fork();

if (pid == 0) {
    raise(SIGSTOP);   // stop child
    sleep(1);
    raise(SIGCONT);   // resume child
    exit(0);
}

waitpid(pid, &status, WUNTRACED | WCONTINUED);

if (WIFSTOPPED(status))
    printf("Child stopped (signal %d)
", WSTOPSIG(status));

waitpid(pid, &status, WUNTRACED | WCONTINUED);

if (WIFCONTINUED(status))
    printf("Child continued
");
```

Useful in **job‑control shells**.

---

## ✅ Example 8 — Handling ECHILD Gracefully

```c
int status;
pid_t r = waitpid(-1, &status, 0);

if (r == -1 && errno == ECHILD)
    printf("No child processes to reap
");
```

Prevents unwanted errors when no children exist.

---

## ✅ Example 9 — Parent Exits First (Orphan Adoption)

```c
pid_t pid = fork();

if (pid == 0) {
    sleep(3);
    printf("Child adopted by init/systemd
");
    exit(0);
}

printf("Parent exiting immediately
");
exit(0);
```

The child becomes an **orphan** → adopted by `init/systemd`, then reaped automatically.

---

If you want more, I can add:
- real‑world interview questions
- diagrams
- flowcharts for wait/waitpid behavior
- troubleshooting cheatsheet

Tell me what style you prefer 🙂
