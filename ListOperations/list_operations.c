#include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
struct SLL {
    int data;
    struct SLL *next;
};

typedef struct SLL NODE;

// Function to create a new node
NODE *getnode() {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &p->data);
    p->next = NULL;
    return p;
}

// Function to display the list
void display(NODE *head) {
    NODE *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE *s1 = NULL, *n1;
    int n, i;

    // Input for List 1
    printf("Number of elements in List 1: ");
    scanf("%d", &n);
    printf("Enter %d elements for List 1:\n", n);
    for (i = 0; i < n; i++) {
        n1 = getnode();
        n1->next = s1;
        s1 = n1;
    }

    // Display the list
    printf("List 1 elements:\n");
    display(s1);

    return 0;
}
