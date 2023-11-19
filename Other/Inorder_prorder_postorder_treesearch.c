#include<stdio.h>
#include<stdlib.h>
int TOP = -1, stack[20];
struct node{
	int data;
	struct node* left;
	struct node* right;
}*parent, *ptr, *temp, *root, *trav;

void insert(struct node *ptr, int key)
{
	char ch;
	if(ptr != NULL)
	{
		ptr->data = key;
		printf("Does %d have a left subtree (Y/N):", ptr->data);
		scanf("%c", &ch);
		if(ch == 'Y')
		{
			parent = malloc(sizeof(struct node));
			ptr->left = parent; 
			printf("Enter the data:");
			scanf("%d", &key); 
			getchar(); 
			insert(parent, key); 
		}	
		else
		{
			parent = NULL; ptr->left = NULL; getchar(); insert(parent, '\0');
		}
		printf("Does %d have a right subtree (Y/N):", ptr->data);
		scanf("%c", &ch);
		if(ch == 'Y')
		{
			parent = malloc(sizeof(struct node));
			ptr->right = parent; 
			printf("Enter the data:");
			scanf("%d", &key); 
			getchar();
			insert(parent, key);
		}	
		else
		{
			parent = NULL; ptr->right = NULL; getchar(); insert(parent, '\0');
		}
	}
}

void inorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		printf("%d ", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->data);
	}
}

int search(struct node **trav, int key)
{
	if((*trav)->data == key)
	{	return 1;	}
	if((*trav) != NULL)
	{
		search((*trav)->left, key);
		search((*trav)->right, key);
	}
	return 0;
}

void delete(struct node *last, int key)
{
	int swap;
	if(last != NULL)
	{
		delete(last->left, key);
		++TOP; stack[TOP] = (int)last;
		delete(last->right, key);
		ptr = (struct node*)stack[TOP]; --TOP; temp = (struct node*)stack[TOP];
		if(ptr->left != NULL || ptr->right != NULL)
		{
			swap = temp->data; temp->data = trav->data; trav->data = swap;
			ptr->left = NULL; free(temp);
		}
		swap = ptr->data; ptr->data = trav->data; trav->data = swap;
		temp->right = NULL; free(ptr);
	}
}


void main()
{
	int op, key;
	while(1)
	{
		printf("\n1.Insert a new node\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Delete a node\nEnter your option:");
		scanf("%d", &op);
		switch(op)
		{
			case 1:	ptr = malloc(sizeof(struct node));
					root = ptr;
					printf("Enter the data:");
					scanf("%d", &key);
					getchar();
					insert(ptr, key); break;
			case 2:	printf("Inorder:\n");
					inorder(root); break;
			case 3: printf("Preorder:\n");
					preorder(root); break;
			case 4: printf("Postorder:\n");
					postorder(root); break;
			case 5: printf("Enter the data:");
					scanf("%d", &key); trav = root;
					if(!search(&trav, key))
					{ printf("Element not found"); break;}
					delete(trav, key);
					printf("%d deleted", key); 
					break;
			default: printf("Invalid input"); break;
		}
	}
}