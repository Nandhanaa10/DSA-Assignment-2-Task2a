# DSA-Assignment-2-Task2a
## Project Description
This project implements a modular comment-post-reply system in C.  
Each module is implemented in separate `.c` and `.h` files for clarity and modularity.

```
## Folder Structure
106124074/
|- code/
| |- comment.c
| |- comment.h
| |- main.c
| |- platform.c
| |- platform.h
| |- post.c
| |- post.h
| |- reply.c
| |- reply.h
|- Makefile
|- README.md
|- Git.docx
```

## Build & Run Instructions
1. Open **Command Prompt**, **PowerShell**, or **Git Bash** in the `106124074` folder.  
2. Build the project:
```bash
make
Run the program:

bash
./app      
Clean compiled files:

bash
make clean
Note: Ensure make and gcc are installed on your system.

Assumptions
All headers are included correctly in code/.

main.c contains int main() and uses functions from other modules.

Memory allocated via malloc or strdup is freed appropriately.

Platform-specific helpers are implemented in platform.c/h.

Each module (comment, post, reply, platform) has its own .c and .h files for modularity.

Notes
Code follows good modular coding practices.

Comments are added in the code where necessary.

String literals are handled safely using strdup when dynamic memory is needed.

Author 
Roll Number: 106124074
Name: Nandhanaa
