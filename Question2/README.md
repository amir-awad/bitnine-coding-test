# Implementing F(n) = F(n-2) + F(n-3) in Three Different Ways

This README file explains three different ways to implement the recurrence relation F(n) = F(n-2) + F(n-3) and discusses the advantages and disadvantages of each approach. The three approaches are:

1. Matrix Exponentiation
2. Dynamic Programming with Optimized Space
3. Recursive Approach

## 1. Matrix Exponentiation

The first approach uses matrix exponentiation to calculate the Fibonacci-like sequence. In this method, we use a 3x3 matrix and perform matrix multiplication to compute the Fibonacci-like values efficiently. The advantage of this approach is that it has a time complexity of O(log n), where n is the input number. This makes it highly efficient for calculating Fibonacci-like numbers for large values of n. However, the disadvantage is that the implementation requires a good understanding of matrix exponentiation and matrix multiplication algorithms, which may be complex for beginners.

## 2. Dynamic Programming with Optimized Space

The second approach utilizes dynamic programming with optimized space to calculate the Fibonacci-like sequence. It uses an array of size 3 to store the Fibonacci-like values iteratively. The advantage of this approach is that it has a space complexity of O(1) since it only uses a fixed-size array to store the Fibonacci-like values. Additionally, it has a time complexity of O(n), making it efficient for calculating Fibonacci-like numbers. However, the disadvantage is that it requires iterating through a loop to compute the Fibonacci-like values, which may be slightly slower compared to the matrix exponentiation approach for large values of n.

## 3. Recursive Approach

The third approach uses a recursive function to calculate the Fibonacci-like sequence. It directly follows the given recurrence relation F(n) = F(n-2) + F(n-3). The advantage of this approach is its simplicity and ease of understanding. It is straightforward to implement and requires minimal code. However, the disadvantage of this approach is that it has a high time complexity of O(2^n). The recursive approach can lead to redundant function calls and repeated calculations, resulting in slower execution for larger values of n.

## Development Environment

The source code provided in this repository is written in C programming language. To compile and run the code, you need a C compiler installed on your system such as:

- GCC (GNU Compiler Collection): Available for Linux, macOS, and Windows.

## Compiling and Running the Source Code

To compile and run the source code, follow these steps:

1. Open a terminal or command prompt.

2. Navigate to the directory where the source code file is located.

3. You should add main function to the code. For example, you can use the following code:

   ```c
   #include <stdio.h>
   int main() {

       for(int i = 0; i < 10; i++) {
           printf("F1(%d): %lld, F2(%d): %lld, F3(%d): %lld", i, F1(i), i, F2(i), i, F3(i));
       }

       return 0;
   }
   ```

4. Use the appropriate compiler command to compile the code. For example, with GCC, you can use the following command

   ```shell
   gcc main.c -o main_executable
   ```

5. Finally, run the compiled program using the following command:

   ```shell
   ./main_executable
   ```
