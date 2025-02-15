# CS_3502_Project1
Project 1 - CS 3502 Spring '25
# Multi-Threading and Inter-Process Communication in C

## Overview
This project explores multi-threading and inter-process communication (IPC) in C. It consists of two main components:

1. **Multi-Threading (Project A)** – Utilizes the `pthread` library to create and manage multiple threads, implementing mutexes to ensure resource protection and prevent race conditions.
2. **Inter-Process Communication (Project B)** – Implements IPC using pipes to facilitate data exchange between parent and child processes.

The project was completed using VS Code with a WSL (Windows Subsystem for Linux) environment instead of a virtual machine. Compilation and execution were performed within the terminal. The C/C++ extension by Microsoft was used in VS Code for better code editing and debugging support

## Dependencies
Before running the project, ensure you have the necessary dependencies installed:
-  GCC (GNU Compiler Collection) - Used for compiling C programs
-  Make - Helps automate the compilation process (recommended but optional)
-  pthread library - Required for multi-threading
-  WSL (Windows Subsystem for Linux) - If using Windows, ensure WSL is installed and set up properly.

## Installation Instructions
### 1. Install WSL (for Windows users):
-  Open PowerShell as Administrator and run:
   <br> `wsl --install`
-  Restart your computer if prompted
-  Set up a Linux distribution (Unbuntu is recommended for beginners but **not required**)

### 2. Install GCC and Make:
-  Open the WSL terminal and run:
  <br> `sudo apt update` <br> `sudo apt install build-essential`

### 3. Verify Installation:
-  Check if GCC is installed:
  <br> `gcc --version`
-  Check if Make is installed:
  <br> `make --version`

## Building and Running the Program
### Compilation
To compile this project, use the following steps:
#### 1. Navigate to the project directory:
  `cd/path/to/your/project`
#### 2. Compile Project A - Multi-Threading: 
`gcc -o threading threading.c -pthread`
#### 3. Compile Project B - IPC:
   `gcc -o ipc ipc.c`
### Execution
#### 1. Run Multi-Threading Program:
    `./threading`
#### 2. Run IPC Program:
    `./ipc`
### Notes
-  Ensure that the necessary permissions are granted to execute the compiled binaries.
-  Debugging tools such as `gdb` can be useful for troubleshooting errors.
-  Modifying the source files (threading.c and ipc.c) as needed to experiment with differen scenarios.
