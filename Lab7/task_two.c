#include "goodinputs.h"
#include <stdlib.h>




void task_two(){
    char* S0;
    char* S;
    char C;
    printf("Input a SO\n>");
    int size_of_S0 = get_string(&S0);
    printf("Input a S\n>");
    int size_of_S = get_string(&S);
    printf("Input a symbol C\n>");
    scanf("%c", &C);
//    steps in char array to find needed element
    for(int i = 0; i<size_of_S;i++){
        if(S[i] == C){
//          increase size of S on size of S0, but on 1 element less, cause end of string is '\n'
            size_of_S += size_of_S0-1;
            S = (char*)realloc(S,size_of_S);
//          shift elemenets on n positions, where n = size_of_S0-1
            for(int j = 0;j<size_of_S0-1;j++){
                for(int k = size_of_S;k>i;k--){
                    S[k] = S[k-1];
                }
            }
            int counter = 0;
            for(int j = i;j<i+size_of_S0-1;j++){
                S[j] = S0[counter];
                counter++;
            }
//          not to forget to increase i on size_of_SO -1!!!
            i+= size_of_S0-1;
        }
    }
    puts(S);

}
