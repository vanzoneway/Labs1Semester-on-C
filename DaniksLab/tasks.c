#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorts.h"
#include "goodinputs.h"

void init_array_from_keyboard(int* array, int size){
    for(int i = 0; i < size; i++ ){
        printf("[%d]\n>", i);
        array[i] = goodScanfInt();
    }
}
void init_array_by_random(int* array, int size){

    for(int i = 0;i<size;i++){
        array[i] = rand()%100;
    }
}
int min_element_from_left(const int* array, int size){
    int min = array[0];
    int index;
    for(int i = 0; i < size; i++){
        if(array[i]<min){
            min = array[i];
            index = i;
        }
    }
    return index;
}
int min_element_from_right(const int* array, int size){
    int min = array[0];
    int index;
    for(int i = 0; i < size; i++){
        if(array[i]<=min){
            min = array[i];
            index = i;
        }
    }
    return index;
}
void print_array(const int* array, int size){
    for(int i = 0; i < size; i++){
        printf("[%d] ", array[i]);
    }
    printf("\n");
}
void first_task(){
    srand(time(NULL));
    printf("A size of array:\n>");
    int size = goodScanfInt();
    while(size<0){
        printf("A size cannot be less then 0!\nTry again:\n>");
        size = goodScanfInt();
    }
    int* array = (int*)malloc(sizeof(int)*size);
    printf("Input 1 if you wanna input from keyboard ( another numbers will init by random ) \n>");
    int variant = goodScanfInt();
    if(variant == 1){
        init_array_from_keyboard(array,size);
    }else{
        init_array_by_random(array,size);
    }
    print_array(array,size);
    int left = min_element_from_left(array,size);
    int right = min_element_from_right(array,size);
    if(left == right){
        printf("Min index of first and last are the similar, so we did nothing!\n");
        print_array(array,size);
    }else{
        InsertionSort(array,left,right);
        print_array(array,size);
    }

}




void init_matrix_by_random(int** array, int N, int M){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = rand()%(100+30-1);
        }
    }
}
void init_matrix_from_keyboard(int** array, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("[%d][%d]:\n>", i, j);
            array[i][j] = goodScanfInt();
        }
    }
}
void print_matrix(int** array, int N, int M){
    for(int i = 0;i < M; i++){
        printf("{%d}", sum_of_column(array,N,i));
    }
    printf("\n");
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            printf("[%d] ", array[i][j]);
        }

        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void second_task(){
    int** matrix;
    printf("Input N:\n>");
    int N = goodScanfInt();
    while(N<0){
        printf("N cannot be less then 0! Try again:\n>");
        N = goodScanfInt();
    }
    int M = goodScanfInt();
    while(M<0){
        printf("M cannot be less then 0! Try again:\n>");
        M = goodScanfInt();
    }
    matrix = (int**)malloc(sizeof(int*)*N);
    for(int i = 0; i < N; i++){
        matrix[i] = (int*)malloc(sizeof(int*)*M);
    }

    init_matrix_by_random(matrix,N,M);
    print_matrix(matrix,N,M);
    QuickSort_for_second_task(matrix,0,N,M-1);
    print_matrix(matrix,N,M);

}