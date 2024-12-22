#include<stdio.h>
#define SIZE 10

int G[SIZE][SIZE];
int nov;
int noe;

void accept()
{
	int i,j,k;
	printf("How Many Vertices :");
	scanf("%d",&nov);

	printf("How many Edges :");
	scanf("%d",&noe);

	for(k=1;k<=noe;k++)
	{
		printf("Enter Edge (vi,vj) :");
		scanf("%d%d",&i,&j);
		G[i][j]=1;
	}
}
void display()
{
	int i,j;
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
int sum_of_row(int i)
{
	int j,sum;
	sum=0;

	for(j=0;j<nov;j++)
	{
		sum=sum+G[i][j];
	}
	return sum;
}
int sum_of_cols(int j)
{
	int i,sum;
	sum=0;

	for(i=0;i<nov;i++)
	{
		sum=sum+G[i][j];
	}
	return sum;
}
int main()
{
	accept();
	display();

}