#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "task3.h"

Array* createArray() {
	Array* array = (Array*)malloc(sizeof(Array));
	if (array == NULL) {
		printf("Memory allocation error\n");
		return array;
	}
	for (int i = 0; i < SIZE; i++) {
		array->hashTable[i].value = NULL;
		array->hashTable[i].check = false;
	}
	array->amount = 0;

	return array;
}

int hashArr(int value) {
	int hashValue = 0;
	for (int i = 0; i < SIZE; i++) {
		hashValue += i;
	}
	return hashValue % SIZE;
}

void addArray(Array* Array, int value) {
	int index = hashArr(value);

	while (Array->hashTable[index].check) {
		if (Array->hashTable[index].value == value) {
			printf("The element is in a container\n");
			return;
		}
		index = (index + 1) % SIZE;
	}

	Array->hashTable[index].value = value;
	Array->hashTable[index].check = true;

	printf("%d was added\n", value);

	Array->amount++;
}

int delArray(Array* Array, int value) {
	int index = hashArr(value);

	while (Array->hashTable[index].check) {
		if (Array->hashTable[index].value == value) {
			Array->hashTable[index].value = NULL;
			Array->hashTable[index].check = false;
			return 1;
		}
		index = (index + 1) % SIZE;
	}

	Array->amount--;

	return 0;
}

void readArray(const Array* Array, int value) {
	int index = hashArr(value);

	while (Array->hashTable[index].check) {
		if (Array->hashTable[index].value == value) {
			printf("Element %d is in structure\n", value);
			return;
		}
		index = (index + 1) % SIZE;
	}

	printf("Element %d is not in structure\n", value);
}

void printArray(const Array* Array) 
{
	printf("Your Array: { ");
	for (int i = 0; i < SIZE; i++) {
		if (Array->hashTable[i].check) {
			printf("%d ", Array->hashTable[i].value);
		}
	}
	printf("}\n");
}

Array* ArrayToArray(Array* Array1, int n)
{
	int amount2 = 0;
	Array* Array2 = (Array*)malloc(sizeof(ArrayNode) * Array1->amount);
	for (int i = 0; i < n; i++)
	{
		if (!Array1->hashTable[i].check) continue;
		Array2->hashTable[amount2].value = Array1->hashTable[i].value;
		amount2++;
		if (amount2 == Array1->amount)
		{
			break;
		}
	}

	Array2->amount = amount2;

	return Array2;
}

void SubArrays(Array* Array, int n)
{
	printf("Your list of subarrays:\n");
	for (int i = 0; i < (1 << n); i++)
	{
		printf("{");
		int temp = i;
		for (int j = 0; j < n; j++)
		{
			if (temp % 2 == 1)
			{
				printf(" %d ", Array->hashTable[j].value);
			}
			temp /= 2;
		}
		printf("}\n");
	}
}