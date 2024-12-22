#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define NEWNODE (struct node *)malloc(sizeof(struct node))
                       
struct node
{
	int vertex;
	struct node *next;
};
struct node *AList[SIZE],*IAList[SIZE];
int nov;
int noe;

void init(struct node *L[])
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		L[i]=NULL;
	}
}
void add_in_list(struct node *L[], int i, int v)
{
	struct node *t,*l;

	t=NEWNODE;
	t->vertex=v;
	t->next=NULL;

	if(L[i]==NULL)
	{
		L[i]=t;
	}
	else
	{
		t->next=L[i];
		L[i]=t;
	}
}
void free_list(struct node *L[])
{
	int i;
	struct node *s,*t;

	for(i=0;i<nov;i++)
	{
		s=L[i];
		 while(s!=NULL)
		 {
		 	t=s;
		 	s=s->next;
		 	free(t);
		 }
		 L[i]=NULL;
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

		add_in_list(AList,i,j);
		add_in_list(IAList,j,i);
	}
}
void display(struct node *L[])
{
	int i;
	struct node *t;

	for(i=0;i<nov;i++)
	{
		printf("V%d->",i);

		for(t=L[i];t!=NULL;t=t->next)
		{
			printf("[%d]->",t->vertex);
		}
		printf("NULL\n");
	}
}
void display_degree(struct node *L1[],struct node *L2[])
{
	int i,indegree,outdegree,total;
	struct node *t;

	printf("\n Degree of Each vertex\n");

	for(i=0;i<nov;i++)
	{
		outdegree=0;
		indegree=0;

		for(t=L1[i];t!=NULL;t=t->next)
		{
			outdegree++;
		}
		for (t=L2[i];t!=NULL;t=t->next)
		{
			indegree++;
		}
		total=outdegree+indegree;
		printf("V%d:indegree=%d outdegree=%d Total Degree =%d\n",i,indegree,outdegree,total);
	}	
}
int main()
{
	init(AList);
	init(IAList);

	accept();

	printf("\nAdjacency List\n");
	display(AList);


	printf("\nInverse AdjacencyList\n");
	display(IAList);

	display_degree(AList,IAList);

	free_list(AList);
	free_list(IAList);
	return 0;
}