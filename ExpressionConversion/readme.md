# Infix to Postfix Conversion

## Overview

This program converts a given infix expression (e.g., `A+B*C`) into a postfix expression (e.g., `ABC*+`). It uses a stack-based approach to handle operators, operands, and parentheses, ensuring proper precedence and associativity rules.

---

## Features

- **Operator Precedence Handling**: Supports operators like `+`, `-`, `*`, `/`, `%`, and `^`.
- **Parentheses Management**: Handles nested parentheses for complex expressions.
- **Error Handling**: Includes stack overflow and underflow checks.
- **Alphanumeric Operands**: Supports single-character alphanumeric operands (e.g., `A`, `B`, `1`, `2`).

---

## Program Flow

1. **Input**:  
   - The user enters an infix expression as a string.
   - The expression can include operators (`+`, `-`, etc.), operands (alphanumeric), and parentheses.

2. **Processing**:  
   - The program uses a stack to temporarily hold operators and parentheses while scanning the infix expression.
   - Operators are popped from the stack based on precedence rules and added to the postfix expression.

3. **Output**:  
   - The converted postfix expression is displayed.

---

## Example

### Sample Input:
```
Enter infix expression: A+(B*C)
```

### Sample Output:
```
Postfix expression: ABC*+
```

---

## Compilation and Execution

### To compile and run the program:

1. Save the code in a file named `infix_to_postfix.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program:
   ```bash
   gcc infix_to_postfix.c -o infix_to_postfix
   ```
4. Run the compiled program:
   ```bash
   ./infix_to_postfix
   ```

---

## Limitations

- The program supports single-character operands only.
- The stack size is limited to `20` elements (can be increased by modifying `#define MAX`).

---

## License

This project is open-source and does not include a specific license.
