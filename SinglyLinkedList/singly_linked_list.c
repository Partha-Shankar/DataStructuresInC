#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SLL {
    char usn[11];
    char name[30];
    float avg_marks;
    struct SLL *link;
};

typedef struct SLL node;
node *start = NULL;

node *getnode() {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("\nError: Memory allocation failed.\n");
        return NULL;
    }
    printf("\nEnter USN, Name, Average Marks:\n");
    scanf("%s %s %f", newnode->usn, newnode->name, &newnode->avg_marks);
    newnode->link = NULL;
    return newnode;
}

void insert_front() {
    node *n1 = getnode();
    if (n1 == NULL)
        return;
    n1->link = start;
    start = n1;  
}

void insert_end() {
    node *n1 = getnode();
    if (n1 == NULL)
        return;
    if (start == NULL) {
        start = n1;
        return;
    }
    node *temp = start;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = n1;
}

void delete_front() {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    node *temp = start;
    printf("\nDeleted Student Data: USN: %s, Name: %s, Avg Marks: %.2f\n",
           temp->usn, temp->name, temp->avg_marks);
    start = temp->link;
    free(temp);
}

void delete_end() {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    if (start->link == NULL) {
        printf("\nDeleted Student Data: USN: %s, Name: %s, Avg Marks: %.2f\n",
               start->usn, start->name, start->avg_marks);
        free(start);
        start = NULL;
        return;
    }
    node *temp = start, *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    printf("\nDeleted Student Data: USN: %s, Name: %s, Avg Marks: %.2f\n",
           temp->usn, temp->name, temp->avg_marks);
    free(temp);
}

void display() {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    int count = 0;
    node *temp = start;
    printf("\nStudent Data in List:\n");
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Avg Marks: %.2f\n", temp->usn, temp->name, temp->avg_marks);
        temp = temp->link;
        count++;
    }
    printf("\nTotal Students: %d\n", count);
}

int main() {
    int choice, n, i;
    while (1) {
        printf("\nMenu:\n");
        printf("1: Create N Students\n");
        printf("2: Insert at Front\n");
        printf("3: Insert at End\n");
        printf("4: Delete at Front\n");
        printf("5: Delete at End\n");
        printf("6: Display List\n");
        printf("9: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the number of students to create: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                insert_end();
            }
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            display();
            break;
        case 9:
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
