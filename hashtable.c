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
    // Linear probing in case of collisions
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + idx) % TABLE_SIZE;
        if(!hash_table[try]){
            hash_table[try] = v;
            return true;
        }
    }
    printf("Collision!\n");
    return false;
}

ExampleObj* lookup_hash(const char* name){
    int idx = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + idx) % TABLE_SIZE;
        if(hash_table[try] && strcmp(hash_table[try]->name, name) == 0) return hash_table[try];
    }
    return NULL;
}

ExampleObj* delete_hash(const char* name){
    int idx = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + idx) % TABLE_SIZE;
        if(hash_table[try] && strcmp(hash_table[try]->name, name) == 0){
            ExampleObj* tmp = hash_table[try];
            hash_table[try] = NULL;
            return tmp;
        }
    }
    return NULL;
}

int main(){
    init_hash_table();

    /* --- create all ExampleObj instances --- */
    ExampleObj plus       = {.name = "+",         .val = 13};
    ExampleObj minus      = {.name = "-",         .val = 23};
    ExampleObj div        = {.name = "/",         .val = 43};
    ExampleObj mult       = {.name = "*",         .val = 32};
    ExampleObj mod        = {.name = "%",         .val = 13};
    ExampleObj eq         = {.name = "=",         .val = 23};
    ExampleObj neq        = {.name = "!=",        .val = 43};
    ExampleObj lt         = {.name = "<",         .val = 32};
    ExampleObj lte        = {.name = "<=",        .val = 13};
    ExampleObj gt         = {.name = ">",         .val = 23};
    ExampleObj gte        = {.name = ">=",        .val = 43};
    ExampleObj excl       = {.name = "!",         .val = 32};
    ExampleObj write      = {.name = ":=",        .val = 1 };
    ExampleObj and        = {.name = "and",       .val = 13};
    ExampleObj cell       = {.name = "cell",      .val = 23};
    ExampleObj chr        = {.name = "chr",       .val = 43};
    ExampleObj cons       = {.name = "cons",      .val = 32};
    ExampleObj def        = {.name = "def",       .val = 13};
    ExampleObj doVal      = {.name = "do",        .val = 23};
    ExampleObj error      = {.name = "error",     .val = 43};
    ExampleObj fn         = {.name = "fn",        .val = 32};
    ExampleObj get_file   = {.name = "get-file",  .val = 13};
    ExampleObj head       = {.name = "head",      .val = 23};
    ExampleObj ifVal      = {.name = "if",        .val = 43};
    ExampleObj input      = {.name = "input",     .val = 32};
    ExampleObj let        = {.name = "let",       .val = 13};
    ExampleObj list       = {.name = "list",      .val = 23};
    ExampleObj load       = {.name = "load",      .val = 43};
    ExampleObj loop       = {.name = "loop",      .val = 32};
    ExampleObj macro      = {.name = "macro",     .val = 13};
    ExampleObj not        = {.name = "not",       .val = 23};
    ExampleObj new_symbol = {.name = "new-symbol",.val = 43};
    ExampleObj or         = {.name = "or",        .val = 32};
    ExampleObj ord        = {.name = "ord",       .val = 13};
    ExampleObj output     = {.name = "output",    .val = 23};
    ExampleObj parse      = {.name = "parse",     .val = 43};
    ExampleObj print      = {.name = "print",     .val = 32};
    ExampleObj put_file   = {.name = "put-file",  .val = 13};
    ExampleObj quit       = {.name = "quit",      .val = 23};
    ExampleObj quote      = {.name = "quote",     .val = 43};
    ExampleObj read       = {.name = "read",      .val = 32};
    ExampleObj str        = {.name = "str",       .val = 13};
    ExampleObj tail       = {.name = "tail",      .val = 23};
    ExampleObj try_       = {.name = "try",       .val = 43};
    ExampleObj type_      = {.name = "type",      .val = 32};

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