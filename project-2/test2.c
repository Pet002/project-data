#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int edge[26][26];


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

char * addString(char *str1, char *str2){
    char *str_add = (char * )malloc(strlen(str1) + strlen(str2) + 1);

    strcpy(str_add, str1);
    strcat(str_add, str2);

    return str_add;

}


int checkcircuit(char **arr){

    char *ch = arr[0];

    return 0;
}


int main(int argc, char const *argv[])
{
    

    // char * string = "abcdefg";
    // char s1[20];
    // char *s12, *s21;
    // strcpy(s1, string);
    // s12 = substring(s1, 0, 5);
    // printString(s12);
    
    //--------------------------
    
    // char * str;

    // str = addString("aaa", "BBB");

    // printf("%s\n", str);



    memset(edge, 0, 10*10*sizeof(int));

    for (int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++){
            printf("%d ", edge[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


