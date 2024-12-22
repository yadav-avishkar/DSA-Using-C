#include<stdio.h>


#define SIZE 10
#define Q_SIZE 100

int Q[Q_SIZE];
int rear,front;

int G[SIZE][SIZE];
int nov;
int noe;

int visited[SIZE];

void init_Q()
{
	rear=-1;
	front=-1;
}
int isFull()
{
 	if(rear == Q_SIZE-1)
 		return 1;
 	else
 		return 0;
}
int isEmpty()
{
 	if(front == rear)
 		return 1;
 	else
 		return 0;
}
void addQ(int item)
{
	if(isFull())
	{
		printf("Queue is Full !!\n");
	}
	else
	{
		rear++;
		Q[rear]=item;
	}
}
int delQ()
{
	if(isEmpty())
	{
		return -1;
	}
	else
	{
		front ++;
		return Q[front];
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
		printf("Enter Edge (vi,vj):");
		scanf("%d%d",&i,&j);
		G[i][j]=1;
		G[j][i]=1;
	}
}
void display()
{
	int i,j;
	printf("\nAdjacency Matrix\n");
	printf("\nAdjacency Matrix\n");

	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
		{
			printf("%d",G[i][j]);
		}
		printf("\n");
	}
}
void bfs(int start)
{
	int i,j;
	printf("\n BFS :");
	addQ(start);

	while(!isEmpty())
	{
		i=delQ();

		if(visited[i]==0)
		{
			printf("%d",i);
			visited[i]=1;
		}
		for(j=0;j<nov;j++)
		{
			if(G[i][j]==1 && visited[j]==0)
			{
				addQ(j);
			}
		}
	}
	printf("\n");
}
int main()
{
	int start;
	accept();
	display();
	int_Q();

	printf("\nEnter starting Vertex:");
	scanf("%d",&start);

	bfs(start);
}