//
// Created by PC on 23.11.2022.
//

#ifndef LAB6_ALL_FOR_ARRAYS_H
#define LAB6_ALL_FOR_ARRAYS_H

#endif //LAB6_ALL_FOR_ARRAYS_H
#include <stdio.h>
void createMatrix(int*** table, int N, int M);
int sum_of_row(const int* row,int M);
void print_matrix_t2(int** table, int N, int M);
void free_matrix(int** table, int N);
int createArray(int** arr);
void print_array(int* arr, int size);
int index_of_max_element(const int* arr, int size);