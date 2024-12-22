#include<stdio.h>
#include"singly.h"

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