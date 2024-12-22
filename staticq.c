#include<stdio.h>
#include <stdlib.h>
#define SIZE 5
#define START -1
 
 int Q[SIZE],front,rear;
void init()
{
	front=START;
	rear=START;

} 
int isEmpty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(rear==SIZE-1)
		return 1;
	else
		return 0;
}
void addQ(int data)
{
	if(!isfull())
	{
		rear++;
		Q[rear]=data;
		printf("Data is added Succesfully into the Queue\n");
	}
}
int delQ()
{
	if(!isEmpty())
	{
		front ++;
		return Q[front];
	}
}
int peek()
{
	if(! isEmpty())
	{
		return Q[front+1];
	}
}
int main()
{
	int choice,data;
	init();
	while(1)
	{
		printf("\n MENU \n 1.ADD \n 2. DELETE \n 3.PEEK \n 4.EXIT \n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			if(isfull())
			{
				printf("\n Queue is full\n");
			}
			else
			{
				printf("\n Enter data to add into the Queue:");
				scanf("%d",&data);
				addQ(data);
			}
               break;
        case 2 :
        	if(isEmpty())
        	{
        		printf("\n Queue is Empty\n");

        	}
        	else
        	{
        		data=delQ();
        		printf("\n Deleted element=%d\n",data);
        	}
        	break;
        case 3 :
        	if(isEmpty())
        	{
        		printf("\n Queue isEmpty\n");
        	}
        	else
        	{
        		data=peek();
        		printf("\n front element=%d\n",data);
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