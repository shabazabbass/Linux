# Vim Basics — Beginner Friendly Notes

Vim is a powerful text editor that has **three main modes** and many shortcuts. This guide is for beginners.

---

## 1️⃣ Vim Modes

### 1. Normal Mode
- Default mode when you open Vim.
- Press **Escape (Esc)** to return to normal mode from other modes.
- Run Vim commands:
  - `:<vim command>` → e.g., `:set number`, `:set relativenumber`, `:set shiftwidth=4`, `:set number!`
  - `:!<bash command>` → e.g., `:!ls`, `:!pwd`

### 2. Insert Mode
- You must be in normal mode to enter insert mode.
- Ways to enter insert mode:
  - `i` → insert before the cursor
  - `a` → insert after the cursor
  - `o` → insert a new line below the current line

### 3. Visual Mode
- Used to select text.
- Types of visual mode:
  - `v` → visual character mode
  - `Shift + v` → visual line mode
  - `Ctrl + v` → visual block mode

---

## 2️⃣ Basic Vim Shortcuts

| Shortcut | Action |
|----------|--------|
| `d`      | delete content before the word |
| `D`      | delete content after the cursor |
| `dd`     | delete the whole line |
| `3dd`    | delete 3 lines |
| `c`      | change (deletes content and goes to insert mode) |
| `y`      | copy (yank) |
| `h`      | move cursor left |
| `j`      | move cursor down |
| `k`      | move cursor up |
| `l`      | move cursor right |
| `r`      | replace a single character |
| `w`      | jump to next word |
| `b`      | jump to previous word |
| `dw`     | delete a word |
| `2dw`    | delete 2 words |
| `diw`    | delete the whole word under cursor |
| `ciw`    | change word under cursor |
| `e`      | jump to end of word |
| `I`      | move to beginning of line (insert) |
| `0`      | move cursor to beginning of line |
| `$`      | move cursor to end of line |
| `d0`     | delete from cursor to beginning of line |
| `yiw`    | copy a word |
| `ci"`   | change content inside quotes |
| `%`      | jump between matching parentheses |
| `d%`     | delete including parentheses |
| `t*`     | jump before occurrence of `*` |
| `f*`     | jump to occurrence of `*` |
| `T*`     | jump backward before `*` |
| `gg`     | move to beginning of file |
| `Shift+G`| move to end of file |
| `123G`   | move to line 123 |
| `>`      | indent right |
| `<`      | indent left |
| `==`     | auto-indent current line |
| `gg=G`   | auto-indent entire file |
| `#`      | jump to previous occurrence of word under cursor |
| `*`      | jump to next occurrence of word under cursor |
| `m`      | mark a position (`ma` to mark, `'a` to go back) |
| `zz`     | center current line on screen |
| `.`      | repeat previous command |
| `dt"`   | delete until quotation mark |
| `"7p`   | paste from register 7 |

---

## 3️⃣ Searching and Replacing

- Find a word: `:/<word>`
  - `n` → next occurrence
  - `N` → previous occurrence
- Replace: `:%s/<old>/<new>/g`
- Use visual mode to select text and replace in selection.

---

## 4️⃣ Registers and Macros

- `:reg` → shows contents of registers
- Macros:
  - `qa` → start recording in register `a`
  - Press `q` again to stop recording
  - `@a` → execute macro stored in register `a`

---

## 5️⃣ Installing Neovim

```bash
sudo apt install neovim
```

- You can install plugins for additional functionality (e.g., via `vim-plug`).

---

## 6️⃣ Extra Tips for Beginners

1. **Undo / Redo:**
   - `u` → undo
   - `Ctrl + r` → redo

2. **Save and Quit:**
   - `:w` → save
   - `:q` → quit
   - `:wq` → save and quit
   - `:q!` → quit without saving

3. **Move Faster:**
   - `Ctrl + d` → scroll down half page
   - `Ctrl + u` → scroll up half page

4. **Split Windows:**
   - `:split filename` → horizontal split
   - `:vsplit filename` → vertical split
   - `Ctrl + w + h/j/k/l` → move between splits

5. **Tabs:**
   - `:tabnew filename` → open new tab
   - `gt` → next tab
   - `gT` → previous tab

6. **Use `:help`** whenever unsure:
   - `:help <command>` → detailed explanation of the command

