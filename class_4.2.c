#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 100

// Structure for Stack
struct Stack {
    int* array;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        // double the capacity of the array
        int new_capacity = stack->capacity * 2;
        stack->array = (int*)realloc(stack->array, new_capacity * sizeof(int));
        stack->capacity = new_capacity;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) return -1;
    return stack->array[stack->top--];
}

// Function to evaluate prefix expression
int evaluatePrefix(char* prefix) {
    struct Stack* stack = createStack(INITIAL_CAPACITY);
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else {
            int a = pop(stack);
            int b = pop(stack);
            switch (prefix[i]) {
                case '+':
                    push(stack, a + b);
                    break;
                case '-':
                    push(stack, a - b);
                    break;
                case '*':
                    push(stack, a * b);
                    break;
                case '/':
                    push(stack, a / b);
                    break;
            }
        }
    }
    int result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(INITIAL_CAPACITY);
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            int a = pop(stack);
            int b = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, b + a);
                    break;
                case '-':
                    push(stack, b - a);
                    break;
                case '*':
                    push(stack, b * a);
                    break;
                case '/':
                    push(stack, b / a);
                    break;
            }
        }
    }
    int result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char prefix[INITIAL_CAPACITY];
    char postfix[INITIAL_CAPACITY];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    printf("Result of prefix expression: %d\n", evaluatePrefix(prefix));

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    printf("Result of postfix expression: %d\n", evaluatePostfix(postfix));

    return 0;
}
