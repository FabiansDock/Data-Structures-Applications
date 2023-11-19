#include<stdio.h>
void tuple(int m, int n, int tuple[m*n+1][3], int matrix[10][10])
{
    int i, j, k = 1;
    tuple[0][0] = m; tuple[0][1] = n; tuple[0][2] = m*n;
    for(i = 0; i < m; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            tuple[k][0] = i;
            tuple[k][1] = j;
            tuple[k][2] = matrix[i][j]; ++k;
        }
    }
}

void transpose(int m, int n, int tuple[m*n+1][3])
{
    int i, j, k, swap, swaper[3];
    for(i = 1; i < m*n+1; ++i)
    {
        swap = tuple[i][0];
        tuple[i][0] = tuple[i][1];
        tuple[i][1] = swap;
    }
    for(i = 1; i < m*n+1; ++i)
    {
        for(j = 1; j < m*n+1-i; ++j)
        {
            if(tuple[j][0] > tuple[j+1][0])
            {
                for(k = 0; k < 3; ++k)
                    swaper[k] = tuple[j][k];
                for(k = 0; k < 3; ++k)
                    tuple[j][k] = tuple[j+1][k];
                for(k = 0; k < 3; ++k)
                    tuple[j+1][k] = swaper[k];
            }else
            if(tuple[j][0] == tuple[j+1][0] && tuple[j][1] > tuple[j+1][1])
            {
                for(k = 0; k < 3; ++k)
                    swaper[k] = tuple[j][k];
                for(k = 0; k < 3; ++k)
                    tuple[j][k] = tuple[j+1][k];
                for(k = 0; k < 3; ++k)
                    tuple[j+1][k] = swaper[k];
            }
        }
    }
}

void display(int m, int n, int tuple[m*n+1][3])
{
    int i, j;
    for(i = 0; i < m*n+1; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            printf("%d ", tuple[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i, j, k = 1, m1, m2, n1, n2, matrix1[10][10], matrix2[10][10];
    printf("Normal forms\n----------------\nOrder 1:");
    scanf("%d %d", &m1, &n1);
    int tuple1[m1*n1+1][3];
    printf("Enter Matrix 1\n");
    for(i = 0; i < m1; ++i)
    {
        for(j = 0; j < n1; ++j)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    tuple(m1, n1, tuple1, matrix1);
    printf("\n-------------------\n");
    printf("Order 2:");
    scanf("%d %d", &m2, &n2);
    int tuple2[m2*n2+1][3];
    printf("Enter Matrix 2\n");
    for(i = 0; i < m2; ++i)
    {
        for(j = 0; j < n2; ++j)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    tuple(m2, n2, tuple2, matrix2);
    printf("\nTuple forms\n-----------------");
    printf("\nMatrix 1\n");
    display(m1, n1, tuple1);
    printf("-----------------");
    printf("\nMatrix 2\n");
    display(m2, n2, tuple2);
    transpose(m1, n1, tuple1);
    transpose(m2, n2, tuple2);
    printf("\nTransform\n----------------");
    printf("\nMatrix 1\n");
    display(m1, n1, tuple1);
    printf("-----------------");
    printf("\nMatrix 2\n");
    display(m2, n2, tuple2);
    transpose(m1, n1, tuple1);
    transpose(m2, n2, tuple2);
    if(m1 == m2 && n1 == n2)
    {
        for(i = 1; i < m1*n1+1; ++i)
        {
            tuple1[i][2] += tuple2[i][2];
        }
    }
    printf("\nSum of the matrices(tuple form)\n----------------");
    printf("\nMatrix sum\n");
    display(m1, n1, tuple1);
}