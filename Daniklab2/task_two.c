#include "goodinputs.h"
#include "stdlib.h"
void task_two(){
    char* string1;
    char* string2;
    printf("Input N1:\n>");
    int N1 = goodScanfInt();
    while(N1<0){
        printf("N1 cannot be less then 0! Try again:\n>");
        N1 = goodScanfInt();
    }
    printf("Input N2:\n>");
    int N2 = goodScanfInt();
    while(N2<0){
        printf("N1 cannot be less then 0! Try again:\n>");
        N2 = goodScanfInt();
    }
    printf("Input a string1:\n");
    int size_of_string1 = get_string(&string1);
    while(size_of_string1<=N1){
        printf("Size of string1 cannot be less then N1. Write string again!\n");
        size_of_string1 = get_string(&string1);
    }
    printf("Input a string2:\n");
    int size_of_string2 = get_string(&string2);
    while(size_of_string2<=N2){
        printf("Size of string2 cannot be less then N2. Write string again!\n");
        size_of_string2 = get_string(&string2);
    }
    char* newString = (char*)malloc(sizeof(char)*(N1+N2));
    for(int i = 0; i < N1; i ++){
        newString[i] = string1[i];
    }
    for(int i = size_of_string2 - N2-1, counter = N1; i < size_of_string2; i++, counter++){
        newString[counter] = string2[i];
    }
    for(int i = 0; i < (N1+N2); i++){
        printf("%c",newString[i]);
    }
    printf("\n");


}
