# Pipex
![42](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)

Pipex is a command-line utility implemented in C as part of a project at 19 (42 Network). The goal is to create a program that simulates the behavior of Unix pipes, allowing the execution of multiple commands with input and output redirection.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Dependencies](#dependencies)

## Project Overview

The Pipex project focuses on understanding inter-process communication via pipes in Unix-like systems. The program takes input from a file, executes two commands using pipes, and outputs the result to another file, mimicking shell command behavior.

## Features

- Input redirection from a specified file
- Execution of two shell commands with piping
- Output redirection to a specified file
- Error handling for various scenarios (file access, command execution, etc.)
- Memory management to avoid leaks

## Requirements

- All the requirements for this project are outlined in the project description en.subject.pdf.
- Language: C, following the Norm.
- Memory Management: All allocated memory must be properly freed, and no memory leaks are tolerated.
- Makefile: The project must include a Makefile with at least the following rules: all, clean, fclean, re, and $(NAME).
- Compilation: Use `gcc` with the flags `-Wall`, `-Wextra`, and `-Werror`.
- External functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`, and your custom `ft_printf`.

## Installation

To build and run Pipex, you need a C compiler and `make`. This program is compatible with Unix-like systems.

1. Clone the repository:
```
git clone https://github.com/yourusername/pipex.git
```
```
cd pipex
```
2. Build the project:
```
make
```

4. The Makefile includes the following targets:
- `all`: Compiles the project
- `clean`: Removes object files
- `fclean`: Removes object files and the executable
- `re`: Rebuilds the project

## Usage

After building the program, you can start it by running:
```
./pipex file1 cmd1 cmd2 file2
```
This will execute the specified commands with the given input and output files.

## Examples

Here are some examples of how to use Pipex:
```
./pipex infile "ls -l" "wc -l" outfile
```
This behaves like: < infile ls -l | wc -l > outfile
```
./pipex infile "grep a1" "wc -w" outfile
```
This behaves like: ```< infile grep a1 | wc -w > outfile```

## Dependencies

Pipex relies on the C standard library and system calls. The project also allows the use of your own libft library.
