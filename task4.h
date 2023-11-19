#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QNode {
    Node* data;
    struct QNode* next;
} QNode;

typedef struct TQueue {
    QNode* HEAD;
    QNode* TAIL;
} TQueue;

Node* createTreeNode(int data); 
Node* AddTreeNode(Node* root, int data);
void printSnakeTree(struct Node* root);