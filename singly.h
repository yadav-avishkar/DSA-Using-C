#include<stdio.h>
#include <stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))
 struct node
  {
  	int data;
  	struct node*next;
  };
 struct node*create(int n)
  {
  	struct node *f=NULL, *l=NULL, *t=NULL;
  	  	int i;
  	  	f=NEWNODE;
  	  	printf("Enter Data:");
  	  	scanf("%d",&f->data);
  	  	  l=f;
  	  	  for(i=2;i<=n;i++)
  	  	  {
  	  	  	t=NEWNODE;
  	  	  	printf("Enter Data:");
  	  	  	scanf("%d",&t->data);
  	  	  	t->next=NULL;
  	  	  	l-> next=t;
  	  	  	l=l->next;
  	  	  }
  	return f;  	   
  }
void display(struct node *f)
{
	struct node*t;
	printf("\n Linked list:");
	  for(t=f;t!=NULL;t=t->next)
	  {
	  	printf("%d",t->data);
      }
      printf("\n");

}   
struct node* eraseall(struct node*f)
{
	struct node*t;
	while(f!=NULL)
	{
		t=f;
		f=f->next;
		free(t);
	}
	return f;
}
struct node* insert(struct node *f, int pos)\
{
	struct node *s,*t;
	int i;
	t=NEWNODE;
	printf("Enter Data :");
	scanf("%d",&t->data);
	  t->next=NULL;
	  if(pos==1)
	  {
	  	t->next=f;
	  	f=t;
	  	printf("Data is Inserted Successfully!!");
	  	return f;
	  }
	  else
	  {
	  	s=f;
	  	for(i=1;i<=pos-2 && s!=NULL;i++)
	  	{
	  		s=s->next;
	  	}
	  	  if(s==NULL)
	  	  {
	  	  	printf("\n Error: Invalid Position\n");
	  	  	  free(t);
	  	  	  return f;
	  	  }
	  	  t->next=s->next;
	       s->next=t;
	      printf("Data is Inserted Successfully!!");
	        return f;
	   }     
}
struct node* delete(struct node *f, int pos)
{
	struct node *s,*t;
	   int i;
	   if(pos==1)
	   {
	   	t=f;
	   	f=f->next;
	   	free(t);
	   	printf("Data is deleted Successfully !!");
	   	  return f;
	   }
	   else
	   {
	   	s=f;
	   	for(i=1; i=pos-2 && s!=NULL;i++)
	   	{
	   		s=s->next;
	   	}
	   	if(s==NULL || s-> next==NULL)
	   	{
	   		printf("\n Invalid Position");
	   		  return f;
	   	}
	   	t=s->next;
	   	s->next=t->next;
	   	free(t);
	   	printf("Data id deleted Successfully !!");
	   	    return f;
	   }
}
struct node* insert_last(struct node *f)
{
	struct node *l,*t;
	
	t=NEWNODE;
	printf("Enter Data to insert at last Position:");
	scanf("%d",&t->data);
	  t->next=NULL;
	  if(f==NULL)
	  {
	  	 	return t;
	  }
	  else
	  {
	   	for(l=f;l->next!=NULL;l=l->next)
	  	{
	  		// No code
	  	}
	  	l->next=t;
	  	 return f;
	   }     
}
