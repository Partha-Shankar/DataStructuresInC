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
        return '\0'; // Sentinel value
    } else {
        return stack[tos--];
    }
}

// Get precedence of operators
int precedence(char s) {
    switch (s) {
        case '^': return 4;
        case '*': case '/': case '%': return 3;
        case '+': case '-': return 2;
        case '(' : return 1;
        default: return 0;
    }
}

// Function to convert infix to postfix
void convertToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    push('#'); // Start with a sentinel
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (isalnum(symbol)) { // Operand
            postfix[j++] = symbol;
        } else if (symbol == '(') { // Left parenthesis
            push(symbol);
        } else if (symbol == ')') { // Right parenthesis
            while (stack[tos] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '('
        } else { // Operator
            while (precedence(symbol) <= precedence(stack[tos])) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while (stack[tos] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[20], postfix[20];

    printf("\nEnter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character if present

    convertToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}
