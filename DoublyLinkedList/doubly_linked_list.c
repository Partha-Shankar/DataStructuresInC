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
