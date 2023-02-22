#include "goodinputs.h"

void task_one(){
    char* string;
    printf("Input a string:\n");
    int size_of_string = get_string(&string);
    for(int i = 0; i < size_of_string; i++){
        printf("%c",string[i]);
    }
    for(int i = 0; i < size_of_string; i++){
        if((i == 0 && string[i] != ' ') || (string[i - 1] == ' ' && (string[i] != ' ' && string[i]!='\n'))){
            string[i] = string[i] - 'a' + 'A';
        }
    }
    for(int i = 0; i < size_of_string; i++){
        printf("%c",string[i]);
    }

}
