#include<stdio.h>
int sTOP = -1;
void push(char item, char stack[20], int *TOP)
{
    ++*TOP; 
    stack[*TOP] = item;
}

char pop(char stack[20])
{
    char temp;
    temp = stack[sTOP];
    --sTOP;
    return temp;
}

int isp(char item)
{
    if(item == '+' || item == '-')
        return 2;
    if(item == '*' || item == '/')
        return 4;
    if(item == '^')
        return 5;
    if(item == '(')
        return 0;
    return -1;
}

int icp(char item)
{
    if(item == '+' || item == '-')
        return 1;
    if(item == '*' || item == '/')
        return 3;
    if(item == '^')
        return 6;
    if(item == '(')
        return 7;
    if(item == ')')
        return 0;
    return -1;
}

int check(char item,char stack[20])
{   
    if(item >= 65 && item <= 90 || item >= 97 && item >= 122 || (int)item >= 0 && (int)item <= 9)
    {
        printf("%c", pop(stack));
    }
    else
    if(item == ')')
    {
        while(stack[sTOP] != '(')
        {    
            printf("%c", pop(stack));             
        }
        pop(stack);
    }
    else
    if(icp(item) > isp(stack[sTOP]))
    {
        push(item, stack, &sTOP);
    }
    else
    if(icp(item) < isp(stack[sTOP]))
    {
        printf("%c", pop(stack));
        push(item, stack, &sTOP);
    }
    else
    {   
        return -1;
    }
    return 0;
}

void main()
{
    int i, j, rTOP = -1;
    char temp;
    char infix[20], rinfix[20], stack[20];
    printf("Enter the infix exp:\n");
    scanf(" %s", infix);
    for(i = 0; infix[i] != '\0'; ++i)
    {
        if(infix[i] == '(')
        {   push(')', rinfix, &rTOP); continue;}
        if(infix[i] == ')')
        {    push('(', rinfix, &rTOP); continue;}
        push(infix[i], rinfix, &rTOP);
    }
    for(i = 0, j = rTOP; i <= rTOP/2; ++i, --j)
    {   
        temp = rinfix[i];
        rinfix[i] = rinfix[j];
        rinfix[j] = temp; 
    } 
    push('(', stack, &sTOP);
    for(i = 0; i <= rTOP; ++i)
    {
        if(check(rinfix[i], stack))
        {   
            printf("Expression cannot be converted"); 
            return;
        }
    }
    while(stack[sTOP] != '(')
    {
        printf("%c", pop(stack));
    }
    return;
}