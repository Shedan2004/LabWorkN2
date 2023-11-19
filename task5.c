#include <stdio.h>
#include <stdlib.h>
#include "task5.h"

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(TreeNode* root, int data) {
    if (data < root->data) {
        if (root->left != NULL) {
            addNode(root->left, data);
        }
        else {
            root->left = createNode(data);
        }
    }
    else {
        if (root->right != NULL) {
            addNode(root->right, data);
        }
        else {
            root->right = createNode(data);
        }
    }
}

void enqueue(Queue* q, TreeNode* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->TAIL == NULL) {
        q->HEAD = newNode;
        q->TAIL = newNode;
    }
    else {
        q->TAIL->next = newNode;
        q->TAIL = newNode;
    }
}

TreeNode* dequeue(Queue* q) {
    if (q->HEAD == NULL) {
        return NULL;
    }
    QueueNode* temp = q->HEAD;
    TreeNode* data = temp->data;
    q->HEAD = q->HEAD->next;
    if (q->HEAD == NULL) {
        q->TAIL = NULL;
    }
    free(temp);
    return data;
}

void printNodesBetweenLevels(TreeNode* root, int level1, int level2) {
    printf("Values between levels %d and %d: { ", level1, level2);
    if (root == NULL) {
        return;
    }

    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->HEAD = NULL;
    q->TAIL = NULL;

    int level = 1;
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = getSize(q);
        while (size > 0) {
            TreeNode* current = dequeue(q);
            if (level >= level1 && level <= level2) {
                printf("%d ", current->data);
            }
            if (current->left != NULL) {
                enqueue(q, current->left);
            }
            if (current->right != NULL) {
                enqueue(q, current->right);
            }
            size--;
        }
        level++;
    }
    printf("}");
}

int isEmpty(Queue* q) {
    return q->HEAD == NULL;
}

int getSize(Queue* q) {
    int count = 0;
    QueueNode* current = q->HEAD;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
