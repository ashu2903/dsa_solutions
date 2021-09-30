#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* ptr;
}node;
void push(node**,int);
int pop(node**);
void display(node*);
main()
{
	node* top=NULL;
	int x,data,val;
	while(1)
	{
		printf("Enter 1 for push,2 for pop,3 for display,0 for exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter value of data : ");
				scanf("%d",&data);
				push(&top,data);
				break;
			case 2:
				val=pop(&top);
				break;
			case 3:
				display(top);
				break;
			case 0:
				exit(0);
		}
	}	
}
void push(node** top,int data)
{
	node *curr,*prev=*top;
	curr=(node*)malloc(sizeof(node));
	if(curr==NULL)
		printf("Push Failed!");
	else
	{
		curr->data=data;
		if(*top==NULL)
			curr->ptr=NULL;
		else
			curr->ptr=prev;
		*top=curr;
	}
}
void display(node* top)
{
	node* temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->ptr;
	}
}
int pop(node** top)
{
	int val;
	node *next;
	if(*top!=NULL)
	{
		next=(*top)->ptr;
		val=(*top)->data;
		free(*top);
		*top=next;
		return val;
	}
	printf("Pop Failed!");
	return -1;
}
