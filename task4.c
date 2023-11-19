#include <stdio.h>
#include <stdlib.h>
#include "task4.h"

Node* createTreeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* AddTreeNode(Node* Tree, int data)
{
    if (Tree == NULL) //если значения нет в корне, то добавляем
        return createTreeNode(data);
    if (data <= Tree->data)
        Tree->left = AddTreeNode(Tree->left, data);
    else
        Tree->right = AddTreeNode(Tree->right, data);
    return Tree;
}

void printSnakeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    Node** queue = (Node**)malloc(sizeof(Node*) * 100);
    int front = 0, rear = 0;
    int level = 1;
    queue[rear++] = root;

    while (front < rear) {
        if (level % 2 != 0) {
            for (int i = front; i < rear; i++) {
                printf("%d ", queue[i]->data);
            }
        }
        else {
            for (int i = rear - 1; i >= front; i--) {
                printf("%d ", queue[i]->data);
            }
        }

        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Node* current = queue[front++];
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }

        level++;
    }

    free(queue);
}