#include<stdio.h>
#include<string.h>
int start, end;
void LeftOperand(char infix[20], int aug[20], int pos, char operand[10])
{
    int i, j, k;
    char temp;
    for(i = pos - 1, k = 0; i >= start && aug[i] == 1; --i, ++k)
    {
        operand[k] = infix[i];
    }
    for(i = 0, j = k - 1; i <= k/2; ++i, --j)
    {
        temp = operand[i]; operand[i] = operand[j]; operand[j] = temp;
    }
    operand[k] = '\0';
}

void RightOperand(char infix[20], int aug[20], int pos, char operand[10])
{
    int i, k;
    for(i = pos + 1, k = 0; infix[i] != '\0' && aug[i] == 1; ++i, ++k)
    {
        operand[k] = infix[i];
    }
    operand[k] = '\0';
}

void write_converted_exp(char infix[20], int aug[20], int pos, char *left, char op, char *right, int startofsub, int endofsub)
{
    int i, k;
    for(i = startofsub, k = 0; i < pos; ++i, ++k)
    {
        infix[i] = left[k]; 
        aug[i] = 1;
    }
    for(i = pos, k = 0; i <= endofsub; ++i, ++k)
    {
        infix[i] = right[k]; 
        aug[i] = 1;
    }
    infix[i] = op; aug[i] = 1;
}


void main()
{
    int i, j, c = 0;
    char infix[20], operand[10];
    char left[10], right[10];
    int aug[20];
    printf("Infix expression:\n");
    scanf("%s", infix);
    for(i = 0; infix[i] != '\0'; ++i)
    {
        if(infix[i] == '(')
            ++c;
    }
    for(i = 0; infix[i] != '\0'; ++i)
    {
        if(infix[i] >= 48 && infix[i] <= 57 || infix[i] >= 65 && infix[i] <= 90 || infix[i] >= 97 && infix[i] <= 122)
        {
            aug[i] = 1;
        }
        else
        {
            aug[i] = 0;
        }
    } 
    for(j = 0; j < c; ++j){
    for(i = 0; infix[i] != '\0'; ++i)
    {
        if(infix[i] == '(')
        { start = i+1;}
        if(infix[i] == ')')
        { end = i-1;}
    }
    for(i = start; i <= end; ++i)
    {
        if(infix[i] == '^' && aug[i] == 0)
        {
            LeftOperand(infix, aug, i, operand);
            strcpy(left, operand);
            operand[0] = '\0'; 
            RightOperand(infix, aug, i, operand);
            strcpy(right, operand);
            operand[0] = '\0';
            write_converted_exp(infix, aug, i, left, infix[i], right, i - strlen(left)+1, i+strlen(right)-1);
        }
    } 
    for(i = start; i <= end; ++i)
    {
        if((infix[i] == '*' || infix[i] == '/') && aug[i] == 0)
        {
            LeftOperand(infix, aug, i, operand);
            strcpy(left, operand);
            operand[0] = '\0';
            RightOperand(infix, aug, i, operand);
            strcpy(right, operand);
            operand[0] = '\0';
            write_converted_exp(infix, aug, i, left, infix[i], right, i - strlen(left)+1, i+strlen(right)-1);
        }
    }
    for(i = start; i <= end; ++i)
    {
        if((infix[i] == '+' || infix[i] == '-') && aug[i] == 0)
        {
            LeftOperand(infix, aug, i, operand);
            strcpy(left, operand);
            operand[0] = '\0';
            RightOperand(infix, aug, i, operand);
            strcpy(right, operand);
            operand[0] = '\0';
            write_converted_exp(infix, aug, i, left, infix[i], right, i - strlen(left) +1, i+strlen(right)-1);
        }
    }
    infix[start-1] = infix[end+1] = '#'; aug[start-1] = aug[end+1] = 1;}
    printf("Postfix expression:\n"); 
    for(i = 0; infix[i] != '\0'; ++i)
    {
        if(infix[i] != '#')   
           printf("%c", infix[i]);
    }
}