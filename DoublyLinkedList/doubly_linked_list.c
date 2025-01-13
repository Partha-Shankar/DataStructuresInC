#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee
struct Employee {
    char SSN[10];
    char name[50];
    char dept[20];
    struct Employee* prev;
    struct Employee* next;
};

// Head and tail pointers
struct Employee* head = NULL;
struct Employee* tail = NULL;

// Function to create a new employee node
struct Employee* createEmployee(char* SSN, char* name, char* dept) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newEmployee->SSN, SSN);
    strcpy(newEmployee->name, name);
    strcpy(newEmployee->dept, dept);
    newEmployee->prev = NULL;
    newEmployee->next = NULL;
    return newEmployee;
}

// a. Create a Node of N Employees Data by inserting in front
void insertInFront(char* SSN, char* name, char* dept) {
    struct Employee* newEmployee = createEmployee(SSN, name, dept);
    if (head == NULL) {
        head = newEmployee;
        tail = newEmployee;
    } else {
        newEmployee->next = head;
        head->prev = newEmployee;
        head = newEmployee;
    }
}

// b. Insert a new node to the right of key value
void insertAfter(char* keySSN, char* SSN, char* name, char* dept) {
    struct Employee* current = head;
    while (current != NULL && strcmp(current->SSN, keySSN) != 0) {
        current = current->next;
    }
    if (current != NULL) {
        struct Employee* newEmployee = createEmployee(SSN, name, dept);
        newEmployee->next = current->next;
        newEmployee->prev = current;
        if (current->next != NULL) {
            current->next->prev = newEmployee;
        } else {
            tail = newEmployee;
        }
        current->next = newEmployee;
        printf("Insertion successful after SSN: %s\n", keySSN);
    } else {
        printf("Key SSN not found!\n");
    }
}

// c. Perform Insertion and Deletion at End of DLL
void insertAtEnd(char* SSN, char* name, char* dept) {
    struct Employee* newEmployee = createEmployee(SSN, name, dept);
    if (tail == NULL) {
        head = newEmployee;
        tail = newEmployee;
    } else {
        tail->next = newEmployee;
        newEmployee->prev = tail;
        tail = newEmployee;
    }
}

void deleteAtEnd() {
    if (tail == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    struct Employee* temp = tail;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted employee with SSN: %s\n", temp->SSN);
    free(temp);
}

// d. Display the status of DLL and count the number of nodes
void displayList() {
    struct Employee* current = head;
    int count = 0;
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    printf("DLL Status:\n");
    while (current != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s\n", current->SSN, current->name, current->dept);
        count++;
        current = current->next;
    }
    printf("Number of nodes: %d\n", count);
}

// e. Exit
void exitProgram() {
    struct Employee* current = head;
    while (current != NULL) {
        struct Employee* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    tail = NULL;
    printf("Exiting and cleaning up memory.\n");
}

int main() {
    int choice;
    char SSN[10], name[50], dept[20], keySSN[10];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert after key SSN\n");
        printf("3. Insert at end\n");
        printf("4. Delete at end\n");
        printf("5. Display DLL\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter SSN, Name, Dept: ");
                scanf("%9s %49s %19s", SSN, name, dept);
                insertInFront(SSN, name, dept);
                break;
            case 2:
                printf("Enter key SSN: ");
                scanf("%9s", keySSN);
                printf("Enter SSN, Name, Dept of new employee: ");
                scanf("%9s %49s %19s", SSN, name, dept);
                insertAfter(keySSN, SSN, name, dept);
                break;
            case 3:
                printf("Enter SSN, Name, Dept: ");
                scanf("%9s %49s %19s", SSN, name, dept);
                insertAtEnd(SSN, name, dept);
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                displayList();
                break;
            case 6:
                exitProgram();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
