#include <stdlib.h>
#include <stdio.h>
void swap_elements(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int index_of_minimum_in_diapason(const int* array,int begin, int end){
    int min = array[begin];
    int index = begin;
    for(int i = begin+1;i<=end;i++){
        if(array[i]<min){
            min = array[i];
            index = i;

        }
    }
    return index;
}
void BubbleSort(int* array,int size){
    int bool = 1;
    while(bool){
        bool = 0;
        for(int i = 1;i<size;i++){
            if(array[i]<array[i-1]){
                swap_elements(&array[i],&array[i-1]);
                bool = 1;
            }
        }
        size--;
    }
}

void ShakerSort(int* array,int size){
    int left = 1;
    int right = size-1;
    while(left<=right){
        for(int i = left;i<=right;i++){
            if(array[i]<array[i-1]){
                swap_elements(&array[i],&array[i-1]);
            }
        }
        right--;
        for(int j = right; j>=left;j--){
            if(array[j]<array[j-1]){
                swap_elements(&array[j],&array[j-1]);
            }
        }
        left++;

    }
}

void InsertionSort(int* array, int size){
    for(int i = 1;i <size; i++){
        int tmp = array[i];
        int k = i;
        while(k>0 && array[k-1]>tmp){
            array[k] = array[k-1];
            k--;
        }
        array[k] = tmp;
    }
}

void SelectionSort(int* array, int size){
    int counter = 0;
    for(int i = 0;i<size;i++){
        swap_elements(&array[i],&array[index_of_minimum_in_diapason(array,i,size-1)]);
    }
}

void QuickSort(int* array, int begin, int end){
    int i = begin, j = end;
    int pivat = array[(end+begin)/2];
    do
    {
       while(array[i]<pivat ){
           i++;
       }
       while(array[j]>pivat) {
           j--;
       }
       if(i<=j){
           swap_elements(&array[i],&array[j]);
           i++;
           j--;
       }
    }while(i<=j);

    if(i<end){
        QuickSort(array,i,end);
    }
    if(j>begin){
        QuickSort(array,begin,j);
    }
}

void ShellSort(int* array, int size){
    for(int gap = size/2;gap>0;gap/=2){
        for(int i = gap;i<size;i++){
            for(int j = i;j>=gap;j-=gap){
                if(array[j]<array[j-gap]){
                    swap_elements(&array[j],&array[j-gap]);
                }
            }
        }
    }
}



void Merge(int* sarr, int first, int last) {
    int* tmp_arr = (int*)malloc(sizeof(int)*(last-first+1));
    int left_iterator, middle, right_iterator;
    left_iterator = first;
    middle = (first+last)/2;
    right_iterator = middle+1;
    for(int i = first;i<=last;i++){
        if((left_iterator<=middle) && (right_iterator>last || sarr[left_iterator]<sarr[right_iterator])){
            tmp_arr[i - first] = sarr[left_iterator];
            left_iterator++;
        }else{
            tmp_arr[i - first] = sarr[right_iterator];
            right_iterator++;
        }
    }
    for(int i = first;i<=last;i++){
        sarr[i] = tmp_arr[i-first];
    }
    free(tmp_arr);


}
void MergeSort(int* arr, int begin, int end){
    if(begin<end){
        MergeSort(arr,begin,(begin+end)/2);
        MergeSort(arr,(begin+end)/2+1,end);
        Merge(arr,begin,end);


    }
}