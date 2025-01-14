# Singly Linked List Operations

## Overview

This program implements various operations on singly linked lists (SLLs) in C. It allows the creation of two separate linked lists, concatenates them, sorts the resulting list, and reverses it. The program demonstrates fundamental concepts of linked list manipulation, including traversal, insertion, and modification.

---

## Features

1. **Create and Initialize Lists**:
   - Users can create two separate linked lists by entering the number of elements and their values.

2. **Concatenate Two Lists**:
   - Joins two singly linked lists end-to-end into one.

3. **Sort the List**:
   - Sorts the elements of the concatenated list in ascending order using bubble sort.

4. **Reverse the List**:
   - Reverses the concatenated and sorted list.

5. **Display the List**:
   - Traverses the list to print its elements.

---

## How It Works

1. **Input**:
   - Users specify the number of elements in each list and their values.

2. **Operations**:
   - **Concatenation**: Traverses the first list to its end and links the second list to it.
   - **Sorting**: Uses a nested loop to sort the list by swapping data fields.
   - **Reversal**: Reverses the pointers in the list to change the traversal direction.

3. **Output**:
   - Displays the concatenated, sorted, and reversed lists after performing each operation.

---

## Example

### Sample Input:
```
Number of elements in List 1: 3
Enter 3 elements for List 1:
3 1 4
Number of elements in List 2: 2
Enter 2 elements for List 2:
5 2
```

### Sample Execution:
```bash
gcc list_operations.c -o list_operations
./list_operations
```

### Sample Output:
```
Concatenated list:
3 1 4 5 2
Sorted list:
1 2 3 4 5
Reversed list:
5 4 3 2 1
```

---

## Program Flow

1. **Node Creation**:
   - Each node is dynamically allocated and contains:
     - **Data**: An integer value.
     - **Next Pointer**: Points to the next node in the list.

2. **Concatenation**:
   - Links the last node of the first list to the first node of the second list.

3. **Sorting**:
   - Compares every node's data with the data of subsequent nodes, swapping them if necessary.

4. **Reversal**:
   - Iteratively reverses the `next` pointers of all nodes.

5. **Display**:
   - Traverses the list, printing the `data` field of each node.

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `list_operations.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc list_operations.c -o list_operations
   ```
4. Run the program:
   ```bash
   ./list_operations
   ```

---

## Functions in the Program

### `getnode()`
- Creates a new node for the linked list and reads user input for its data.

### `display(NODE *head)`
- Traverses the list and prints the data of each node.

### `concatenate(NODE *s1, NODE *s2)`
- Concatenates the second list to the first.

### `sort_list(NODE *head)`
- Sorts the elements of the list in ascending order.

### `reverse(NODE *head)`
- Reverses the pointers in the list and returns the new head.

---

## Limitations

1. **Fixed Data Type**:
   - The program only supports integer data in the nodes.

2. **No Error Handling for Empty Lists**:
   - Assumes lists are non-empty when performing operations like sorting and reversal.

3. **Inefficient Sorting**:
   - Uses bubble sort, which is less efficient for large lists.

---

