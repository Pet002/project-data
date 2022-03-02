#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//value declear
char node[26];

int numOfNode = 7;
int sum = 0;
int edge[7][7] = {
                                    {0, 1, 1, 0, 1, 1, 0},
                                    {1, 0, 0, 1, 1, 1, 0},
                                    {1, 0, 0, 1, 1, 0, 0},
                                    {0, 1, 1, 0, 1, 0, 0},
                                    {1, 1, 1, 1, 0, 0, 0},
                                    {1, 1, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0}
                                };


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
        return "00";
    }else{
        char *dest = (char *)malloc(strlen(circuit) + 1);
        strcpy(dest , circuit);
        return dest;
    }
    

    
}



int main(int argc, char const *argv[])
{   
    // int a = 10 , b = 10;
    // int length = 10;

    // printf("");

    // int edge[length][length];
    // memset(edge , 0, length*length*sizeof(int));
    // char k = 65;
    




    addNode(numOfNode);
    printNode(node);
    SumofVertical();
    char * circuit = findSubCircuit();
    printf("circuit = %s\n" , circuit);
    free(circuit);
    circuit = findSubCircuit();
    printf("circuit2 = %s\n" , circuit);
    free(circuit);
    circuit = findSubCircuit();
    printf("circuit3 = %s" , circuit);
    if(circuit == NULL){
        free(circuit);
    }

    // printf("%c\n" ,k);

    // print2DArray(edge);
    return 0;
}



