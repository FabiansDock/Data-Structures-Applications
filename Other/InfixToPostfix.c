#include<stdio.h>
int TOP = -1, TOPe = -1; 
char evaluation[20], stack[20];
void push(char item, char stack[20], int *cTOP)
{
    ++*cTOP; 
    stack[*cTOP] = item;
}

char pop(char stack[20], int *cTOP)
{
    char temp;
    temp = stack[*cTOP];
    --*cTOP;
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
 
int check(char item, char stack[20])
{
    if(item >= 65 && item <= 90 || item >= 97 && item <= 122 || item >= 48 && (int)item <= 57)
    {
        push(item, evaluation, &TOPe);
    }
    else
    if(item == ')')
    {
        while(stack[TOP] != '(')
        {    
            push(stack[TOP], evaluation, &TOPe);
            pop(stack, &TOP);             
        }
        pop(stack, &TOP); 
    }
    else
    if(icp(item) > isp(stack[TOP]))
    {
        push(item, stack, &TOP);
    }
    else
    if(icp(item) < isp(stack[TOP]))
    {
        push(stack[TOP], evaluation, &TOPe);
        pop(stack, &TOP);
        push(item, stack, &TOP);
    }
    else
    {   
        return -1;
    }
    return 0;
}


void main()
{
    int i, j, item;
    char temp;
    char infix[20], x, y;
    printf("Enter the infix exp:\n");
    scanf(" %s", infix); 
    ++TOP;
    stack[TOP] = '(';
    printf("Postfix expression:\n");
    for(i = 0; infix[i] != '\0'; ++i)
    {
        if(check(infix[i], stack))
        {   
            printf("Expression cannot be converted"); 
            return;
        }
    }
    while(stack[TOP] != '(')
    {
        push(stack[TOP], evaluation, &TOPe);
        pop(stack, &TOP);
    }
    stack[0] = '\0'; 
    printf("%s", evaluation);
    for(i = 0, j = TOPe; i <= TOPe/2; ++i, --j)
    {   
        temp = evaluation[i];
        evaluation[i] = evaluation[j];
        evaluation[j] = temp; 
    } 
    // printf("%s", evaluation);
    TOP = -1;
    for(i = TOPe; i >= 0; --i)
    {   
        if(evaluation[i] >= 48 && evaluation[i] <= 57)
        {
            push(evaluation[i], stack, &TOP);
        }
        else
        {   
            switch(evaluation[i])
            {
                case '+':y = pop(stack, &TOP)-'0'; x = pop(stack, &TOP)-'0';
                         push((x+y)+'0', stack, &TOP); break;
                case '-':y = pop(stack, &TOP)-'0'; x = pop(stack, &TOP)-'0';                           
                         push((x-y)+'0', stack, &TOP); break;
                case '/':y = pop(stack, &TOP)-'0'; x = pop(stack, &TOP)-'0';                         
                         push((y/x)+'0', stack, &TOP); break;
                case '*':y = pop(stack, &TOP)-'0'; x = pop(stack, &TOP)-'0';                          
                         push((x*y)+'0', stack, &TOP); break;
                case '^':y = pop(stack, &TOP)-'0'; x = pop(stack, &TOP)-'0';                       
                         push((x^y)+'0', stack, &TOP); break;
                default: break;
            }
        }
    }
    printf("\nValue of expression: %d", pop(stack, &TOP)-'0');
    return;
}