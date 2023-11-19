#include<stdio.h>
int linear_search(int a[10], int N, int s);
void main()
{
	int i = 0, N, a[10], s, l;
	printf("Limit:\n");
	scanf("%d", &N);
	printf("Elements:\n");
	for(i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}	
	printf("Key:\n");
	scanf("%d", &s);
	l = linear_search(a, s, N);
	if(l != -1)
	{	printf("Element index:%d", l);}
	else
	{	printf("Not found");}
}

int linear_search(int a[10], int s, int N)
{
	int i = 0;
	for(i = 0; i < N; ++i)
	if(a[i] == s)
	return i;		
	return -1;	
}