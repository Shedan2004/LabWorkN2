#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

void push(Stack* stack, char value) {
    SNode* newSNode = (SNode*)malloc(sizeof(SNode));
    newSNode->value = value;
    newSNode->next = stack->head;
    stack->head = newSNode;
}

char pop(Stack* stack) {
    if (stack->head == NULL) {
        return '\0';
    }
    SNode* temp = stack->head;
    char value = temp->value;
    stack->head = temp->next;
    free(temp);
    return value;
}

int is_empty(Stack* stack) {
    return (stack->head == NULL);
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    stack.head = NULL;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= 'A' && infix[i] <= 'Z') {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&stack, '(');
        }
        else if (infix[i] == ')') {
            while (!is_empty(&stack) && stack.head->value != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!is_empty(&stack) && stack.head->value == '(') {
                pop(&stack);
            }
        }
        else {
            while (!is_empty(&stack) && precedence(stack.head->value) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}