#include  "goodinputs.h"
#include "diffrent_sorts.h"
#include "all_for_arrays.h"

void task_two(){
    int** table;
    printf("Input how many rows should be in the table (N): \n>");
    int N = goodScanfInt();
    while(N<1){
        printf("You wrote an incorrect size for rows\nTry again!\n>");
        N = goodScanfInt();
    }
    printf("Input how many columns should be in the table (M): \n>");
    int M = goodScanfInt();
    while(M<1){
        printf("You wrote an incorrect size for columns\nTry again!\n>");
        M = goodScanfInt();
    }
    createMatrix(&table,N,M);
    print_matrix_t2(table,N,M);
    ShellSortTable(&table,N,M);
    printf("\n\n\n");
    print_matrix_t2(table,N,M);
    free_matrix(table,N);


}

