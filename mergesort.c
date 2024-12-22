#include<stdio.h>
#include<stdlib.h>

void accept(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the Number:");
		scanf("%d",&a[i]);
	} 
}
void display(int a[],int n)
{
	int i;
	printf("Array:");
	
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void merge (int a[],int lb,int mid,int ub)
{
	int temp[50];
	int i,j,k;
	i=lb;
	mid+1;
	k=0;
 while(i<=mid && j<=ub)
 {
	if(a[i]<=a[j])
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	else
	{
		temp[k]=a[j];
		j++;
		k++;
	}
 } 
  while(i<=mid);
 	{
		temp[k]=a[i];
		i++;
		k++;
 	}
  while(j<=ub)
   {
		temp[k]=a[j];
		i++;
		k++;
   }
	
	for(k=lb;k<=ub;k++)
  	{
		a[k]=temp[k];
  	}
}
void mergesort(int a[],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
int main()
{
	int a[100],n;
	printf("How Many random integer numbers:");
	scanf("%d",&n);

	accept(a,n);

	printf("Before sort: \n");
	display(a,n);

	mergesort(a,0,n-1);

	printf("After Sort: \n");
	display(a,n);

	return 0;
}