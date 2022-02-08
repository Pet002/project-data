#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct nd{
    char c;
    struct nd *next;
}node;

node *top = NULL;


void push(char x){
    node *n = malloc(sizeof(node));
    n->next = top;
    top = n;
    n->c = x;
}

char pop(){
    char p;
    node *n;
    n = top;
    top = top -> next;
    p = n->c;
    free(n);
    return p;
}

char stacktop(){
    if(top == NULL)
        return '\0';
    else
        return top -> c;
}

int checkpr(char temp){
    int pr;
    if(temp == '(')
        return 5;
    else if(temp == '*' || temp == '/'){
        return 2;
    }else{
        return 1;
    }
}


void checkoper(char ck){
    if(stacktop() == '\0' || stacktop() == '('){
        push(ck);
    }
    else{
        if (checkpr(ck) <= checkpr(stacktop()))
        {
            while ( (checkpr(ck) <= checkpr(stacktop())) && stacktop() != '\0' )
            {
                printf("%c ",pop());
            }
            
        }
        push(ck);
    }
    
}

int main(int argc, char const *argv[])
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if(isdigit(ch) || isalpha(ch))
            printf("%c ", ch);
        else if(ch == ')'){
            while (stacktop() != '(')
            {
                printf("%c ", pop());
            }
            pop();
        }
        else
            checkoper(ch);
    }
    while(stacktop() != '\0'){
        printf("%c ", pop());
    }
    
    return 0;
}
