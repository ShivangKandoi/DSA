#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for storing operators and operands
struct Stack {
    int top;
    char* array[MAX];
};

// Function to create a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to push an element to the stack
void push(struct Stack* stack, char* item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char* pop(struct Stack* stack) {
    if (stack->top == -1) return NULL;
    return stack->array[stack->top--];
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    struct Stack* stack = createStack();
    reverse(infix);
    int k = 0;
    
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            prefix[k++] = infix[i];
        } else if (infix[i] == ')') {
            push(stack, ")");
        } else if (infix[i] == '(') {
            while (stack->top != -1 && strcmp(stack->array[stack->top], ")") != 0) {
                prefix[k++] = *(pop(stack));
            }
            pop(stack);
        } else if (isOperator(infix[i])) {
            while (stack->top != -1 && precedence(infix[i]) <= precedence(*(stack->array[stack->top]))) {
                prefix[k++] = *(pop(stack));
            }
            char* op = (char*)malloc(2);
            op[0] = infix[i];
            op[1] = '\0';
            push(stack, op);
        }
    }

    while (stack->top != -1) {
        prefix[k++] = *(pop(stack));
    }

    prefix[k] = '\0';
    reverse(prefix);
    free(stack);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}

