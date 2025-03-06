#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    int array[MAX];
};

void push(struct Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int evaluatePrefix(char* prefix) {
    struct Stack stack;
    stack.top = -1;
    int result = 0;
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(&stack, prefix[i] - '0');
        } else {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            switch (prefix[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            push(&stack, result);
        }
    }
    return result;
}

int evaluatePostfix(char* postfix) {
    struct Stack stack;
    stack.top = -1;
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, op1 + op2);
                    break;
                case '-':
                    push(&stack, op1 - op2);
                    break;
                case '*':
                    push(&stack, op1 * op2);
                    break;
                case '/':
                    push(&stack, op1 / op2);
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char prefix[MAX], postfix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    printf("Result of prefix expression: %d\n", evaluatePrefix(prefix));
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    printf("Result of postfix expression: %d\n", evaluatePostfix(postfix));
    return 0;
}
