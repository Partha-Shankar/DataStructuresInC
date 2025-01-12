# Single Linked List Implementation

## Overview

This program demonstrates the implementation of a **Single Linked List** (SLL) in C, which is a fundamental data structure. It allows dynamic memory allocation where each node points to the next node in the sequence. The program performs various operations like insertion, deletion, and traversal, which are useful for understanding how a linked list works.

---

## Features

1. **Dynamic Memory Allocation**:
   - The list grows or shrinks dynamically based on the operations, with each node being allocated memory as needed.
   
2. **Basic Linked List Operations**:
   - **Insert at Front**: Adds a new node at the beginning of the list.
   - **Insert at End**: Adds a new node at the end of the list.
   - **Delete from Front**: Removes the first node from the list.
   - **Delete from End**: Removes the last node from the list.
   - **Display List**: Prints all the nodes in the list.

3. **Stack and Queue Demonstrations**:
   - **Stack Operations**: Demonstrates stack-like behavior with insertions at the front and deletions from the front.
   - **Queue Operations**: Demonstrates queue-like behavior with insertions at the end and deletions from the front.

4. **Memory Management**:
   - The program efficiently manages memory by allocating and freeing nodes when required.

---

## How It Works

1. **Input**:  
   - User can input student details such as **USN**, **Name**, and **Average Marks** which will be stored in each node of the linked list.

2. **Operations**:
   - **Insert at Front**: A new node is created and inserted at the front of the list.
   - **Insert at End**: A new node is added at the end of the list.
   - **Delete from Front**: The node at the front is removed from the list.
   - **Delete from End**: The last node is removed from the list.

3. **Output**:  
   - The list's current state is displayed, showing the student information for each node.

---

## Example

### Sample Input:
```c
Enter the number of students to create: 2
Enter USN, Name, Average Marks:
1DS19CS001 John 85.5
Enter USN, Name, Average Marks:
1DS19CS002 Jane 90.0
```

### Sample Execution:
```bash
gcc single_linked_list.c -o single_linked_list
./single_linked_list
```

### Sample Output:
```
Menu:
1: Create N Students
2: Insert at Front
3: Insert at End
4: Delete at Front
5: Delete at End
6: Display List
7: Demonstrate Stack
8: Demonstrate Queue
9: Exit
Enter your choice: 6

Student Data in List:
USN: 1DS19CS001, Name: John, Avg Marks: 85.50
USN: 1DS19CS002, Name: Jane, Avg Marks: 90.00

Total Students: 2
```

---

## Program Flow

1. **Node Creation**:
   - A new node is created with the user-provided data (USN, Name, Average Marks).
   - The node is linked to the existing list based on the operation (insert at front, insert at end).

2. **Insert and Delete Operations**:
   - **Insert at Front**: A new node is inserted at the start of the list by adjusting the `link` of the new node.
   - **Insert at End**: The new node is added at the end of the list by traversing to the last node and updating its `link`.
   - **Delete from Front**: The front node is removed and the list is updated.
   - **Delete from End**: The last node is removed by traversing the list to find the last node.

3. **Display**:
   - The program traverses the entire list, displaying each node’s details.

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `single_linked_list.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc single_linked_list.c -o single_linked_list
   ```
4. Run the program:
   ```bash
   ./single_linked_list
   ```

---

## Limitations

1. **Memory Management**:
   - The program allocates memory dynamically but does not handle advanced memory management like garbage collection in higher-level languages.

2. **No Search Functionality**:
   - The current program does not support searching for specific elements within the list.

3. **No Advanced Operations**:
   - Operations such as reversing the list, sorting the list, or inserting at a specific position are not included in the current implementation.

---
