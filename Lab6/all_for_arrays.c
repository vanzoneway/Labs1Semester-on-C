#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "goodinputs.h"
#include <time.h>
void give_memory_matrix(int*** table, int N, int M){
    *table = (int**)malloc(N*sizeof(int*));
    for(int i = 0;i<N;i++){
        (*table)[i] = (int*)calloc(M,sizeof(int));
    }
}
void randomised_init_matrix(int*** table, int N, int M){
    srand(time(NULL));
    for(int i = 0; i<N;i++){
        for(int j = 0;j<M;j++){
            (*table)[i][j] = rand()%(100-50+1);
        }
    }
}
void input_array_by_keyboard(int*** table, int N, int M){
    for(int i = 0;i<N;i++){
        printf("Enter [%d] row of matrix:\n ",i+1);
        for(int j = 0; j<M;j++){
            printf("Element [%d][%d] = ", i+1,j+1);
            (*table)[i][j] = goodScanfInt();
            printf("\n");
        }
    }
}

void createMatrix(int*** table, int N, int M){

    printf("Enter [1] if you wanna randomised matrix\nEnter [2] if you wanna matrix by keyboard\n>");
    int var = goodScanfInt();
    int flag = 1;

    while(flag){

        switch (var) {
            case 1:
                give_memory_matrix(table,N,M);
                randomised_init_matrix(table,N,M);
                flag = 0;
                break;
            case 2:
                give_memory_matrix(table,N,M);
                input_array_by_keyboard(table,N,M);
                flag = 0;
                break;


            default:
                printf("You wrote an incorrect variant, try again!\n>");
                var = goodScanfInt();

        }
    }
}

int sum_of_row(const int* row, int M){
    int sum = 0;
    for(int i = 0;i<M;i++){
        sum += row[i];
    }
    return sum;
}

void print_matrix_t2(int** table, int N, int M){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d ",table[i][j]);
            if(j == M-1){
                printf("   (sum of array = %d)", sum_of_row(table[i],M));
            }
        }
        printf("\n");
    }
}

void free_matrix(int** table, int N){
    for(int i = 0;i<N;i++){
        free(table[i]);
    }
    free(table);
}

/*functions for arrays, NOT FOR TABLES!*/

//returns quality of symbols in a string before '\n'
int str_len(const char* str){
    int i = 0;
    while(str[i]!='\n'){
        i++;
    }
    return i;
}

// checking if number a character or a decimal number. returns 1
// if a decimal number; returns 0 if a character
int if_number(char s){
    if(s>= '0' && s<='9')
        return 1;
    return 0;
}

//returns quality of words devided by spaces in string
int find_quality_of_words(char* str) {
    int i = 0, n = str_len(str), cnt = 0;
    while (str[i] != '\n') {
        if ((i == 0 && if_number(str[i]) == 1) || (if_number(str[i - 1]) == 0 && if_number(str[i]) == 1)) {
            cnt++;
        }
        i++;


    }
    return cnt;
}

// returns index of k word in string
int beginning_of_k_word(char* str, int k){
    int b = 0, n = str_len(str), cnt = 0, j = 0;
    while(str[j]!='\n'){
        if( (j == 0 && if_number(str[j]) == 1) || (if_number(str[j-1]) == 0 && if_number(str[j]) == 1))
            cnt++;
        if(cnt == k)
            return j;
        j++;
    }
    return -1;
}

//converts a number from k index to int
int a_to_i_from_k(const char* s, int k){
    int n, znak;
    if( (s[k-1] == '+' || s[k-1] == ' ') || k == 0){
        znak = 1;
    } else{
        znak = -1;
    }

    for (n=0;s[k]>='0' && s[k]<='9';k++){
        n = 10*n +(s[k] - '0');
    }
    return n*znak;
}

//get string from command line with error checking; return 1
//if all good, returns 0 if something went wrong
int check_and_get_string(char** str){
    int w = 0, size_of_str = 1;
    char c;
    int flag = 1;

    while((c = getchar())!= '\n' && flag){


        size_of_str = w + 1;
        *str = (char *) realloc(*str, sizeof(char) * (size_of_str));
        (*str)[w] = c;
        w++;
        if((c>'9' || c< '0') && c != ' ' && c!= '-' && c!= '+'){
            printf("BAD! Try again!\n");
            *str = (char*)realloc(*str,sizeof(char));
            rewind(stdin);
            flag = 0;
            break;
        }
    }
    (*str)[w] = '\n';
    return flag;
}

int init_array_from_keyboard(int** arr){
    int w = 0, size_of_array;

    char* str = (char*)calloc(1,sizeof(char));
    int flag = 0;
    while(flag == 0){
        flag = check_and_get_string(&str);
    }
    size_of_array = find_quality_of_words(str);
    (*arr) = (int*)calloc(size_of_array,sizeof(int));
    for(int i = 0;i<size_of_array;i++){
        (*arr)[i] = a_to_i_from_k(str, beginning_of_k_word(str,i+1));
    }
    return size_of_array;

}
void randomised_init_array(int* arr, int size){
    srand(time(NULL));
    for(int i = 0;i<size;i++){
        arr[i] = rand()%(100-50+1);
    }
}



int createArray(int** arr){
    int size;
    printf("Enter [1] if you wanna randomised array\n Enter [2] if you wanna keyboard array\n>");
    int var = goodScanfInt();
    int flag = 1;
    while(flag){
        switch (var) {
            case 1:
                printf("Input a size of array:\n>");
                size = goodScanfInt();
                while(size<1 || size > 10000){
                    printf("You wrote an incorrect size of array. Try again!\n>");
                    size = goodScanfInt();
                }
                *arr = (int*)malloc(sizeof(int)*size);
                randomised_init_array(*arr, size);
                flag = 0;
                break;
            case 2:
                size = init_array_from_keyboard(&(*arr));
                flag = 0;
                break;
            default:
                printf("You wrote and incorrect variant! Try again!\n>");
                var = goodScanfInt();
        }
    }
    return size;
}
void print_array(int* arr, int size){
    for(int i = 0;i<size;i++){
        printf("[%d] ",arr[i]);
    }
}

int index_of_max_element(const int* arr, int size){
    int max = arr[0];
    int index_of_max = 0;
    for(int i = 0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
            index_of_max = i;
        }
    }
    return index_of_max;
}