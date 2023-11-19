#include<stdio.h>
int binary_search(int N, int a[10], int key);
void main()
{
	int N, a[10], i, key, l;
	printf("Limit:");
	scanf("%d", &N);

	printf("Input the elements:\n");
	for(i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}	
	printf("Key:");
	scanf("%d", &key);
	if(binary_search(N, a, key) != -1)
	{	printf("Elemnet found at:%d", binary_search(N, a, key));}
	else
	{	printf("Element not found");}
}

int binary_search(int N, int a[10], int key)
{
	int i = 0, j = N-1, mid;
	while(i <= j)
	{
		mid = (i+j)/2;
		if(a[mid] == key)
		{	return mid;}
		else
		if(a[mid] < key)
		{	i = mid + 1;}
		else
		if(a[mid] > key)
		{	j = mid - 1;}
	}
	return -1;	
	
}