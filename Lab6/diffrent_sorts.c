#include <stdlib.h>
#include "all_for_arrays.h"
void swap_elements(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_pointers(int** pointer1, int** pointer2){
    int* temp_pointer = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp_pointer;
}
struct min_info_of_array{
    int index;
    int min;
};

struct min_info_of_array min_even_element_in_diapason(const int* arr,int i,int size){
    struct min_info_of_array info;
    info.index = i;
    info.min = arr[i];
    for(i;i<size;i++){
        if(arr[i]<info.min){
            info.min = arr[i];
            info.index = i;
        }
    }
    return info;
}

void ShellSortTable(int*** table, int N, int M){
    int i,j, gap;
    for(gap = N/2;gap>0;gap/=2){
        for(i = gap;i<N;i++){
            for(j = i;j>=gap;j-=gap){
                if( sum_of_row((*table)[j],M) > sum_of_row((*table)[j-gap],M) ){
                    swap_pointers(&(*table)[j],&(*table)[j-gap]);
                }
            }
        }
    }
}

void SelectionSortForTaskOne(int* arr, int size){
    int temp_index;
    for(int i = index_of_max_element(arr,size)+1;i<size;i++){
        if(arr[i]%2 == 0){
            temp_index = min_even_element_in_diapason(arr,i,size).index;
            swap_elements(&arr[i],&arr[temp_index]);

        }
    }
}