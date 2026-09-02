# holbertonschool-simple_shell

A simple, lightweight Unix command-line interpreter (shell) written in C as part of the low-level programming curriculum at Holberton School.

## Description
This project replicates the basic functionalities of a standard Unix shell. It prompts the user for input, reads the command line, parses it into arguments, and executes the specified command by creating a child process. It supports interactive mode, non-interactive mode, custom path resolution, and basic built-in commands.

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
### Interactive Mode
Run the compiled binary directly from your terminal:
```bash
$ ./hsh
Shell$ ls -la
Shell$ pwd
Shell$ env
Shell$ exit
```

### Non-Interactive Mode
Pipe a single command or a script into the shell:
```bash
$ echo "ls -l" | ./hsh
$ echo "pwd" | ./hsh
```

## Project File Structure
* `main.h`: Core header file.
* `ssShell.c`: Contains the main entry point loop managing execution logic and exit states.
* `readline.c`: Handles inputs via `getline`, removes trailing newlines, and manages prompts.
* `tokenisation.c`: Contains `stringsplit` which leverages `strtok` to convert a raw string buffer into an array of commands and flags.
* `forkexec.c`: Dispatches path validation checks, forks the system process, handles execution environments, and captures process statuses.
* `printenv.c`: Traverses and prints the inherited execution environment pointers array.
* `path.c`: Contains path searching and resolution features (`_getenv`, `find_path`).
