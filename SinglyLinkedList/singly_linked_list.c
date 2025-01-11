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

int main() {
    int choice, n, i;
    while (1) {
        printf("\nMenu:\n");
        printf("1: Create N Students\n");
        printf("2: Insert at Front\n");
        printf("3: Insert at End\n");
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
        case 9:
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
