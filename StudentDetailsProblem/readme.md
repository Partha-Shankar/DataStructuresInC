# Student Details Management System

## Overview

This program provides a dynamic array implementation for managing student roll numbers. It allows the user to insert, delete, and display roll numbers interactively. The program uses dynamic memory allocation to ensure efficient use of resources and provides a flexible solution for managing roll numbers.

---

## Features

1. **Dynamic Array Management**:
   - Utilizes dynamic memory allocation (`malloc`, `realloc`) for resizing the array as needed.

2. **Insertion**:
   - Inserts a roll number at a specific position, shifting other elements as required.

3. **Deletion**:
   - Deletes a roll number from a specific position, maintaining the order of remaining elements.

4. **Display**:
   - Outputs the list of roll numbers currently stored in the system.

5. **Interactive Menu**:
   - Provides a menu-based interface for user-friendly operation.

---

## How It Works

1. **Insertion**:
   - The user provides the roll number and the position where it should be inserted.
   - The program shifts elements to the right to accommodate the new roll number.

2. **Deletion**:
   - The user specifies the position of the roll number to be deleted.
   - The program shifts elements to the left and resizes the array.

3. **Display**:
   - Displays all roll numbers currently stored in the array.

4. **Dynamic Memory Management**:
   - Automatically resizes the array during insertion and deletion, ensuring memory efficiency.

---

## Example

### Sample Input:
```plaintext
Menu:
1. Insert Roll Number
2. Delete Roll Number
3. Display Roll Numbers
4. Exit
```

### Example Session:
```bash
Enter your choice: 1
Enter Roll Number to insert: 101
Enter position to insert (1 to 1): 1
Roll number inserted successfully.

Enter your choice: 1
Enter Roll Number to insert: 102
Enter position to insert (1 to 2): 2
Roll number inserted successfully.

Enter your choice: 3
Roll Numbers: 101 102

Enter your choice: 2
Enter position to delete (1 to 2): 1
Roll number deleted successfully.

Enter your choice: 3
Roll Numbers: 102
```

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `student_details_problem.c`.
2. Navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc student_details_problem.c -o student_details_problem
   ```
4. Run the program:
   ```bash
   ./student_details_problem
   ```

---

## Directory Structure

```
DataStructuresInC/
│
├── README.md
├── RollNumberManagement/
│   ├── roll_number_management.c
│   ├── README.md
├── StudentDetailsProblem/
│   ├── student_details_problem.c
│   ├── README.md
```

---

## Limitations

1. **Integer Roll Numbers**:
   - Only supports integer roll numbers. Modifications are needed for other data types.

2. **Manual Input**:
   - Relies on user input for operations. Automated testing would require additional scripting.

3. **Memory Management**:
   - Proper care must be taken to free allocated memory after program execution.

---
