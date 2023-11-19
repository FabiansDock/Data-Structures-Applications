#include<stdio.h>
int smallestnumber(int *, int );
void main()
{
    int n, a[10];
	printf("Limit:");
	scanf("%d", &n);
	printf("Elements:");
	for(int i = 0; i < n; ++i) 
	{
		scanf("%d", &a[i]);
	}
	printf("Smallest no.:%d", smallestnumber(a, n));
}

int smallestnumber(int *p, int n)
{
	int i = 0, small = *(p + i);
	for(i = 0; i < n; ++i)
	{
		if(*(p+i) < small)
		{	
			small = *(p + i);
		}
	}	
	return small;
}
