#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define NEWNODE (struct node*) malloc(sizeof(struct node))
#define START NULL 

struct node
{
	int data;
	struct node*next;
};
struct node *front,*rear;
 
void init()
{
	front=START;
	rear=START;

} 
int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void addQ(int num)
{
	struct node *t;
	t=NEWNODE;
	if(t==NULL)
	{
		printf("Queue is Overflow !!");
		return;
	}
	t-> data=num;
	t->next=NULL;
	if(rear==NULL)
	{
		front=t;
		rear=t;
	}
	else
	{
		rear->next=t;
		rear=rear->next;
	}
}
int delQ()
{
	struct node *t;
	int num;

	if(!isEmpty())
	{
		num=front->data;
		if(front->next==NULL)
		{
			free(front);
			front=rear=NULL;
			return num;
		}
		t=front;
		front=front ->next;
		free(t);
		return num;
	}
}
int peek()
{
	if(! isEmpty())
	{
		return front->data;
	}
}
int main()
{
	int choice,num;
	init();
	while(1)
	{
		printf("\n MENU \n 1.ADD \n 2. DELETE \n 3.PEEK \n 4.EXIT \n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			{			
				printf("\n Enter data to add into the Queue:");
				scanf("%d",&num);
				addQ(num);
				printf("Data is Added in queue successfully!!\n");
			}
               break;
        case 2 :
        	if(isEmpty())
        	{
        		printf("\n Queue is Empty\n");

        	}
        	else
        	{
        		num=delQ();
        		printf("\n Deleted element=%d\n",num);
        	}
        	break;
        case 3 :
        	if(isEmpty())
        	{
        		printf("\n Queue isEmpty\n");
        	}
        	else
        	{
        		num=peek();
        		printf("\n front element=%d\n",num);
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