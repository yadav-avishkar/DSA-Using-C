#include<stdio.h>

void accept(int a[], int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&a[i]);
	}
}

void display(int a[],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

}

void merge(int a[], int lb, int mid, int ub)
{
	int temp[40];
	int i,j,k;
	i=lb;
	k=0;
	j=mid+1;

	while((i<=mid) && (i<=ub))
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=ub)
	{
		temp[k]=a[j];
		j++;
		k++;
	}
	
	for(i=lb,k=0;i<=ub; i++, k++)
	{
		a[i]=temp[k];
	}
}
void mergesort(int a[], int lb, int ub)
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
	int a[50],n;

	printf("How many random integer numbers:");
	scanf("%d",&n);

	accept(a,n);

	printf("\nBefore sort\n");
	display(a,n);
	
	mergesort(a,0,n-1);

	printf("\nAfter sort\n");
	display(a,n);

	return 0;

}
