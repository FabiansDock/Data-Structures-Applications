#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node* llink;
	struct node* rlink;
}*head, *ptr, *ptr1, *ptr2;

void initializer(char ch)
{
	ptr1->rlink = ptr;
	ptr->rlink = NULL;
	ptr->llink = ptr1;
	ptr->data = ch;
	ptr1 = ptr;
}

void checker()
{
	ptr2 = head->rlink; 
	while(ptr2 != ptr1)
	{
		if(ptr2->data != ptr1->data)
		{
			printf("Not a palindrome"); return;
		}
		ptr1 = ptr1->llink;
		ptr2 = ptr2->rlink;
	}
	printf("Palindrome"); 
}

void main()
{
	char str[17]; 
	head = malloc(sizeof(struct node));
	if(head == NULL)
	{ printf("Memory allocation error"); exit(0);}
	head->data = '\0';
	head->rlink = NULL;
	head->llink = NULL;
	ptr1 = head;
	printf("Enter the string:");
	scanf(" %[^\n]", str);
	for(int i = 0; str[i] != '\0'; ++i)
	{
		ptr = malloc(sizeof(struct node));
		initializer(str[i]);
	}
	checker();
	free(head);
	free(ptr);
}