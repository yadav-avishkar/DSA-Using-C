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
void selection_sort( int a[], int n)
{
	int i,j,t,flag;
	for(i=n-1;i>0;i--)
	{
		flag=0;
		
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
			 	t=a[j];
			 	a[j]=a[j+1];
			 	a[j+1]=t;
			}
		}
		if(flag==0)
			break;
		
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
	
	selection_sort(a,n);

	printf("\nAfter sort\n");
	display(a,n);

	return 0;

}
