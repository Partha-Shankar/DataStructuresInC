
# Student High Scorers Program

## Problem Statement

The program is designed to display the details of students whose average percentage marks are greater than 85%. It uses an array of structures to store and manage student details and passes the array to functions for processing.

---

## Program Requirements

1. **Data Members**:
   - Name
   - Roll Number
   - Percentage Marks

2. **Functionality**:
   - Use an array of structures to read details for at least 5 students.
   - Write functions to:
     - Input student data.
     - Filter students with percentage marks greater than 85%.
     - Display the filtered student details.

3. **Array of Structures**:
   - The program uses an array of structures to store student details and pass them to functions for processing.

---

## How It Works

1. **Input Functionality**:  
   - The program prompts the user to enter details for each student: Name, Roll Number, and Percentage Marks.
   - The user can enter details for up to 5 students. If the number of students exceeds 5 or is invalid, it will be adjusted accordingly.
   - If a student's percentage is invalid (less than 0 or greater than 100), the program will prompt the user to re-enter the student's details.

2. **Filtering**:  
   - The program filters students who have percentage marks greater than 85%.
   - Only those students who meet the condition will have their details displayed.

3. **Display**:  
   - After filtering, the program will display the names, roll numbers, and percentage marks of students whose marks are greater than 85%.

---

## Example

### Sample Input:
```
Enter how many students (max 5)? 4
Enter student details:
Student name    Roll Num    Percentage Marks
Student 1:
Name: Alice
Roll Number: 101
Percentage Marks: 90
Student 2:
Name: Bob
Roll Number: 102
Percentage Marks: 75
Student 3:
Name: Charlie
Roll Number: 103
Percentage Marks: 88
Student 4:
Name: Dave
Roll Number: 104
Percentage Marks: 80
```

### Sample Output:
```
Student Details (Score > 85):
Stud Name        Roll Num   Percentage Marks
-------------------------------------------------
Alice            101        90.00
Charlie          103        88.00
```

---

## Compilation and Execution

### To compile and run the program:

1. Save the code in a file named `student_high_scorers.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program:
   ```bash
   gcc student_high_scorers.c -o student_high_scorers
   ```
4. Run the compiled program:
   ```bash
   ./student_high_scorers
   ```

---

## License

This project is open-source and does not include a specific license.
