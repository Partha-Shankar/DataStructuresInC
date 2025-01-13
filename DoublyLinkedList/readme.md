# Doubly Linked List Implementation

## Overview

This program demonstrates the implementation of a **Doubly Linked List** (DLL) in C. A doubly linked list allows traversal in both forward and backward directions using `prev` and `next` pointers. The program supports various operations like inserting nodes, deleting nodes, and displaying the list.

---

## Features

1. **Dynamic Memory Allocation**:
   - Each node is dynamically allocated, and the list size adjusts based on operations performed.

2. **Basic DLL Operations**:
   - **Insert at Front**: Adds a node at the beginning of the list.
   - **Insert After Key**: Adds a node after a specific key node identified by its SSN.
   - **Insert at End**: Adds a node at the end of the list.
   - **Delete at End**: Removes the last node from the list.
   - **Display List**: Displays all nodes in the DLL and counts the total nodes.

3. **Memory Cleanup**:
   - Ensures all allocated memory is freed before exiting the program.

---

## How It Works

1. **Input**:  
   - Users provide employee details like **SSN**, **Name**, and **Department**. These details are stored in nodes of the doubly linked list.

2. **Operations**:
   - Insertions and deletions modify the DLL structure by updating the `prev` and `next` pointers of the relevant nodes.
   - The `display` function traverses the list to show the current status.

3. **Output**:  
   - Displays the contents of the list along with the total number of nodes.

---

## Example

### Sample Input:
```c
Enter SSN, Name, Dept: 12345 Alice HR
```

### Sample Execution:
```bash
gcc doubly_linked_list.c -o doubly_linked_list
./doubly_linked_list
```

### Sample Output:
```
Menu:
1. Insert at front
2. Insert after key SSN
3. Insert at end
4. Delete at end
5. Display DLL
6. Exit
Enter your choice: 5

DLL Status:
SSN: 12345, Name: Alice, Dept: HR
Number of nodes: 1
```

---

## Program Flow

1. **Node Creation**:
   - Each node contains three fields:
     - **SSN**: Unique identifier for an employee.
     - **Name**: Name of the employee.
     - **Department**: Department of the employee.
     - **Prev**: Pointer to the previous node.
     - **Next**: Pointer to the next node.

2. **Insertion**:
   - **At Front**: A new node is created and linked as the head of the list.
   - **After Key SSN**: A node is inserted after the node matching the given SSN.
   - **At End**: A new node is created and linked as the tail of the list.

3. **Deletion**:
   - The last node of the list is removed, and the `prev` pointer of the new last node is set to `NULL`.

4. **Display**:
   - The list is traversed, printing details of each node.

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `doubly_linked_list.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc doubly_linked_list.c -o doubly_linked_list
   ```
4. Run the program:
   ```bash
   ./doubly_linked_list
   ```

---

## Limitations

1. **No Advanced Search Functionality**:
   - Searching for nodes is done linearly; there is no optimized search.

2. **Memory Management**:
   - While memory is freed before exiting, improper use of pointers during modifications may lead to issues if extended further.

3. **No Backward Traversal**:
   - The current implementation doesn't explicitly traverse the DLL backward, although the structure supports it.

---
