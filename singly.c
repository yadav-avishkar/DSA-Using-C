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
int main()
{
	struct node *head=NULL;
	int n,choice,pos;
	printf("How many Nodes you want to create:");
	scanf("%d",&n);
	  if(n<=0)
	  {
	  	printf("\n Given number is less than One:\n");
	  	exit(0);
	  }
	  head=create(n);
	  while(1)
	  {
	  	printf("\n Menu\n 1. Display Linked list \n 2. Insert Node into Linked list \n 3. Delete node from Linked List \n 4. Insert last into Linked List\n 5.Exit\n");
	  	printf("What is your choice:");
	  	scanf("%d", &choice);
	  	switch(choice)
	  	{
	  	case 1:
	  		printf("\n Linked List :");
	  		display(head);
	  		break;
	  	case 2:
	  		printf("Enter Position to Insert:");
	  		scanf("%d",&pos);
	  		head=insert(head,pos);
	  		break;
	  	case 3:
	  		printf("Enter Position to delete node into a Linked List :");
	  		scanf("%d",&pos);
	  		head=delete(head,pos);
	  		break;
	  	case 4:
	  		printf("Enter Position to Insert last");
	  		scanf("%d",&pos);
	  		head=insert(head,pos);
	  		break;
	  	case 5:
	  		head=eraseall(head);
	  		exit(0);
	  	default:
	  		printf("Invalid Option in selected:\n");
	  	}
	  }
	return 0;
}