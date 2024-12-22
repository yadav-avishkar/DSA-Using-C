
#include<stdio.h>
#include <stdlib.h>
#define SIZE 3
#define BOTTOM -1
 
 int stack[SIZE];
 int top;

void init()
{
	top=BOTTOM;
} 
int isEmpty()
{
	if(top==BOTTOM)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(top==SIZE-1)
		return 1;
	else
		return 0;
}
void push(int data)
{
	if(isfull())
	{
		printf("stack is overflow!!\n");
	}
	else
	{
		top++;
		stack[top]=data;
	}
}
int pop()
{
	int data;
	if(isEmpty())
	{
		printf("Stack is Empty!!");
	}
	else
	{
		data = stack[top];
		top--;
		return data;
	}
}
int peek()
{
	if(isEmpty())
	{
		printf("Stack is Empty!!");
	}
	else
	{
		return stack[top];
	}
}
void display_stack()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d",stack[i]);
	}
	printf("\n");
}
int main()
{
	int choice,data;
	init();
	while(1)
	{
		printf("\n MENU \n 1.ADD \n 2. DELETE \n 3.PEEK \n 4.Display Stack \n 5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			if(isfull())
			{
				printf("\n Stack is full\n");
			}
			else
			{
				printf("\n Enter data to add into the Queue:");
				scanf("%d",&data);
				push(data);
			}
               break;
        case 2 :
        	if(isEmpty())
        	{
        		printf("\n Stack is Empty\n");

        	}
        	else
        	{
        		printf("\n popped element=%d\n",pop());
        	}
        	break;
        case 3 :
        	if(isEmpty())
        	{
        		printf("\n Stack is Empty\n");
        	}
        	else
        	{
        		printf("\n peeked element=%d\n",peek());
        	}
        	break;
        case 4 :
        	if(isEmpty())
        	{
        		printf("\n Stack is Empty\n");
        	}
        	else
        	{
        		display_stack();
        	}
        case 5 :
        	   exit(0);
        default :
        	printf("Invalid choice\n");

		}
	}
	return 0;
}