#include<stdio.h>
typedef struct employee
{
	int age;
	char name[200];
}emp;
emp e[10];
int readfile(emp a[])
{
	int i=0;
	FILE *fp;
	fp=fopen("avi.txt","r");
	if(fp==NULL)
	{
		printf("\nFile is not found\n");
	}
	else
	{
		while(! feof(fp))
		{
			scanf("%d%s",&a[i].age,a[i].name);
			i++; 
		}
	}
	return i-1;
}
void writefile(emp a[], int n)
{
	int i=0;
	for(i=0; i<n; i++)
	{
		printf("%d \t %s \n",a[i].age , a[i].name);
	}
}
void insertion(int a[],int n)
{
	int i,j;
	int t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i-1;j>=0;j--)
		{
			
			if(a[j].age>t.age)
			{
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
}
int main()
{
	int n;
	printf("The contents of file are:\n");
	n=readfile(e);
	writefile(e,n);
	insertion(e,n);
	printf("After sorting file contents are:\n");
	   writefile(e,n);
}