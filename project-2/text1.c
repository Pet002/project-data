#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//value declear
char node[26];
int sum = 0;

//**input Testcase : when we need input data
// int numOfNode = 0;
// int edge[26][26];




//**testcase 1 : Euler circuit;
int numOfNode = 7;
int edge[26][26] = {
                    {0, 1, 1, 0, 1, 1, 0},
                    {1, 0, 0, 1, 1, 1, 0},
                    {1, 0, 0, 1, 1, 0, 1},
                    {0, 1, 1, 0, 1, 0, 1},
                    {1, 1, 1, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0, 0, 0}
                 };



//**testcaste2 : semi Euler circuit;
// int numOfNode = 6;
// int edge[6][6] = {
//                     {0, 1, 1, 0, 1, 1},
//                     {1, 0, 0, 1, 1, 1},
//                     {1, 0, 0, 1, 1, 0},
//                     {0, 1, 1, 0, 1, 0},
//                     {1, 1, 1, 1, 0, 0},
//                     {1, 1, 0, 0, 0, 0}
//                 };


//**testcase3 : non-Euler circuit;
// int numOfNode = 5;
// int edge[5][5] = {
//                     {0, 1, 1, 0, 1},
//                     {1, 0, 0, 1, 1},
//                     {1, 0, 0, 1, 1},
//                     {0, 1, 1, 0, 1},
//                     {1, 1, 1, 1, 0}
//                 };


//**testcase4 : non-Euler circuit
// int numOfNode = 6;
// int edge[6][6]={
//                 {0, 1, 1, 0, 0, 0},
//                 {1, 0, 1, 0, 0, 0},
//                 {1, 1, 0, 0, 0, 0},
//                 {0, 0, 0, 0, 1, 1},
//                 {0, 0, 0, 1, 0, 1},
//                 {0, 0, 0, 1, 1, 0}
// };





void printNode(){
    
    for(int i = 0 ; i < sizeof(node) ; i++){
        printf("%c " , node[i]);
    }
    printf("\n");
}

void addNode(int numOfNode){
    for(int i = 0; i < numOfNode; i++){
        node[i] = 65 + i;
    }
}

int SumofVertical(){
    for(int i = 0 ; i < numOfNode; i++){
        for(int j = 0; j < numOfNode ; j++){
            if(edge[i][j] == 1){
                sum++;
            }
        }
    }
    return sum;

}


char *findSubCircuit(){
    char circuit[20] = "";
    int i = 0, j = 0, locationCircuit = 0 , locationindex = 1;

    int check = 0;

    while(i < numOfNode && j < numOfNode && locationindex != numOfNode && sum != 0 && ( !(check) ||  circuit[0] != circuit[locationCircuit - 1] ) ){
        
        if(edge[i][j] == 1){
            edge[i][j] = 0;
            edge[j][i] = 0;
            if(strlen(circuit) == 0){
                circuit[locationCircuit++] = node[i];
                check = 1;
            }
            
            circuit[locationCircuit++] = node[j];
            i = j;
            j = 0;
            sum -= 2;
        }else{
            j++;
            if(j == numOfNode){
                i = locationindex++;
                j = 0;
            }
        }
        
    }

    if( !(strlen(circuit)) || circuit[0] != circuit[locationCircuit - 1]){
        return NULL;
    }else{
        char *dest = (char *)malloc(strlen(circuit) + 1);
        strcpy(dest , circuit);
        
        return dest;
    }
    

    
}


void printVertical(){
    for (int i = 0; i < numOfNode; i++)
    {
        for(int j = 0; j < numOfNode; j++){
            printf("%d " , edge[i][j]);
        }
         printf("\n");
    }
    
}


char **getAllCircuit(){
    int i = 0, nullCheck = 1;
    char **result = malloc(sizeof(char *) * 50);
    while (sum != 0)
    {
        char * x = findSubCircuit();
        result[i] = malloc(sizeof(char ) * (30 + 1));
        if(x != NULL){
            strcpy(result[i], x);
            free(x);
        }else{
            result[i] = NULL;
            nullCheck = 0;
        }
        i++;
    }
    if(nullCheck){
        result[i] = malloc(sizeof(char ) * (10 + 1));
        result[i] = NULL;
    }
    
    

    return result ;
}


int checkcircuit(char **arr){
    int x = 0, circuit_check = 0;
    for(int i = 0 ; arr[i] != NULL ;i++ ){
        circuit_check++;
    }

    for(int i = 1; arr[i] != NULL; i++){
        for(int j = 0; j < strlen(arr[0]) ; j++){
            if(arr[0][j] == arr[i][0]){
                x++;
            }
        }
    }
    // printf("DEBUG CIRCUIR = %d    |    DEBUG x = %d \n" , circuit_check, x);

    if(circuit_check != x){
        return 0;
    }else{
        return 1;
    }

    
}

char *add_string_location(char * strin1, char *strin2, int location){

    char * str = (char *)malloc(strlen(strin1) + strlen(strin2) + 1);
    char sss[40] = "";
     strcpy(str, (char[1]){'\0'} );
    for (int i = 0; i < location; i++){
        strcat(str, (char[2]){strin1[i] , '\0' });
    }
    strcat(str, strin2);
    for(int i = location + 1; i < strlen(strin1); i++){
        strcat(str, (char[2]){strin1[i] , '\0' });
    }
    
    // printf("%s\n", str);

    return str;
    

}

char *connectCitcuit(char **arr, int value){
    char * result = (char *)malloc(value + 1);
    result = arr[0];
    for(int i = 1; arr[i] != NULL ; i++){
        for(int j = 0; j < strlen(result); j++){
            if(arr[i][0] == result[j]){
                // printf("\ni = %d , j = %d \n", i, j);
                result = add_string_location(result, arr[i], j);
                break;
            }
        }
    }
    
    // printf("%s", result);

    return result;

}





int main(int argc, char const *argv[])
{   
    // int a = 10 , b = 10;
    // int length = 10;

    // printf("");

    // int edge[length][length];
    // memset(edge , 0, length*length*sizeof(int));
    // char k = 65;
    


    //=======================================================
    printVertical();
    printf("-------------------------------\n" );
    addNode(numOfNode);
    printNode(node);
    SumofVertical();
    //to save data of vertical
    int valueVertical = sum/2;
    int getValueVertical = 0;
    
    
    
    char **arr = getAllCircuit();

    

    for (int i = 0; arr[i] != NULL ; i++)
    {
        getValueVertical = getValueVertical + strlen(arr[i]) - 1;
        printf("%s\n" , arr[i]);
    }
    printf("===================================\n");

    for (int i = 0; arr[i] != NULL ; i++)
    {
        for(int j = 0; j < strlen(arr[i]); j++){
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    

    printf("Vertical value = %d\nSum = %d\n" , getValueVertical, valueVertical);
    


    if(getValueVertical == valueVertical && checkcircuit(arr)){
        printf("Is Euler Circuit = ");

        // add_string_location(arr[0], arr[2], 3);
        char *euler_Citcuit = connectCitcuit(arr, getValueVertical);
        printf("%s\n" , euler_Citcuit);
    }else{
        printf("Is non-Euler Circuit");
    }
    printf("\n");

    // printVertical();




    //================================================================
    // printf("%c\n" ,k);

    // print2DArray(edge);
    return 0;
}



