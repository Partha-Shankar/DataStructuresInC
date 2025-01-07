#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isalnum()

#define MAX 20

char stack[MAX];
int tos = -1;

// Push an element onto the stack
void push(char s) {
    if (tos == MAX - 1) {
        printf("Stack overflow! Cannot push '%c'.\n", s);
    } else {
        stack[++tos] = s;
    }
}

// Pop an element from the stack
char pop() {
    if (tos == -1) {
        printf("Stack underflow! Stack is empty.\n");
        return '\0'; 
    } else {
        return stack[tos--];
    }
}

int main() {
    return 0;
}
