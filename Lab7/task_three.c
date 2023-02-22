#include "goodinputs.h"
#include <stdio.h>
#include <stdlib.h>
int size_of_str(const char* string){
    int i = 0;
    while(string[i]!='\n'){
        i++;
    }
    return i;
}
void init_char_table(int rows[], char** table, int count_of_rows){
    for(int i = 0;i<count_of_rows;i++){
        rows[i] = get_string(&table[i]);
    }
}
void print_char_table(const int rows[],char** table, int count_of_rows){
    for(int i = 0; i <count_of_rows; i++){
        for(int j = 0; j < rows[i]; j++){
            printf("%c",table[i][j]);
        }

    }
}
int quality_of_words_three(const char* string, int size_of_string){
    int i, cnt = 0;
    for(i = 0;i<size_of_string;i++){
        if((i == 0 && string[i]!= ' ') ||((string[i]!=' ' && string[i-1] == ' ') && string[i]!='\n')){
            cnt++;
        }
    }
    return cnt;
}
void swap_char_pointers(char** string1, char** string2){
    char* tmp = *string1;
    *string1 = *string2;
    *string2 = tmp;
}
void swap_elements(int* el1, int* el2){
    int tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}
void QuickSort_for_char_table(char*** table, int begin, int end,int rows[]){
    int l = begin, r = end;
    int piv = quality_of_words_three((*table)[(l+r)/2],rows[(l+r)/2]);
   do{
        while (quality_of_words_three((*table)[l], rows[l]) < piv) {
            l++;
        }
        while (quality_of_words_three((*table)[r], rows[r]) > piv) {
            r--;
        }
        if (l <= r) {
            swap_char_pointers(&(*table)[l], &(*table)[r]);
            swap_elements(&rows[l],&rows[r]);
            l++;
            r--;

        }
    } while(l<=r);
    if(l<end){
        QuickSort_for_char_table(table,l,end,rows);
    }
    if(r>begin){
        QuickSort_for_char_table(table,begin,r,rows);
    }
}
void task_three(){
    printf("Please, input how many rows will be in your table:\n>");
    int count_of_rows = goodScanfInt();
    char** table = (char**)malloc(sizeof(char*)*count_of_rows);
    int rows[count_of_rows];
    init_char_table(rows,table,count_of_rows);
    print_char_table(rows,table,count_of_rows);
    QuickSort_for_char_table(&table,0,count_of_rows-1,rows);
    printf("\n");
    print_char_table(rows,table,count_of_rows);


}