#include <stdio.h>
#include "stdlib.h"

int main() {
    FILE* f;
    f = fopen("file.txt","a+");
    if(f == NULL){
        printf("Error\n");
        return 0;
    }
    int n = 0;
    while(!feof(f)){
        n++;
    }

    int y;
    char* a;
    a = (char*)malloc(sizeof(char)* n);
    a = fgets(a, n,f);
    puts(a);

}