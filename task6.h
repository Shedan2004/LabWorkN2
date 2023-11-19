#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100 

typedef struct HNode {
    char* key;
    char* value;
    bool check;
} HNode;


typedef struct HashTable {
    HNode hashTable[SIZE];
    int amount;
} HashTable;

HashTable* createHashTable();
int hash(const char* key);
void insertElem(HashTable* table, const char* key, int value);
int deleteElem(HashTable* table, const char* key);
void search(HashTable* table, const char* key);