#include <stdio.h>
#include <stdlib.h>


int get_string(char** string){
    *string = (char*)malloc(sizeof(char) * 1);
    int size = 0;
    char c;
    while( (c = getchar()) != '\n'){
        (*string)[size] = c;
        size++;
        *string = (char*)realloc(*string,size+1);

    }
    (*string)[size] = '\0';
    return size;
}

int str_len(char* string){
    int len = 0;
    while(string[len]!='\0'){
        len++;
    }
    return len;
}
// copy string1 into string2
void str_copy(char* string1, char** string2){
    int n = str_len(string1);
    *string2 = (char*)calloc(n+1,sizeof(char));
    int i = 0;
    while(string1[i] != '\0'){
        (*string2)[i] = string1[i];
        i++;
    }
    (*string2)[i] = '\0';
}

int if_letter(char s){
    if((s > 'a' && s<'z') || (s > 'A' && s < 'Z')){
        return 1;
    }
    return 0;
}


int find_index_of_begin_of_k_word(char* string, int k){
    int i = 0, cnt = 0;

    while(string[i] != '\0'){

        if( (i == 0 && if_letter(string[i]) ==  1) || (if_letter(string[i+1]) == 1 && if_letter(string[i]) == 0)  ){
            cnt++;
        }
        if(cnt == k){
            return i;
        }
        i++;
    }
    return -1;
}


int find_index_of_end_of_k_word(char* string, int k){
    int i = find_index_of_begin_of_k_word(string,k);
    while(string[i+1]!='\0' && string[i+1] != ' '){
        i++;
    }
    return i;
}

void reverse_of_k_word(char* string, int begin, int end){
    int k = 0;
    for(int i = begin; i <= (begin+end)/2; i++){
        char tmp = string[i];
        string[i] = string[end-k];
        string[end-k] = tmp;
        k++;
    }
}

int a_to_i(char *s) {
    int n, i = 0, znak;
    while (s[i] != '\0' && s[i] == ' ')
        i++;

    if (s[i] == '\0') return 0;

    znak = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return znak * n;
}

int remove_k_word(char* string, int k){
    int size = str_len(string);
    int times = find_index_of_end_of_k_word(string,k)- find_index_of_begin_of_k_word(string,k)+1;
    int f = 0;
    int index = find_index_of_begin_of_k_word(string, k);
    while(f<times){
        f++;
        for(int i = index; i < size; i++){
            string[i] = string[i+1];
        }
        size--;
    }
    return size;
}
// return -1 if s1 < s2, return 0 if s1 == s2 or s1 > s2 and return
int str_cmp(char* s1, char* s2){
    int i = 0;
    while(s1[i] != '\0'){
        if(s1[i] - s2[i] != 0 ){
            return s1[i] - s2[i];
        }
        i++;
    }
    if(s1[i] == '\0' && s2[i] != '\0'){
        return -1;
    }
    return 0;
}
