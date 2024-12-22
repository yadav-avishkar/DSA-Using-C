#include<stdio.h>
#define SIZE 10

#define BOTTOM -1
#define S_SIZE 100

int stack[S_SIZE];
int top;

int G[SIZE][SIZE];
int nov;
int noe;

int visited[SIZE];

void init_stack()
{
	top=BOTTOM;
}
int isfull()
{
	if(top==S_SIZE-1)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(top==BOTTOM)
		return 1;
	else 
	    return 0;
}
void push(int item)
{
	if(isfull())
	{
		printf("Stack is Full !!\n");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
int pop()
{
	int item;

	if(isEmpty())
	{
		return 1;
	}
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}
int peek()
{
	if(isEmpty())
	{
		return -1;
	}
	else
	{
		return stack[top];
	}
}
void accept()
{
	int i,j,k;
	printf("How many Vertices :");
	scanf("%d",&nov);

	printf("How many Edges :");
	scanf("%d",&noe);

	for(k=1;k<=noe;k++)
	{
		printf("Enter Edge (vi, vj):");
		scanf("%d%d",&i,&j);

		G[i][j]=1;

		G[j][i]=1;
	}
}
void display()
{
	int i,j;
	printf("\n Adjacency Matrix\n");

	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
		{
			printf("%d",G[i][j]);
		}
		printf("\n");
	}
}
void dfs(int start)
{
	int i,j,status;
	printf("\n DFS[Start V%d]:",start);
	printf("%d",start);

	visited[start]=1;
	push(start);

	while(!isEmpty())
	{
		i=peek();
		status=0;
		for(j=0;j<nov;j++)
		{
			if(G[i][j] == 1 && visited[j] == 0)
			{
				printf("%d",j);
				visited[j]=1;
				push(j);
				status=1;
				break;
			}
		}
		if(status == 0)
		{
			pop();
		}
	}
	printf("\n");
}
int main()
{
	int start;
	accept();
	display();
	init_stack();

	printf("\nEnter Starting Vertex :");
	scanf("%d",&start);
	dfs(start);
}