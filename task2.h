#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SETSIZE 100

typedef struct node_set {
	const char* value;
	bool check;
} node_set;

typedef struct Set {
	node_set settabl[SETSIZE];
	unsigned int size;
} Set;

Set* createSet();
int SHash(const char* value, int* size);
void pushset(Set* set, const char* value, int* size);
int popset(Set* set, const char* value, int* size);
int readSet(const Set* set, const char* value, int* size);
void printSet(Set* set, int* size);
Set* unionofsets(Set* set1, Set* set2, int* size1, int* size2, int* size3);
Set* intersection(Set* set1, Set* set2, int* size1, int* size2, int* size);
Set* setdifference(Set* set1, Set* set2, int* size1, int* size2, int* size3);