#include <stdio.h>

int checkingOneError(int error){
    if(error!=1){
        return error;
    }
    char temp = getchar();
    if(temp!='\n'){
        if (temp > '9' || temp < '0') {
            return -2;
        }
    }
    return 1;
}
int goodScanfInt(){
    int num = 0;
    rewind(stdin);
    while(checkingOneError(scanf("%d",&num))!=1){
        printf("You wrote an incorrect symbol. Try again!\n>");
        rewind(stdin);
    }
    return num;
}
int goodScanfFloat(){
    float num = 0;
    rewind(stdin);
    while(checkingOneError(scanf("%f",&num))!=1){
        printf("You wrote an incorrect symbol. Try again!\n>");
        rewind(stdin);
    }
    return num;
}