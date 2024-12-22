#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
#define BOTTOM -1
 
 char stack[SIZE];
 int top;

void init()
{
	top=BOTTOM;
} 
int isfull()
{
	if(top==SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(top==BOTTOM)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char data)
{
	if(isfull())
	{
	
		top++;
		stack[top]=data;
	}
}
char pop()
{
	char data;
	if(isEmpty())
	{
			
		data=stack[top];
		top--;
		return data;
	}
}

int main()
{
	char str[80];
	int i;

	init();

	printf("Enter string:");
	gets(str);

	for(i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
	printf("Reverse of string :");

	while(! isEmpty())
	{
	printf("%c",pop());
	}
	printf("\n");
	return 0;
}