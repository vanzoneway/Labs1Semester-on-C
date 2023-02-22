#include <stdio.h>
#include "goodinputs.h"
#include "all_for_strings.h"
#include "arrays_and_matrix.h"
#include<stdlib.h>
#include<time.h>

void swap_elements(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void InsertionSort(int* array, int size){
    int newElement, location;
    int isEven = 0;
    for(int i = 1; i < size; i++){
        newElement = array[i];
        location = i-1;
        while(location >= 0 && array[location] > newElement){
            array[location+1] = array[location];
            location--;
        }
        array[location+1] = newElement;
    }
}


void BubbleSort(int* array, int size){
    int n = 0;
    for(int i = size-1; i>=0; i--){
        for(int j = 0; j < i; j++){
            if(array[j]%2 == 0){
                for(int k = j+1;k<i;k++){
                    if(array[k]%2 == 0 && array[k]<array[j]){
                        swap_elements(&array[j],&array[k]);
                    }
                }
            }
        }
    }
}


void sdvig(int* array, int size, int k){
    int n = 0;
    while(n<k){
        for(int i = 0; i < size; i++){
            if(array[i] % 2 == 0){
                for( int j = i+1; j < size; j++){
                    if(array[j]%2 == 0){
                        swap_elements(&array[i], &array[j]);
                        i = j;
                    }
                }
            }
        }

        n++;
    }
}

void ShellSort(int* array, int size, int k){
    for (int gap = size/2;gap>0;gap /=2){
        for(int i = gap;i<size;i++){
            for(int j = i; j >= gap; j-=gap){
                if(array[j] > array[j-gap]){
                    swap_elements(&array[j],&array[j-gap]);
                }
            }
        }
    }
}


int main(){

}