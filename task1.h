#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SNode
{
    char value;
    struct SNode* next;
} SNode;

typedef struct Stack
{
    SNode* head;
} Stack;


void push(Stack* stack, char value);
char pop(Stack* stack);
int is_empty(Stack* stack);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
