#include "goodinputs.h"
//return index or -1< if k> quality of words in string
int quality_of_words(const char* string) {
    int cnt = 0, i = 0;
    while (string[i] != '\n') {
        if ((i == 0 && string[i] != ' ') || (string[i - 1] == ' ' && string[i] != ' ')) {
            cnt++;
        }
        i++;
    }
    return cnt;
}
int index_of_beginning_k_word(const char* string, int k){
    int cnt = 0, i = 0;
    while(string[i]!='\n'){
        if((i == 0 && string[i]!=' ')|| (string[i-1] == ' ' && string[i] != ' ')){
            cnt++;
        }
        i++;
        if(cnt == k)
            return i-1;

    }
    return -1;
}
// return index of the end of k word, and gets char* string and index
// of the beginning of k word as arguments
int index_of_end_k_word(const char* string, int begin_index_k){
    int i = begin_index_k;
    while(string[i]!=' ' && string[i]!='\n'){
        i++;
    }
    return i-1;
}
void rotate_k_word(char* string, int k){
    int begin, end;
    begin = index_of_beginning_k_word(string,k);
    end = index_of_end_k_word(string, begin);
    for(begin;begin <= (begin+end)/2 && end >= (begin+end)/2;begin++,end--){
        char tmp = string[end];
        string[end] = string[begin];
        string[begin] = tmp;
    }
}


void task_one(){
    char* string;
    printf("Input a string\n");
    int size = get_string(&string);
    for(int i = 0; i<size;i++){
        printf("%c",string[i]);
    }
    printf("Input a k\n>");
    int k = goodScanfInt();
    while(k<1 ||k > quality_of_words(string)){
        printf("Theres is no k word in sequence of word. Try again!\n>");
        k = goodScanfInt();
    }
    rotate_k_word(string,k);
    printf("Result is:\n");
    for(int i = 0; i<size;i++){
        printf("%c",string[i]);
    }
    printf("\n");

}