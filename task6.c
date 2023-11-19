#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "task6.h"

HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->amount = NULL;

    for (int i = 0; i < SIZE; i++) {
        table->hashTable[i].check = false;
    }

    return table;
}

int hash(const char* key) {
    int hash = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        hash = hash + key[i];
    }

    return abs(hash) % SIZE;
}

void insertElem(HashTable* table, const char* key, int value)
{
    if (table->amount == SIZE)
    {
        printf("Хеш-таблица переполнена\n");
        return;
    }

    int index = hash(key);

    while (table->hashTable[index].check) {
        index = (index + 1) % SIZE; // Линейное пробирование для обработки коллизий
    }

    table->hashTable[index].key = key;
    table->hashTable[index].value = value;
    table->hashTable[index].check = true;
    table->amount++;
    printf("Element %d was addded\n", table->hashTable[index].value);
}

int deleteElem(HashTable* table, const char* key)
{
    int index = hash(key);

    while (!table->hashTable[index].check) {
        index = (index + 1) % SIZE; // Линейное пробирование для обработки коллизий
    }

    printf("Element %d was deleted\n", table->hashTable[index].value);
    table->hashTable[index].key = NULL;
    table->hashTable[index].value = NULL;
    table->hashTable[index].check = false;
    table->amount--;
}

void search(HashTable* table, const char* key) {
    int index = hash(key);

    while (table->hashTable[index].check) {
        if (strcmp(table->hashTable[index].key, key) == 0) {
            printf("Your searched element: %d\n", table->hashTable[index].value);
            return;
        }

        index = (index + 1) % SIZE; // Продолжаем поиск с помощью метода открытой адресации
    }

    printf("Element wasn't find\n");
}

void showHash(HashTable* table)
{
    printf("All elements of your hash table: ");
    for (int i = 0; i < SIZE; i++)
    {
        if (table->hashTable[i].check)
        {
            printf("%d ", table->hashTable[i].value);
        }
    }
    printf("\n");
}