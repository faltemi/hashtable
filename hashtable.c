#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define TABLE_SIZE 34

typedef struct ExampleObj{
    char* name;
    int val;
}ExampleObj;

ExampleObj* hash_table[TABLE_SIZE];

unsigned int hash(const char* name){
    int len = strlen(name);
    unsigned int hashVal = 0;
    for(int i = 0; i < len; i++){
        hashVal += name[i];
        hashVal *= name[i];
        hashVal %= TABLE_SIZE;
    }
    return hashVal;
}

void init_hash_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

void print_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i]){
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
        else{
           printf("\t%i\t---\n", i); 
        }
    }
}

bool hash_table_insert(ExampleObj* v){
    if(!v) return false;
    int idx = hash(v->name);
    if(hash_table[idx] != NULL){
        printf("Collision!\n");
        return false;
    }
    hash_table[idx] = v;
    return true;
}

ExampleObj* lookup_hash(const char* name){
    int idx = hash(name);
    if(hash_table[idx] && strcmp(hash_table[idx]->name, name) == 0) return hash_table[idx];
    return NULL;
}

ExampleObj* delete_hash(const char* name){
    int idx = hash(name);
    if(hash_table[idx] && strcmp(hash_table[idx]->name, name) == 0){
        ExampleObj* tmp = hash_table[idx];
        hash_table[idx] = NULL;
        return tmp;
    }
    return NULL;
}

int main(){
    init_hash_table();
    ExampleObj bob = {.name = "Bob", .val = 13};
    ExampleObj jon = {.name = "Jon", .val = 23};
    ExampleObj tracy = {.name = "Tracy", .val = 43};
    ExampleObj kate = {.name = "Kate", .val = 32};
    hash_table_insert(&bob);
    hash_table_insert(&jon);
    hash_table_insert(&tracy);
    hash_table_insert(&kate);
    print_table();
    ExampleObj* tmp = lookup_hash("Bob");
    printf("Found %s\n", tmp->name);
    
    return 0;
}