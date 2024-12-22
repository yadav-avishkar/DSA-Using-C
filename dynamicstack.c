#include<stdio.h>
#include<stdlib.h>
#define BOTTOM NULL

#define NEWNODE (struct node*)malloc(sizeof(struct node))
 
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *top;
 
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

void push(int data)
{
	struct node *t;
	t=NEWNODE;

	if(t==NULL)
	{
		printf("\nStack is full !!\n");
		return;
	}

	t-> data=data;
	t->prev=NULL;
	t->next=NULL;

	if(top=BOTTOM)
	{
		top=t;
		
	}
	else
	{
		top->next=t;
		t->prev=top;
		top=top->next;
	}
}
int pop()
{
	struct node *t;
	int data;

	if(!isEmpty())
	{
		data=top->data;
		t=top;
		top=top->prev;

		free(t);

		if(top!=NULL)
		{
			top->next=NULL;
		}
		return data;
	}
}
int peek()
{
	if(! isEmpty())
	{
		return top->data;
	}
}
int main()
{
	int choice,data;

	init();

	while(1)
	{
		printf("\n MENU \n 1.PUSH \n 2. POP \n 3.PEEK \n 4.EXIT \n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
						
				printf("\n Enter data to push:");
				scanf("%d",&data);
				push(data);
				printf("Pushed successfully!!\n");
			    break;
        case 2 :
        	if(isEmpty())
        	{
        		printf("\n Stack is Empty\n");

        	}
        	else
        	{
        		data=pop();
        		printf("\n Popped element=%d\n",data);
        	}
        	break;
        case 3 :
        	if(isEmpty())
        	{
        		printf("\nStack is Empty\n");
            }
        	else
        	{
        		data=peek();
        		printf("\n Topmost element=%d\n",data);
        	}
        	break;
        case 4 :
        	exit(0);
        default :
        	printf("Invalid choice\n");

		}
	}
	return 0;
}