#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void slice_str(const char * str, char * buffer, size_t start, size_t end);

// void slice_concat_str (char * str , char *catstr, char * output, int location){
//     int j = 0;
    
//     for(int i = 0; i < location ; i++){
//         output[j++] = str[i];
//     }
//     for(int i = 0 ; i < strlen(catstr); i++ ){
//         output[j++] = catstr[i];
//     }
//     for(int i = location + 1; i <= strlen(str); i++){
//         output[j++] = str[i];
//     }

//     output[j] = '\0';
    
// }

char node [] = "ABCDEF";
int vertical[50][50] ={
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {1,1,0,0,0,0},
        {0,0,0,0,1,1},
        {0,0,0,1,0,1},
        {0,0,0,1,1,0}
    }; 




int main(int argc, char const *argv[])
{
    /* code */
    char circuit[2][50] = {"", ""}; 

    int i=0, j = 0;
    int locationstringc = 0;
    int check = 0;


    while(i < strlen(node)){
        while(j < strlen(node) ){
            if(vertical[i][j] == 1 ){
                vertical[i][j] = 0;
                vertical[j][i] = 0;
                check = 1;
                if(strlen(circuit[0]) == 0){
                    circuit[0][locationstringc++] = node[i];
                    circuit[0][locationstringc++] = node[j];
                }else{
                    circuit[0][locationstringc++] = node[j];
                }

                break;
            }
            j++;
        }
        if(check){
            i = j;
            check = 0;
        }else{
            i++;
        }
        if(circuit[0][0] == circuit[0][strlen(circuit[0]) - 1] && strlen(circuit[0]) != 0 ){
            break;
        }
        j = 0;
            
    }

    printf("%s\n", circuit[0]);
    
    i=0, j = 0;
    locationstringc = 0;
    check = 0;


    while(i < strlen(node)){
        while(j < strlen(node) ){
            if(vertical[i][j] == 1 ){
                vertical[i][j] = 0;
                vertical[j][i] = 0;
                check = 1;
                if(strlen(circuit[1]) == 0){
                    circuit[1][locationstringc++] = node[i];
                    circuit[1][locationstringc++] = node[j];
                }else{
                    circuit[1][locationstringc++] = node[j];
                }

                break;
            }
            j++;
        }
        if(check){
            i = j;
            check = 0;
        }else{
            i++;
        }
        if(circuit[1][0] == circuit[1][strlen(circuit[1]) - 1] && strlen(circuit[1]) != 0){
            break;
        }
        j = 0;
            
    }
    
    printf("%s\n", circuit[1]);





    return 0;
}





void slice_str(const char * str, char * buffer, size_t start, size_t end)
{
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        buffer[j++] = str[i];
    }
    buffer[j] = '\0';
}