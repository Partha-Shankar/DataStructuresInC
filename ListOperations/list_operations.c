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

// Function to concatenate two lists
void concatenate(NODE *s1, NODE *s2) {
    NODE *temp = s1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = s2;
}

// Function to sort the list
void sort_list(NODE *head) {
    NODE *current, *temp;
    int t;
    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (current->data > temp->data) {
                t = current->data;
                current->data = temp->data;
                temp->data = t;
            }
        }
    }
}

// Function to reverse the list
NODE *reverse(NODE *head) {
    NODE *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    NODE *s1 = NULL, *s2 = NULL, *n1, *n2;
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

    // Input for List 2
    printf("Number of elements in List 2: ");
    scanf("%d", &n);
    printf("Enter %d elements for List 2:\n", n);
    for (i = 0; i < n; i++) {
        n2 = getnode();
        n2->next = s2;
        s2 = n2;
    }

    // Concatenate and display
    printf("Concatenated list:\n");
    concatenate(s1, s2);
    display(s1);

    // Sort and display
    printf("Sorted list:\n");
    sort_list(s1);
    display(s1);

    // Reverse and display
    printf("Reversed list:\n");
    s1 = reverse(s1);
    display(s1);

    return 0;
}
