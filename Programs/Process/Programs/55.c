#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == 0) { // Child process
        printf("Child process running...\n");
        // Simulate some work
        sleep(5);
        printf("Child process stopping...\n");
        // Stop the child process explicitly
        //raise(SIGSTOP);
	//printf("exited");
        //exit(0);
	while(1);
    } else if (pid > 0) { // Parent process
        printf("Parent process waiting for child...\n");
        wpid = waitpid(pid, &status, WUNTRACED);

        if (WIFSTOPPED(status)) {
            printf("Child process stopped.\n");
        } else {
            printf("Unexpected status received.\n");
        }
    } else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

