#include <stdlib.h>
void QuickSort(int* array, int begin, int end){
    int piv = array[(end+begin)/2];
    int left = begin;
    int right = end;
    do{
        while(array[left] < piv){
            left++;
        }
        while(array[right] > piv){
            right--;
        }
        if(left<=right){
            int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
            left++;
            right--;
        }

    }while(left<=right);
    if(left < end){
        QuickSort(array,left,end);
    }
    if(right>begin){
        QuickSort(array,begin,right);
    }

}

