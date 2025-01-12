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
