#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct ExampleObj{
    char* name;
    int val;
}ExampleObj;

unsigned int hash(char* name){
    return 0;
}

int main(){
    printf("Bob Hashed: %d\n", hash("Bob"));
    printf("Ron Hashed: %d\n", hash("Ron"));
    printf("Tracy Hashed: %d\n", hash("Tracy"));
    return 0;
}