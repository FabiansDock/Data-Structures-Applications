#include<stdio.h>
struct polynomial{
    int coeff;
    int exp;
}p1[10], p2[10], r[10];


void main()
{
    int i, j, k1 = 0, k2 = 0, k = 0;
    char exp1[20], exp2[20];
    printf("Input\n");
    printf("\tPolynomial 1:");
    scanf("%s", exp1);
    printf("\tPolynomial 2:");
    scanf("%s", exp2);
    for(i = 0; exp1[i] != '\0'; ++i)
    {
        if(exp1[i] == 'x')
        {
            if(exp1[i-2] == '-')
            {p1[k1].coeff = -(exp1[i-1]-'0');}
            else
            {p1[k1].coeff = (exp1[i-1]-'0');}
            p1[k1].exp = (exp1[i+1]-'0'); 
            ++k1;
        }
        if(exp1[i+1] == '\0' && exp1[i-1] != 'x')
        {
            if(exp1[i-1] == '-')
            {p1[k1].coeff = -(exp1[i]-'0');}
            else
            {p1[k1].coeff = exp1[i]-'0';}
            p1[k1].exp = 0;
            ++k1;
        }
    } 
    
    for(i = 0; exp2[i] != '\0'; ++i)
    {
        if(exp2[i] == 'x')
        {
            if(exp2[i-2] == '-')
            {p2[k2].coeff = -(exp2[i-1]-'0');}
            else
            {p2[k2].coeff = exp2[i-1]-'0';}
            p2[k2].exp = exp2[i+1]-'0';
            ++k2;
        }
        if(exp2[i+1] == '\0' && exp2[i-1] != 'x')
        {
            if(exp1[i-1] == '-')
            {p2[k2].coeff = -(exp2[i]-'0');}
            else
            {p2[k2].coeff = exp2[i]-'0';}
            p2[k2].exp = 0;
            ++k2;
        }
    }
    i = j = 0;
    while(i < k1 && j < k2)
    {
        if(p1[i].exp > p2[j].exp)
        {
            r[k].exp = p1[i].exp;
            r[k].coeff = p1[i].coeff; ++k; ++i;
        }
        else
        if(p1[i].exp < p2[j].exp)
        {
            r[k].exp = p2[j].exp;
            r[k].coeff = p2[j].coeff; ++k; ++j;
        }
        else
        {
            r[k].exp = p2[j].exp;
            r[k].coeff = p1[i].coeff + p2[j].coeff; 
            ++k; ++j; ++i;
        }
    }
    while(i < k1)
    {
        r[k].exp = p1[i].exp;
        r[k].coeff = p1[i].coeff; ++k; ++i; 
    }
    while(j < k2)
    {
        r[k].exp = p2[j].exp;
        r[k].coeff = p2[j].coeff; ++k; ++j; 
    }
    printf("Result\n");
    for(i = 0; i < k; ++i)
    {
        if(r[i].exp != 0 && r[i].coeff != 0)
        {
            if(r[i+1].coeff >= 0 && i < k-1)
                printf("%dx%d+", r[i].coeff, r[i].exp);
            else
                printf("%dx%d", r[i].coeff, r[i].exp);
        }
        else
        if(r[i].coeff != 0)
        {printf("%d", r[i].coeff);}
    }
}