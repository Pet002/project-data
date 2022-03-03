#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char * substring(char * str , int start, int end){
    int j = 0;
    char * buffer = (char *)malloc(strlen(str) + 1);
    for ( int i = start; i < end; ++i ) {
        buffer[j++] = str[i];
    }
    buffer[j] = '\0';
    return buffer;
}

void printString(char * str){
    for(int i = 0 ; i < strlen(str) ; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    char * string = "abcdefg";
    char s1[20];
    char *s12, *s21;
    strcpy(s1, string);
    s12 = substring(s1, 0, 5);
    printString(s12);
    return 0;
}
