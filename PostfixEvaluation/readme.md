# Postfix Expression Evaluation

## Overview

This program evaluates a postfix expression (Reverse Polish Notation) using a stack. It handles single-digit operands and the operators `+`, `-`, `*`, and `/`. The program ensures that the input expression is valid and calculates the correct result using a stack-based approach.

---

## Features

1. **Stack-Based Implementation**:
   - Uses a custom stack structure to manage operands and intermediate results.
   
2. **Operator Support**:
   - Supports basic arithmetic operations: Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`).
   
3. **Error Handling**:
   - Detects malformed expressions, including:
     - Insufficient operands for operators.
     - Division by zero.
     - Invalid characters in the expression.
   
4. **Efficiency**:
   - Evaluates the expression in a single pass.

---

## How It Works

1. **Input**:  
   - A valid postfix expression (e.g., `56+2*`).
   
2. **Evaluation**:
   - Scans the postfix expression character by character:
     - **Operands**: Push digits onto the stack.
     - **Operators**: Pop two operands from the stack, apply the operator, and push the result back onto the stack.
   - Continues until the entire expression is processed.

3. **Output**:  
   - The final result is the only value remaining in the stack.

---

## Example

### Sample Input:
```c
const char* expression = "656+5*2*";
```

### Sample Execution:
```bash
gcc postfix_evaluation.c -o postfix_evaluation
./postfix_evaluation
```

### Sample Output:
```
Result of postfix expression '656+5*2*' is: 170
```

---

## Program Flow

1. **Operand Handling**:
   - Push digits directly onto the stack after converting them from characters to integers.
   
2. **Operator Handling**:
   - Pop the top two operands from the stack.
   - Perform the operation (`+`, `-`, `*`, `/`).
   - Push the result back onto the stack.

3. **Final Result**:
   - After processing the expression, the result is the only item left in the stack.

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `postfix_evaluation.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc postfix_evaluation.c -o postfix_evaluation
   ```
4. Run the program:
   ```bash
   ./postfix_evaluation
   ```

---

## Limitations

1. **Single-Digit Operands**:
   - Only handles single-digit numbers (e.g., `1`, `5`), not multi-digit numbers (e.g., `12`).
   
2. **No Floating-Point Arithmetic**:
   - Works only with integer operands and results.

3. **Malformed Expressions**:
   - Assumes the input is a valid postfix expression but provides error messages for common issues.

---

