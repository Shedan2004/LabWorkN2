#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"

void tasks()
{
	printf("Chose one of these tasks and write his number:\n");
	printf("1) Task with stack;\n");
	printf("2) Task with set;\n");
	printf("3) Task with array;\n");
	printf("4) Task with binary tree;\n");
	printf("5) Task with queue;\n");
	printf("6) Task with hash-table;\n");
	printf("7) Exit from programm;\n\n");
	printf("Input number of point, which you want to chose: ");
}

void task1()
{
	printf("\n");
	char infix[20], postfix[20];

	printf("Enter an infix expression: ");
	scanf("%s", infix);

	infixToPostfix(infix, postfix);

	printf("Postfix expression: %s\n", postfix);
	printf("\n");
}

void task2()
{
	printf("\n");
	
	Set* Set1 = createSet();
	Set* Set2 = createSet();
	int size1 = 1;
	int size2 = 1;
	pushset(Set1, "l", &size1);
	pushset(Set1, "g", &size1);
	pushset(Set1, "k", &size1);
	printSet(Set1, &size1);
	printf("\n");
	pushset(Set2, "o", &size2);
	pushset(Set2, "p", &size2);
	pushset(Set2, "l", &size2);
	printSet(Set2, &size2);
	printf("\n");
	int size3 = 1;
	Set* unionset = unionofsets(Set1, Set2, &size1, &size2, &size3);
	printSet(unionset, &size3);
	printf("\n");
	int size4 = 1;
	Set* intersectionset = intersection(Set1, Set2, &size1, &size2, &size4);
	printSet(intersectionset, &size4);
	printf("\n");
	int size5 = 1;
	Set* difference = setdifference(Set1, Set2, &size1, &size2, &size5);
	printSet(difference, &size5);
	printf("\n");

	printf("\n");
}

void task3()
{
	printf("\n");
	Array* arr = createArray();
	addArray(arr, 1);
	addArray(arr, 2);
	addArray(arr, 3);
	printArray(arr, SIZE);
	int n = SIZE;
	Array* arr2 = ArrayToArray(arr, n);

	SubArrays(arr2, arr2->amount);
	free(arr2);
	printf("\n");
}

void task4()
{
	printf("\n");

	Node* root = createTreeNode(5);
	AddTreeNode(root, 3);
	AddTreeNode(root, 8);
	AddTreeNode(root, 2);
	AddTreeNode(root, 7);
	AddTreeNode(root, 4);
	AddTreeNode(root, 9);
	AddTreeNode(root, 1);

	printf("Snake tree traversal: ");
	printSnakeTree(root);

	printf("\n");
}

void task5()
{
	printf("\n");

	TreeNode* root = createNode(5);
	addNode(root, 8);
	addNode(root, 3);
	addNode(root, 7);
	addNode(root, 9);
	addNode(root, 4);
	addNode(root, 2);
	addNode(root, 1);

	int level1 = 2;
	int level2 = 3;

	printNodesBetweenLevels(root, level1, level2);

	printf("\n");
}

void task6()
{
	printf("\n");

	HashTable* table = createHashTable();

	insertElem(table, "key1", 10);
	insertElem(table, "key2", 20);
	insertElem(table, "key1", 30);

	showHash(table);

	search(table, "key1");

	deleteElem(table, "key1");

	showHash(table);

	search(table, "key1");

	printf("\n");
}

int main()
{
	int command;
	tasks();
	scanf("%d", &command);
	while (command != 7)
	{
		switch (command)
		{
		case 1:
		{
			task1();
			printf("\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		case 2:
		{
			task2();
			printf("\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		case 3:
		{
			task3();
			printf("\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		case 4:
		{
			task4();
			printf("\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		case 5:
		{
			task5();
			printf("\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		case 6:
		{
			task6();
			printf("\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		case 7:
		{
			exit(0);
			break;
		}
		default:
		{
			printf("You wrote uncorrect value. Try again\n\n");
			tasks();
			scanf("%d", &command);
			break;
		}
		}
	}

	return 0;
}