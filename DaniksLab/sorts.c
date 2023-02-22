//
// Created by PC on 26.12.2022.
//

int sum_of_column(int** matrix, int N, int number_of_column){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += matrix[i][number_of_column];
    }
    return sum;
}

void swap_elements(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void QuickSort_for_second_task(int** matrix, int begin, int N, int M){
    int left = begin, right = M;
    int piv = sum_of_column(matrix,N,(begin+M)/2);
    do
    {
        while(sum_of_column(matrix,N,left) > piv){
            left++;
        }
        while(sum_of_column(matrix,N,right) < piv){
            right--;
        }
        if(left<=right){
            for(int i = 0;i < N; i++){
                swap_elements(&matrix[i][left],&matrix[i][right]);
            }
            left++;
            right--;
        }
    }while(left<=right);
    if(left<M){
        QuickSort_for_second_task(matrix,left,N,M);
    }
    if(right>begin){
        QuickSort_for_second_task(matrix,begin,N,right);
    }
}

void InsertionSort(int* array, int begin, int end){
    int newElement, location;
    for(int i = begin + 1; i < end; i++){
        newElement = array[i];
        location = i - 1;
        while(location>= 0 && array[location] > newElement){
            array[location + 1] = array[location];
            location--;
        }
        array[location + 1] = newElement;
    }
}