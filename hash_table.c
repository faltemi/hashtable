#include "hash_table.h"

HashTable* hash_table_new(size_t table_size, void (*destroy)(ExampleObj *)){
    HashTable* hash_table = malloc(sizeof(*hash_table));
    if (!hash_table) return NULL;
    hash_table->buf = calloc(table_size, sizeof(*hash_table->buf));
    if(!hash_table->buf){
        free(hash_table);
        return NULL;
    }

    hash_table->table_size = table_size;
    hash_table->destroy = destroy;
    return hash_table;
}

unsigned int hash(const char* name, int table_size){
    size_t len = strlen(name);
    unsigned int hashVal = 0;
    for(size_t i = 0; i < len; i++){
        hashVal += name[i];
        hashVal *= name[i];
    }
    return hashVal % table_size;
}

void print_table(HashTable* hash_table){
    if(!hash_table || !hash_table->buf) return;
    for(size_t i = 0; i < hash_table->table_size; i++){
        if(!hash_table->buf[i]){
            printf("\t%li\t---\n", i); 
        }
        else{
            printf("\t%li\t", i);
            ExampleObj* itr = hash_table->buf[i];
            while(itr){
                printf("%s - ", itr->name);  
                itr = itr->next;             
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(HashTable* hash_table, ExampleObj* v){
    if(!hash_table || !hash_table->buf || !v) return false;
    int idx = hash(v->name, hash_table->table_size);
    v->next = hash_table->buf[idx];
    hash_table->buf[idx] = v;
    return true;
}

ExampleObj* lookup_hash(HashTable* hash_table, const char* name){
    if(!hash_table || !hash_table->buf || !name) return NULL;
    int idx = hash(name, hash_table->table_size);
    ExampleObj* itr = hash_table->buf[idx];
    while(itr && strcmp(itr->name, name) != 0){
        itr = itr->next;
    }
    return itr;
}

ExampleObj* delete_hash(HashTable* hash_table, const char* name){
    if(!hash_table || !hash_table->buf || !name) return NULL;
    int idx = hash(name, hash_table->table_size);
    ExampleObj* prev = NULL;
    ExampleObj* itr = hash_table->buf[idx];

    while(itr && strcmp(itr->name, name) != 0){
        prev = itr;
        itr = itr->next;
    }
    if(!itr) return NULL;

    if(prev) prev->next = itr->next;
    else     hash_table->buf[idx] = itr->next;
    
    return itr;
}

void delete_hash_table(HashTable* hash_table){
    if(!hash_table) return;

    for(size_t i = 0; i < hash_table->table_size; i++){
        ExampleObj* itr = hash_table->buf[i];
        while(itr){
            ExampleObj* next = itr->next;
            // Use custom destructor if provided
            if (hash_table->destroy) hash_table->destroy(next);
            itr = next;
        }
        // Not sure
    }
    free(hash_table->buf);
    free(hash_table);
}
