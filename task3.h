#pragma once
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define SIZE 10 

typedef struct ArrayNode {
	int value;
	bool check;
} ArrayNode;

typedef struct Array {
	ArrayNode hashTable[SIZE];
	int amount;
} Array;

Array* createArray();
int hashArr(int value);
void addArray(Array* Array, int value);
int delArray(Array* Array, int value);
void readArray(const Array* Array, int value);
void printArray(const Array* Array);
Array* ArrayToArray(Array* arr1, int n);
void SubArrays(Array* arr, int n);