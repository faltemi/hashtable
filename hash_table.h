#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct ExampleObj{
    char* name;
    int val;
    struct ExampleObj* next;
}ExampleObj;

typedef struct HashTable{
    ExampleObj** buf;
    size_t table_size;
    void (*destroy)(ExampleObj *); // Callback to destructor for buffer objects
}HashTable;


HashTable* hash_table_new(size_t table_size, void (*destroy)(ExampleObj *));

unsigned int hash(const char* name, int table_size);

void print_table(HashTable* hash_table);

bool hash_table_insert(HashTable* hash_table, ExampleObj* v);

ExampleObj* lookup_hash(HashTable* hash_table, const char* name);

ExampleObj* delete_hash(HashTable* hash_table, const char* name);

void delete_hash_table(HashTable* hash_table);

#endif // HASH_TABLE_H
