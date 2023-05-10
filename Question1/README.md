# Fibonacci Calculation with Signal Handling

This README file provides an explanation of the code that performs mathematical operations (addition, multiplication, subtraction, and Fibonacci calculation) with signal handling. It also includes information about the development environment and instructions on how to compile and run the source code.

## Code Explanation

The provided code is written in C programming language and performs mathematical operations using functions and signal handling. Here's a brief explanation of the code:

- The code defines a `Node` structure that contains a `type` field representing the operation type (`ADD`, `MUL`, `SUB`) and a `value` field to store the calculated value.
- The `fib` function calculates the Fibonacci sequence up to the given input value `n` using dp with optimized space.
- There are separate functions (`addFuncIntegers`, `mulFuncIntegers`, `subFuncIntegers`) to perform mathematical operations on integers (`long long`).
- The `addFuncNodes`, `mulFuncNodes`, and `subFuncNodes` functions are similar to the above functions but operate on `Node` structures instead.
- The `signalHandler` function is a signal handler that catches segmentation faults (SIGSEGV) and modifies the program's execution flow based on the operation type.
- The `makeFunc` function dynamically creates and returns a function pointer based on the provided operation type.
- The `calc` function prints the calculated value of a `Node` structure.

The main function demonstrates the usage of the code by performing addition, multiplication, subtraction, and Fibonacci calculation operations.

## Development Environment

The source code provided in this repository is written in C programming language. To compile and run the code, you need a C compiler installed on your system. Here are the recommended development environments:

- Online Compilers: The code is compatible with online C compilers such as (programiz)[https://www.programiz.com/c-programming/online-compiler]. You can copy and paste the code into the respective online compiler and execute it.

- Linux Machine (Intel x86_64): To run the code on a Linux machine with an Intel x86_64 architecture, follow the instructions below.

## Compiling and Running the Source Code

To compile and run the source code on a Linux machine (Intel x86_64), follow these steps:

1. Open a terminal.

2. Navigate to the directory where the source code file is located.

3. Use the following command to compile the code:

   ```shell
   gcc main.c -o main_executable
   ```

4. Finally, run the compiled program using the following command:

   ```shell
   ./main_executable
   ```
