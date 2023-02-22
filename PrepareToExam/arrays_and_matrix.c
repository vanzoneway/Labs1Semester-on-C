#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* init_array_and_randomised_it(int size){
    srand(time(NULL));
    int* array = (int*)malloc(sizeof(int)*size);
    for(int i = 0;i<size;i++){
        array[i] = rand()%(100-50+1);

    }
    return array;
}
void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("[%d] ",array[i]);
    }

    printf("\n");
}

void add_zero_after_odd_elements(int** array, int* size){
    for (int i = 0; i < *size; i++){
        if ((*array)[i] % 2 == 0){
            (*size)++;
            *array = (int*)realloc(*array,sizeof(int)*(*size));
            for(int j = *size-1; j > i; j--){
                (*array)[j] = (*array)[j-1];
            }
            i++;
            (*array)[i] = 0;
            i++;
        }


    }
}

void print_table(int** table, int N, int M){
    for(int i = 0; i < N; i++){
        print_array(table[i],M);
    }
}

int** create_and_init_matrix(int*** table, int N, int M){
    srand(time(NULL));
    *table = (int**)malloc(sizeof(int*)*N);
    for(int i = 0; i < N; i++){
        (*table)[i] = (int*)calloc(M,sizeof(int));
        for(int j = 0;j < M;j++){
            (*table)[i][j] = -50 + rand()%(100+50-1);
        }
    }

    return *table;
}
