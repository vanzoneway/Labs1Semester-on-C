#include <stdlib.h>
#include "goodinputs.h"
#include <time.h>
#include <stdio.h>
void doArrayInt(int** array,int* size);
void printMenu(){
    printf("What do you want to do ?(Enter a variant)\n");
    printf("1.First task\n");
    printf("2.Second task\n");
    printf("3.Third task\n");
    printf("4.Clear display\n");
    printf("5.Exit\n>");

}
void doMatrixInt(int*** table,int* size){
    *table  = (int**)malloc(sizeof(int*)*(*size));
    for(int i = 0;i<(*size);i++){
        (*table)[i] = (int*)malloc(sizeof(int)*(*size));
    }
}

void do_matrix_for_third_task(int*** table,int* size){
    doMatrixInt(table,size);
    for(int i = 0;i<(*size);i++){
        printf("Enter [%d] array of matrix\n",i);
        int* temp;
        doArrayInt(&temp,size);
        (*table)[i] = temp;
    }

}
void printMatrixInt(int** table, int size){
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            printf("[%d] ",table[i][j]);
        }
        printf("\n");
    }
}
void doArrayInt(int** array,int* size){
    srand(time(NULL));
    *array = (int*)malloc(sizeof(int)*(*size));
    printf("1.Make array from random elements\n2.Input array by keyboard\n>");
    int var  = goodScanfInt();
    while(var>2||var<1){
        printf("You wrote an incorrect variant. Try again!\n>");
        var = goodScanfInt();
    }
    if(var == 1){
        for(int i = 0;i<(*size);i++){
            (*array)[i] = rand()%(100+50+1)-50;
        }
    }else{
        for(int i = 0;i<(*size);i++){
            printf("Input a [%d] element of array\n>",i);
            (*array)[i] = goodScanfInt();
        }
    }
}
void do_array_for_first_task(int** array){
    (*array) = (int*)malloc(sizeof(int)*49);
    int x = 2;
    for(int i = 0;i<49;i++){
        (*array)[i] = x;
        x +=2;
    }
}
void printArrayInt(int* array, int size){
    for(int i = 0;i<size;i++){
        printf("[%d] ",array[i]);
    }
    printf("\n");
}
void one_one(){
//    the size of array will be 49, because we have to do array till 99
    int* array;
    do_array_for_first_task(&array);
    printArrayInt(array,49);
    printf("Enter the beginning of the segment\n>");
    int beginning = goodScanfInt();
    while(beginning<2||beginning>98){
        printf("You out of diapason of array. Enter it again!\n>");
        beginning = goodScanfInt();
    }
    printf("Enter the end of the segment\n>");
    int end = goodScanfInt();
    while(end<2||end>98){
        printf("You out of diapason of array. Enter int again!\n>");
        end = goodScanfInt();
    }
//    we have to create counter to change indexes of our array, because each time
//    when we will delete 1 elements, indexing of array changes. we have to take it into account
    int counter = 0;
    for(int i = 0;i<49;i++){
        if(array[i-counter] >= beginning && array[i-counter]<=end){
            for(int j = i-counter;j<49;j++){
                array[j] = array[j+1];
            }
            counter++;
        }
    }
    array = (int*)realloc(array,sizeof(int)*49-counter);
    printArrayInt(array,49-counter);
    free(array);
}
void two_one() {
    printf("Input how many rows should be in a table\n>");
    int size_of_table = goodScanfInt();
    int **table = calloc(size_of_table, sizeof(int *));
    int *rows = calloc(size_of_table, sizeof(int));
    for (int i = 0; i < size_of_table; i++) {
        int n = 1;
        printf("Enter a %d row\n>",i);
        rewind(stdin);
        do {

            if(scanf("%d", &n)== 0){
                printf("You wrote an incorrect raw. Try again!\n");
                rewind(stdin);
                i -=1;
                break;

            }
            table[i] = realloc(table[i], sizeof(int) * (rows[i] + 1));
            table[i][rows[i]] = n;
            rows[i]++;
        } while (n != 0);
    }
    for(int i = 0;i<size_of_table;i++){
        for(int j = 0;j<rows[i];j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
}
void three_one() {
    int **matrix;
    int size;
    printf("Input a size of matrix:\n>");
    size = goodScanfInt();
    while (size <= 0) {
        printf("Too small size of matrix or size is negative number.\nTry again!\n>");
        size = goodScanfInt();
    }

    do_matrix_for_third_task(&matrix, &size);
    printMatrixInt(matrix, size);
    int min_number_under = matrix[1][0];
    int min_number_over = matrix[0][1];
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (min_number_over > matrix[i][j]) {
                min_number_over = matrix[i][j];
            }
            if (min_number_under > matrix[j][i]) {
                min_number_under = matrix[j][i];
            }
        }
    }
    if (size > 1) {
        printf("Minimal number under main diagonal of matrix is %d\n", min_number_under);
        printf("Minimal number over main diagonal of matrix is %d\n", min_number_over);
    } else {
        printf("There is only 1 element in matrix!\n");
    }

}