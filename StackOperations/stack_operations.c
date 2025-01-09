#include <stdio.h>
#include <stdlib.h>
#define max 4

int a[max], tos = -1;

// Function to push an element onto the stack
void push(int m) {
    if (tos == max - 1) {
        printf("\nStack Overflow! Cannot push %d.\n", m);
    } else {
        a[++tos] = m;
        printf("\nElement %d pushed onto stack.\n", m);
    }
}

// Function to pop an element from the stack
int pop() {
    if (tos == -1) {
        printf("\nStack Underflow! No element to pop.\n");
        return -1; // Return a sentinel value
    } else {
        return a[tos--];
    }
}

// Function to display the elements of the stack
void display() {
    if (tos == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements (top to bottom):\n");
        for (int i = tos; i >= 0; i--) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}

// Function to check if a number is a palindrome using the stack
void palin() {
    int n, temp, rem, flag = 1;

    printf("\nEnter a number to check for palindrome: ");
    scanf("%d", &n);

    // Copy of the original number
    temp = n;

    // Push each digit onto the stack
    while (temp != 0) {
        rem = temp % 10;
        push(rem);
        temp /= 10;
    }

    // Check if the number is a palindrome
    temp = n; // Reset temp to the original number
    while (temp != 0) {
        rem = temp % 10;
        if (pop() != rem) {
            flag = 0;
            break;
        }
        temp /= 10;
    }

    if (flag) {
        printf("\n%d is a palindrome.\n", n);
    } else {
        printf("\n%d is not a palindrome.\n", n);
    }
}

// Main function with menu
int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:");
        printf("\n1. Push an element onto the stack");
        printf("\n2. Pop an element from the stack");
        printf("\n3. Display stack elements");
        printf("\n4. Check if a number is a palindrome");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter an element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    printf("\nPopped element: %d\n", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                palin();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}
