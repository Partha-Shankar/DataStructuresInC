# Stack Operations Program

## Overview

This program demonstrates basic stack operations and includes functionality to check if a given number is a palindrome using a stack. The stack is implemented using an array, with a fixed maximum size of 4. The program provides a menu-driven interface to interact with the stack.

---

## Features

1. **Stack Operations**:
   - **Push**: Add an element to the top of the stack.
   - **Pop**: Remove and return the top element of the stack.
   - **Display**: Show all elements in the stack.

2. **Palindrome Checker**:
   - Checks whether a given number is a palindrome using the stack.

3. **Menu-Driven Interface**:
   - Easy-to-use menu to perform the above operations interactively.

---

## Program Flow

1. **Menu**:  
   - The user is presented with a menu to perform operations on the stack or check for palindromes.
   - Options include:
     - Push an element onto the stack.
     - Pop an element from the stack.
     - Display the stack elements.
     - Check if a number is a palindrome.
     - Exit the program.

2. **Stack Implementation**:  
   - The stack is implemented using an array of fixed size (`max = 4`).
   - Handles stack overflow and underflow scenarios gracefully.

3. **Palindrome Checking**:  
   - A number is pushed onto the stack digit by digit.
   - The stack is then used to check if the number reads the same backward as forward.

---

## Example

### Sample Run:
#### Input:
```
Menu:
1. Push an element onto the stack
2. Pop an element from the stack
3. Display stack elements
4. Check if a number is a palindrome
5. Exit
Enter your choice: 1
Enter an element to push: 10

Enter your choice: 3
```

#### Output:
```
Element 10 pushed onto stack.

Stack elements (top to bottom):
10
```

#### Palindrome Check:
#### Input:
```
Enter your choice: 4
Enter a number to check for palindrome: 121
```

#### Output:
```
121 is a palindrome.
```

---

## Compilation and Execution

### Steps to compile and run:
1. Save the code in a file named `stack_operations.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc stack_operations.c -o stack_operations
   ```
4. Run the program:
   ```bash
   ./stack_operations
   ```

---

## Limitations

1. The stack size is fixed at 4 elements.
2. The program only works with single integers for stack operations.
3. Palindrome check is limited to integers only.

---

## License

This project is open-source and does not include a specific license.
