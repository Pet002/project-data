#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//value declear
char node[26];
int sum = 0;


//**testcase 1 : Euler circuit;
// int numOfNode = 7;
// int edge[7][7] = {
//                     {0, 1, 1, 0, 1, 1, 0},
//                     {1, 0, 0, 1, 1, 1, 0},
//                     {1, 0, 0, 1, 1, 0, 1},
//                     {0, 1, 1, 0, 1, 0, 1},
//                     {1, 1, 1, 1, 0, 0, 0},
//                     {1, 1, 0, 0, 0, 0, 0},
//                     {0, 0, 1, 1, 0, 0, 0}
//                  };



//**testcaste2 : semi Euler circuit;
int numOfNode = 6;
int edge[6][6] = {
                    {0, 1, 1, 0, 1, 1},
                    {1, 0, 0, 1, 1, 1},
                    {1, 0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 1, 0},
                    {1, 1, 1, 1, 0, 0},
                    {1, 1, 0, 0, 0, 0}
                };


//**testcase3 : non-Euler circuit;
// int numOfNode = 5;
// int edge[5][5] = {
//                     {0, 1, 1, 0, 1},
//                     {1, 0, 0, 1, 1},
//                     {1, 0, 0, 1, 1},
//                     {0, 1, 1, 0, 1},
//                     {1, 1, 1, 1, 0}
//                 };




void print2DArray(int twoDArray[10][10]){

    printf("%d", twoDArray[0][0]);

}

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

int main(int argc, char const *argv[])
{   
    // int a = 10 , b = 10;
    // int length = 10;

    // printf("");

    // int edge[length][length];
    // memset(edge , 0, length*length*sizeof(int));
    // char k = 65;
    



    printVertical();
    printf("-------------------------------\n" );
    addNode(numOfNode);
    printNode(node);
    SumofVertical();
    //to save data of vertical
    int valueVertical = sum;
    int getValueVertical = 0;
    
    
    
    char **arr = getAllCircuit();

    for (int i = 0; arr[i] != NULL ; i++)
    {
        getValueVertical = getValueVertical + strlen(arr[i]) - 1;
        printf("%s\n" , arr[i]);
    }

    printf("Vertical value = %d\nSum = %d\n" , getValueVertical, valueVertical/2);
    
    if(getValueVertical == valueVertical/2){
        printf("Is Euler Circuit");
    }else{
        printf("Is non-Euler Circuit");
    }
    printf("\n");

    // char * circuit = findSubCircuit();
    // printf("circuit = %s\n" , circuit);
    // free(circuit);
    
    

    // circuit = findSubCircuit();
    // printf("circuit2 = %s\n" , circuit);
    
    // free(circuit);
    
    // circuit = findSubCircuit();
    // printf("circuit3 = %s\n" , circuit);
    // free(circuit);
    


    printVertical();
    // printf("%c\n" ,k);

    // print2DArray(edge);
    return 0;
}



