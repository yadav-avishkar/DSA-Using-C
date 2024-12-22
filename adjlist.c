#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define NEWNODE (struct node *)malloc(sizeof(struct node))
                       
struct node
{
	int vertex;
	struct node *next;
};
struct node *AList[SIZE];
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

int main()
{
 	init(AList);
    accept();
	printf("\nAdjacency List\n");
	display(AList);
	free_list(AList);
	
	return 0;
}
