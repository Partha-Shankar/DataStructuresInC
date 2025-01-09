#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Define a stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow! Cannot push %d.\n", value);
        exit(EXIT_FAILURE); // Exit on stack overflow
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow! No elements to pop.\n");
        exit(EXIT_FAILURE); // Exit on stack underflow
    }
}

int main() {
    printf("Initial stack functions implemented.\n");
    return 0;
}
