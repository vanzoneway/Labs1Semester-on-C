#include <stdio.h>
#include "diffrent_sorts.h"
#include "helping_functions.h"



int main() {
    int* array;
    int size;
    printf("A size of array\n>");
    scanf("%d",&size);
    createArrayAndInit(&array,size);
    printArray(array,size);
    QuickSort(array,0,size-1);
    printArray(array,size);

}
