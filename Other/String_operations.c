#include<stdio.h>
#include<string.h>
int StringLength(char *);
void StringCopy(char *, char *);
void StringConcatination(char *, char *, char *);

int StringComparison(char *, char *);
void main()
{
	int s;
	char s1[10], s2[10], s3[20];
	
	  
		printf("1.string length\n2.string copy\n3.string compare\n4.string concatination\n5.Exit\nEnter option:\n");
		scanf("%d",&s);
		switch(s)
		{
		case 1: printf("String:\n");
				scanf(" %s", s1);
				printf("%d", StringLength(s1)); break;
		case 2: printf("String:\n");
				scanf("%s", s2);
				StringCopy(s1, s2);
				printf("Copied string:");
				puts(s1);		break;
		case 3: printf("String 1:\n");
				scanf(" %[^\n]", s1);
				printf("Enter sring 2:\n");
				scanf(" %[^\n]", s2);
				if(StringComparison(s1, s2) == 0)
				{ printf("Equal strings\n");}
				else
				{ printf("Unequal strings\n");} break;
		case 4: printf("String 1:\n");
				scanf(" %[^\n]", s1);
				printf("String 2:\n");
				scanf(" %[^\n]", s2);
				StringConcatination(s1, s2, s3);
				puts(s3); break;
		case 5: return;
		default: printf("Invalid input\n"); break;
		}
	
}

int StringLength(char *s)
{
	int c = 0;
	while(*s++ != '\0')
	{
		++c; 
	}	
	return c;
}

void StringCopy(char *s1, char *s2)
{
	while(*s2++ != '\0')
	{
		*s1 = *s2;
		s1++;
	}	
}

int StringComparison(char *s1, char *s2)
{
	while(*s1++ != '\0' && *s2++ != '\0')
	{
		if(*s1 != *s2)
			return *s1-*s2;
	}	
}

void StringConcatination(char *s1, char *s2, char *s3)
{
	while(*s1 != '\0')	
	{	*s3 = *s1; ++s1; ++s3;}
	while(*s2 != '\0')
    {		*s3 = *s2;	++s3; ++s2;}
}