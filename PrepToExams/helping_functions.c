#include <stdlib.h>
#include "time.h"
#include <stdio.h>
int createArrayAndInit(int** array, int size){
    srand(time(NULL));
    *array = (int*)calloc(size,sizeof(int));
    for(int i = 0;i<size;i++){
        (*array)[i] = rand()%100;
    }

}
void printArray(const int* array,int size){
    for(int i = 0;i<size;i++){
        printf("[%d] ",array[i]);
    }
    printf("\n");
}