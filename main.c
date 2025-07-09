#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "hash_table.h"

int main(){
    int table_size = 44;
    // Not using custom destructor for ExampleObj as all are stack allocated for this demo
    HashTable* hash_table = hash_table_new(table_size, NULL);

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
    hash_table_insert(hash_table, &plus);
    hash_table_insert(hash_table, &minus);
    hash_table_insert(hash_table, &div);
    hash_table_insert(hash_table, &mult);
    hash_table_insert(hash_table, &mod);
    hash_table_insert(hash_table, &eq);
    hash_table_insert(hash_table, &neq);
    hash_table_insert(hash_table, &lt);
    hash_table_insert(hash_table, &lte);
    hash_table_insert(hash_table, &gt);
    hash_table_insert(hash_table, &gte);
    hash_table_insert(hash_table, &excl);
    hash_table_insert(hash_table, &write);
    hash_table_insert(hash_table, &and);
    hash_table_insert(hash_table, &cell);
    hash_table_insert(hash_table, &chr);
    hash_table_insert(hash_table, &cons);
    hash_table_insert(hash_table, &def);
    hash_table_insert(hash_table, &doVal);
    hash_table_insert(hash_table, &error);
    hash_table_insert(hash_table, &fn);
    hash_table_insert(hash_table, &get_file);
    hash_table_insert(hash_table, &head);
    hash_table_insert(hash_table, &ifVal);
    hash_table_insert(hash_table, &input);
    hash_table_insert(hash_table, &let);
    hash_table_insert(hash_table, &list);
    hash_table_insert(hash_table, &load);
    hash_table_insert(hash_table, &loop);
    hash_table_insert(hash_table, &macro);
    hash_table_insert(hash_table, &not);
    hash_table_insert(hash_table, &new_symbol);
    hash_table_insert(hash_table, &or);
    hash_table_insert(hash_table, &ord);
    hash_table_insert(hash_table, &output);
    hash_table_insert(hash_table, &parse);
    hash_table_insert(hash_table, &print);
    hash_table_insert(hash_table, &put_file);
    hash_table_insert(hash_table, &quit);
    hash_table_insert(hash_table, &quote);
    hash_table_insert(hash_table, &read);
    hash_table_insert(hash_table, &str);
    hash_table_insert(hash_table, &tail);
    hash_table_insert(hash_table, &try_);
    hash_table_insert(hash_table, &type_);

    /* --- inspect table and try a simple lookup --- */
    print_table(hash_table);

    ExampleObj* tmp = lookup_hash(hash_table, "+");
    if(tmp) printf("Found %s (val=%d)\n", tmp->name, tmp->val);
    else    printf("Did not find +\n");

    delete_hash_table(hash_table);
    return 0;
}