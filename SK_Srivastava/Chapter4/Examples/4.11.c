// Program for conversion of infix to postfix and evaluation of postfix. It will evaluate only single digit numbers.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push(long int symbol);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space();
char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int main()
{
    long int value;
    top = -1;
    printf("Enter infix: ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix: %s\n", postfix);
    value = eval_post();
    printf("Value of expression: %ld\n", value);
}

void infix_to_postfix()
{
    unsigned int i, p = 0;
    char next, symbol;
    for(i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if(!white_space(symbol))
        {
            switch (symbol)
            {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((next = pop())!= '(')
                        postfix[p++] = next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while(!isEmpty() && priority(stack[top]) >= priority(symbol))
                        postfix[p++] = pop();
                    push(symbol);
                    break;
            
                default: /*if an operand comes*/
                    postfix[p++] = symbol;
            }
        }
    }
    while(!isEmpty())
        postfix[p++] = pop();
    postfix[p] = '\0'; /*End postfix with '\0' to make it a string*/
}

int white_space(char symbol)
{
    if(symbol == BLANK || symbol == TAB)
        return 1;
    else
    {
        return 0;
    }
    
}

int isEmpty()
{
    if(top == -1) /*empty*/
        return 1;
    else
    {
        return 0;
    }
}