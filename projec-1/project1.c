#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nd
{
    char c;
    struct nd *next;
} node1;

typedef struct new
{
    double num;
    struct new *next;
}
node2;

node2 *top2 = NULL;

node1 *top = NULL;

// infix to postfix algorithem
void push(char x)
{
    node1 *n = malloc(sizeof(node1));
    n->next = top;
    top = n;
    n->c = x;
}

char pop()
{
    char p;
    node1 *n;
    n = top;
    top = top->next;
    p = n->c;
    free(n);
    return p;
}

char stacktop()
{
    if (top == NULL)
        return '\0';
    else
        return top->c;
}


int checkpr(char temp)
{
    int pr;
    if (temp == '^')
        return 5;
    else if (temp == '*' || temp == '/')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void checkoper(char ck)
{
    if (stacktop() == '\0' || stacktop() == '(')
    {
        push(ck);
    }
    else
    {
        if (checkpr(ck) <= checkpr(stacktop()))
        {
            while ((checkpr(ck) <= checkpr(stacktop())) && stacktop() != '\0' && stacktop() != '(')
            {
                printf("%c ", pop());
            }
        }
        push(ck);
    }
}

void prefixToPostfix()
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (isdigit(ch) || isalpha(ch))
            printf("%c ", ch);
        else if (ch == ')')
        {
            while (stacktop() != '(')
            {
                printf("%c ", pop());
            }
            pop();
        }
        else if(ch == '(')
            push(ch);
        else
            checkoper(ch);
    }
    while (stacktop() != '\0')
    {
        printf("%c ", pop());
    }
}

// postfix to result
void push2(double num)
{
    node2 *n = malloc(sizeof(node2));
    n->next = top2;
    top2 = n;
    n->num = num;
}

double pop2()
{
    node2 *collect;
    double numcol;

    collect = top2;
    top2 = top2->next;
    numcol = collect->num;
    free(collect);
    return numcol;
}

void postToResult(char num)
{
    if (isdigit(num))
    {
        double n = num - '0';
        push2(n);
    }
    else
    {
        double n1 = pop2();
        double n2 = pop2();
        if (num == '+')
            push2(n2 + n1);
        else if (num == '-')
            push2(n2 - n1);
        else if (num == '*')
            push2(n2 * n1);
        else if (num == '/')
            push2(n2 / n1);
    }
}

void postfixToResult()
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        postToResult(ch);
    }
    printf("%.2f", top2->num);
}


void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void reset()
{
    printf("\033[0m");
}

int main(int argc, char const *argv[])
{
    red();
    printf("1 Infix To Postfix Function\n");
    printf("2 Postfix To Result Function\n");
    printf("Enter Your Selection : ");
    char check, invalid;
    scanf("%c" , &check);
    scanf("%c" , &invalid);
    if (check == '1')
    {
        yellow();
        printf("--------------------------------------------\n");
        printf("Your infix is : ");
        char ch;
        int value = 1;
        while (scanf("%c" , &ch) && ch != '\n')
        {
            if(value){
                printf("Your Answer is : ");
                value = 0;
            }
            if (isdigit(ch) || isalpha(ch))
                printf("%c ", ch);
            else if (ch == ')')
            {
                while (stacktop() != '(')
                {
                    printf("%c ", pop());
                }
                pop();
            }
            else
                checkoper(ch);
        }
        while (stacktop() != '\0')
        {
            printf("%c ", pop());
        }
        printf("\n--------------------------------------------\n");

    }
    else if (check == '2')
    {
        yellow();
        printf("--------------------------------------------\n");
        printf("Your postfix is : ");
        char ch;
        while (scanf("%c" , &ch) && ch != '\n')
        {
            postToResult(ch);
        }
        
        printf("Your result is : ");
        printf("%.2f", top2->num);
        printf("\n--------------------------------------------\n");

    }
    else
    {
        reset();
        printf("Incorrect...");
    }
    reset();

    return 0;
}
