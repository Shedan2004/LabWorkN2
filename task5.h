#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* HEAD;
    QueueNode* TAIL;
} Queue;


TreeNode* createNode(int data);
void addNode(TreeNode* root, int data);
void enqueue(Queue* q, TreeNode* data);
TreeNode* dequeue(Queue* q);
void printNodesBetweenLevels(TreeNode* root, int level1, int level2);
int isEmpty(Queue* q);
int getSize(Queue* q);