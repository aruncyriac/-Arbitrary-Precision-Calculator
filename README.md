# Arbitrary Precision Calculator

## Overview
Arbitrary-precision arithmetic, also known as big-number arithmetic, enables calculations on numbers with unlimited precision, constrained only by system memory. Unlike standard fixed-precision arithmetic (8-64 bits) used in most ALUs, this approach ensures accurate computation of extremely large numbers.

This project implements fundamental mathematical operations for large numbers using an Abstract Data Type (ADT) such as a linked list to store and process numerical values.

## Features
- Supports arbitrary-length integers.
- Implements core arithmetic operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`x`)
  - Division (`/`)
- Efficient memory management using linked lists.
- Command-line interface for ease of use.

## Usage
Run the program with the following command format:
```sh
./a.out [operand1] [operator] [operand2]
```
### Example
```sh
./a.out 123456789123456789 + 987654321987654321
```

## Implementation Details
- **Linked List Representation:** Stores each digit as a node to handle arbitrarily large numbers.
- **Optimized Arithmetic Operations:** Implements addition, subtraction, multiplication, and division efficiently.
- **Input Validation:** Ensures correct formatting and error handling for invalid inputs.

## Requirements
- GCC compiler (or any C compiler)
- Compatible with Linux/macOS/Windows

## Compilation & Execution
Compile the program using:
```sh
gcc -o calculator calculator.c
```
Run the program with:
```sh
./calculator 123456789 + 987654321
```
