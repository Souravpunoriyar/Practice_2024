#include<stdio.h>
#include<string.h>


void rem_all_dup(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        for(int j=i+1; str[j] != '\0'; j++) {
            if(str[i] == str[j]){
                for(int k = j; str[k] != '\0'; k++) {
                    str[k] = str[k+1];
                }
                
            }
        }
    }
    
}

void rev_word(char *strbeg, char *strend) {
    while(strbeg < strend){
        char temp = *strbeg;
        *strbeg++ = *strend;
        *strend-- = temp;
    }

}


void rev_sent(char * str) {
    rev_word(&str[0], &str[(strlen(str)-1)]);
    printf("[%s] \r\n", str);
    int begin = 0;
    for(int i =0 ; i < strlen(str); i++) {
        if((str[i] == ' ') || (str[i] == '\0')){
            rev_word(&str[begin], &str[i-1]);
            begin = i+1;
        }
    }
    printf("[%s] \r\n", str);
}



int main() {
    char str1[20] = "i love my India";
    char str2[20] = "abcdes";
    //gets(str);
    printf("[%s] \r\n", str2);
    //rem_all_dup(str);
    //rev_word(&str2[0], &str2[(strlen(str2)-1)]);
    rev_sent(str1);



    printf("[%s] \r\n", str2);

    return 0;
}