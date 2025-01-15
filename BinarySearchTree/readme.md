# Binary Search Tree (BST)

## Overview

This program implements a Binary Search Tree (BST) with functionalities to insert, traverse, search, and delete nodes. The program provides interactive options to perform operations on the BST and demonstrates its efficiency in organizing and accessing data.

---

## Features

1. **Dynamic Tree Construction**:
   - Allows the insertion of multiple elements to build a BST dynamically.

2. **Traversal Methods**:
   - Supports three types of tree traversal:
     - **Inorder** (Left → Root → Right)
     - **Preorder** (Root → Left → Right)
     - **Postorder** (Left → Right → Root)

3. **Search Functionality**:
   - Searches for a specific key in the BST and returns whether the key exists.

4. **Deletion of Nodes**:
   - Deletes a specified key and adjusts the tree structure:
     - Handles nodes with zero, one, or two children.

5. **Interactive Menu**:
   - User-friendly interface for performing operations in sequence.

---

## How It Works

1. **Insertion**:
   - Adds nodes to the BST, maintaining the order:
     - Values less than the root go to the left subtree.
     - Values greater than the root go to the right subtree.

2. **Traversal**:
   - Performs tree traversal and displays nodes in the specified order.

3. **Search**:
   - Iteratively searches for a given key in the BST.

4. **Deletion**:
   - Deletes a node with:
     - No children (leaf node).
     - One child (replaces the node with its child).
     - Two children (replaces the node with its inorder successor).

---

## Example

### Sample Input:
```plaintext
Enter:
1: Insert  2: Traverse  3: Search  4: Delete  5: Exit
```

### Example Session:
```bash
Enter: 1
Enter the number of elements: 5
Enter value: 50
Enter value: 30
Enter value: 70
Enter value: 20
Enter value: 40

Enter: 2
Inorder traversal:
20    30    40    50    70
Preorder traversal:
50    30    20    40    70
Postorder traversal:
20    40    30    70    50

Enter: 3
Enter the key to search: 40
Key found.

Enter: 4
Enter the key to delete: 30
```

### Sample Output:
```plaintext
Inorder traversal after deletion:
20    40    50    70
```

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `binary_search_tree.c`.
2. Navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc binary_search_tree.c -o binary_search_tree
   ```
4. Run the program:
   ```bash
   ./binary_search_tree
   ```

---

## Limitations

1. **Static Integer Data**:
   - Handles integer data only. Modifications are needed for other data types.
   
2. **Manual Input**:
   - Relies on user input for operations. Automated testing requires additional scripts.

3. **Not Thread-Safe**:
   - Designed for single-threaded execution.

---

## Directory Structure

```
DataStructuresInC/
│
├── README.md
├── RollNumberManagement/
│   ├── roll_number_management.c
│   ├── README.md
├── BinarySearchTree/
│   ├── binary_search_tree.c
│   ├── README.md
```

---
