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

// Evaluate a postfix expression
int evaluatePostfix(const char* expression) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } 
        // If the character is an operator, pop two operands and apply the operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (stack.top < 1) {
                printf("Error: Not enough operands for operator '%c'.\n", ch);
                exit(EXIT_FAILURE);
            }
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Unsupported operator '%c'.\n", ch);
                    exit(EXIT_FAILURE);
            }
            // Push the result back onto the stack
            push(&stack, result);
        } else {
            printf("Error: Invalid character '%c' in expression.\n", ch);
            exit(EXIT_FAILURE);
        }
    }

    // The final result should be the only item left in the stack
    if (stack.top != 0) {
        printf("Error: Malformed expression. Too many operands.\n");
        exit(EXIT_FAILURE);
    }

    return pop(&stack);
}

int main() {
    const char* expression = "656+5*2*";
    printf("Result of postfix expression '%s' is: %d\n", expression, evaluatePostfix(expression));
    return 0;
}
