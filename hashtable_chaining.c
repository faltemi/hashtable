#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define TABLE_SIZE 34

typedef struct ExampleObj{
    char* name;
    int val;
    struct ExampleObj* next;
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
        if(!hash_table[i]){
            printf("\t%i\t---\n", i); 
        }
        else{
            printf("\t%i\t", i);
            ExampleObj* itr = hash_table[i];
            while(itr){
                printf("%s - ", itr->name);  
                itr = itr->next;             
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(ExampleObj* v){
    if(!v) return false;
    int idx = hash(v->name);
    v->next = hash_table[idx];
    hash_table[idx] = v;
    return true;
}

ExampleObj* lookup_hash(const char* name){
    int idx = hash(name);
    ExampleObj* itr = hash_table[idx];
    while(itr && strcmp(itr->name, name) != 0){
        itr = itr->next;
    }
    return itr;
}

ExampleObj* delete_hash(const char* name){
    int idx = hash(name);
    ExampleObj* prev = NULL;
    ExampleObj* itr = hash_table[idx];

    while(itr && strcmp(itr->name, name) != 0){
        prev = itr;
        itr = itr->next;
    }
    if(!itr) return NULL;

    if(prev) prev->next = itr->next;
    else     hash_table[idx] = itr->next;
    
    return itr;
}

int main(){
    init_hash_table();

    /* --- create all ExampleObj instances --- */
    ExampleObj plus       = {.name = "+",         .val = 13, .next = NULL};
    ExampleObj minus      = {.name = "-",         .val = 23, .next = NULL};
    ExampleObj div        = {.name = "/",         .val = 43, .next = NULL};
    ExampleObj mult       = {.name = "*",         .val = 32, .next = NULL};
    ExampleObj mod        = {.name = "%",         .val = 13, .next = NULL};
    ExampleObj eq         = {.name = "=",         .val = 23, .next = NULL};
    ExampleObj neq        = {.name = "!=",        .val = 43, .next = NULL};
    ExampleObj lt         = {.name = "<",         .val = 32, .next = NULL};
    ExampleObj lte        = {.name = "<=",        .val = 13, .next = NULL};
    ExampleObj gt         = {.name = ">",         .val = 23, .next = NULL};
    ExampleObj gte        = {.name = ">=",        .val = 43, .next = NULL};
    ExampleObj excl       = {.name = "!",         .val = 32, .next = NULL};
    ExampleObj write      = {.name = ":=",        .val = 1 , .next = NULL};
    ExampleObj and        = {.name = "and",       .val = 13, .next = NULL};
    ExampleObj cell       = {.name = "cell",      .val = 23, .next = NULL};
    ExampleObj chr        = {.name = "chr",       .val = 43, .next = NULL};
    ExampleObj cons       = {.name = "cons",      .val = 32, .next = NULL};
    ExampleObj def        = {.name = "def",       .val = 13, .next = NULL};
    ExampleObj doVal      = {.name = "do",        .val = 23, .next = NULL};
    ExampleObj error      = {.name = "error",     .val = 43, .next = NULL};
    ExampleObj fn         = {.name = "fn",        .val = 32, .next = NULL};
    ExampleObj get_file   = {.name = "get-file",  .val = 13, .next = NULL};
    ExampleObj head       = {.name = "head",      .val = 23, .next = NULL};
    ExampleObj ifVal      = {.name = "if",        .val = 43, .next = NULL};
    ExampleObj input      = {.name = "input",     .val = 32, .next = NULL};
    ExampleObj let        = {.name = "let",       .val = 13, .next = NULL};
    ExampleObj list       = {.name = "list",      .val = 23, .next = NULL};
    ExampleObj load       = {.name = "load",      .val = 43, .next = NULL};
    ExampleObj loop       = {.name = "loop",      .val = 32, .next = NULL};
    ExampleObj macro      = {.name = "macro",     .val = 13, .next = NULL};
    ExampleObj not        = {.name = "not",       .val = 23, .next = NULL};
    ExampleObj new_symbol = {.name = "new-symbol",.val = 43, .next = NULL};
    ExampleObj or         = {.name = "or",        .val = 32, .next = NULL};
    ExampleObj ord        = {.name = "ord",       .val = 13, .next = NULL};
    ExampleObj output     = {.name = "output",    .val = 23, .next = NULL};
    ExampleObj parse      = {.name = "parse",     .val = 43, .next = NULL};
    ExampleObj print      = {.name = "print",     .val = 32, .next = NULL};
    ExampleObj put_file   = {.name = "put-file",  .val = 13, .next = NULL};
    ExampleObj quit       = {.name = "quit",      .val = 23, .next = NULL};
    ExampleObj quote      = {.name = "quote",     .val = 43, .next = NULL};
    ExampleObj read       = {.name = "read",      .val = 32, .next = NULL};
    ExampleObj str        = {.name = "str",       .val = 13, .next = NULL};
    ExampleObj tail       = {.name = "tail",      .val = 23, .next = NULL};
    ExampleObj try_       = {.name = "try",       .val = 43, .next = NULL};
    ExampleObj type_      = {.name = "type",      .val = 32, .next = NULL};

    /* --- insert every object into the hash table --- */
    hash_table_insert(&plus);
    hash_table_insert(&minus);
    hash_table_insert(&div);
    hash_table_insert(&mult);
    hash_table_insert(&mod);
    hash_table_insert(&eq);
    hash_table_insert(&neq);
    hash_table_insert(&lt);
    hash_table_insert(&lte);
    hash_table_insert(&gt);
    hash_table_insert(&gte);
    hash_table_insert(&excl);
    hash_table_insert(&write);
    hash_table_insert(&and);
    hash_table_insert(&cell);
    hash_table_insert(&chr);
    hash_table_insert(&cons);
    hash_table_insert(&def);
    hash_table_insert(&doVal);
    hash_table_insert(&error);
    hash_table_insert(&fn);
    hash_table_insert(&get_file);
    hash_table_insert(&head);
    hash_table_insert(&ifVal);
    hash_table_insert(&input);
    hash_table_insert(&let);
    hash_table_insert(&list);
    hash_table_insert(&load);
    hash_table_insert(&loop);
    hash_table_insert(&macro);
    hash_table_insert(&not);
    hash_table_insert(&new_symbol);
    hash_table_insert(&or);
    hash_table_insert(&ord);
    hash_table_insert(&output);
    hash_table_insert(&parse);
    hash_table_insert(&print);
    hash_table_insert(&put_file);
    hash_table_insert(&quit);
    hash_table_insert(&quote);
    hash_table_insert(&read);
    hash_table_insert(&str);
    hash_table_insert(&tail);
    hash_table_insert(&try_);
    hash_table_insert(&type_);

    /* --- inspect table and try a simple lookup --- */
    print_table();

    ExampleObj* tmp = lookup_hash("+");
    if(tmp) printf("Found %s (val=%d)\n", tmp->name, tmp->val);
    else    printf("Did not find +\n");

    return 0;
}