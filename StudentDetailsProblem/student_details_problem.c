#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insertRollNo(int **array, int *size, int rollNo, int pos);
void deleteRollNo(int **array, int *size, int pos);
void displayArray(int *array, int size);

int main() {
    int *rollNumbers = NULL; 
    int size = 0;            
    int choice, rollNo, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Roll Number\n");
        printf("2. Delete Roll Number\n");
        printf("3. Display Roll Numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number to insert: ");
                scanf("%d", &rollNo);
                printf("Enter position to insert (1 to %d): ", size + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > size + 1) {
                    printf("Invalid position!\n");
                } else {
                    insertRollNo(&rollNumbers, &size, rollNo, pos);
                    printf("Roll number inserted successfully.\n");
                }
                break;

            case 2:
                printf("Enter position to delete (1 to %d): ", size);
                scanf("%d", &pos);

                if (pos < 1 || pos > size) {
                    printf("Invalid position!\n");
                } else {
                    deleteRollNo(&rollNumbers, &size, pos);
                    printf("Roll number deleted successfully.\n");
                }
                break;

            case 3:
                displayArray(rollNumbers, size);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free(rollNumbers); // Free allocated memory
    return 0;
}

// Function to insert a roll number at a specific position
void insertRollNo(int **array, int *size, int rollNo, int pos) {
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int)); // Resize array

    for (int i = *size; i >= pos; i--) {
        (*array)[i] = (*array)[i - 1]; // Shift elements to the right
    }

    (*array)[pos - 1] = rollNo; // Insert new roll number
    (*size)++;
}

// Function to delete a roll number from a specific position
void deleteRollNo(int **array, int *size, int pos) {
    for (int i = pos - 1; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1]; // Shift elements to the left
    }

    *array = (int *)realloc(*array, (*size - 1) * sizeof(int)); // Resize array
    (*size)--;
}

// Function to display the roll numbers in the array
void displayArray(int *array, int size) {
    if (size == 0) {
        printf("No roll numbers to display.\n");
        return;
    }

    printf("Roll Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
