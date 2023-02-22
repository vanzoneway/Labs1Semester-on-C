#include <stdio.h>
#include <stdlib.h>
int str_len(char *s){
    int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
void str_copy(char* s1, char **s2){
    int i = 0;
    int n = str_len(s1);
    *s2 = (char* )calloc(n,sizeof(char));
    while(s1[i]!='\0'){
        (*s2)[i] = s1[i];
        i++;
    }
    *s2[i] = '\0';

}
// Найти k-ое слово
int if_letter(char s){
    if((s>= 'a' && s<='z')||(s>='A'&& s<='Z')){
        return 1;
    }
    return 0;
}
int find_k_word(char* s, int k){
    int i = 0, n = str_len(s), ent = 0;
    while(s[i]!='\0'){
        if((i==0 && if_letter(s[i])==1)||(if_letter(s[i-1]) == 0 && if_letter(s[i]) == 1)){
            ent++;
        }
        if (ent == k){
            return i;
        }
        i++;
    }
    return -1;
}



int main() {
    printf("Hello, World!\n");
    return 0;
}
