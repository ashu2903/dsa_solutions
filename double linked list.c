#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,*back;
}node;
node* createdll();
void transfor(node*);
void transback(node*);
node* insertatpos(node*,int,int);
main()
{
	node* start;
	int pos,val;
	start=create();
	transfor(start);
	transback(start);
	printf("Enter pos at which element to be inserted & val to be inserted: ");
	scanf("%d %d",&pos,&val);
	start=insertatpos(start,pos,val);
}
node* create()
{
	node *start=NULL,*temp,*prev;
	int val;
	printf("Enter Data : ");
	scanf("%d",&val);
	while(val!=-1)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		if(start==NULL)
		{
			start=temp;
			start->back=NULL;
		}
		else
		{
			prev->next=temp;
			temp->back=prev;
		}
		prev=temp;
		scanf("%d",&val);
	}
	if(start!=NULL)
		prev->next=NULL;
	return start;
}
void transfor(node* start)
{
	node* temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void transback(node* start)
{
	node* temp=start;
	while(temp->next!=NULL)
		temp=temp->next;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->back;
	}
}
node* insertatpos(node* start,int pos,int val)
{
	node *temp,*temp1,*nextn;
	int i=2;
	if(pos==1)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		start->back=temp;
		temp->back=NULL;
		temp->next=start;
		return temp;
	}
	while(temp!=NULL&&i<pos)
	{
		i++;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Insertion Unsuccessfull!");
		return start;
	}
	nextn=temp->next;
	temp1=(node*)malloc(sizeof(node));
	temp1->data=val;
	temp->next=temp1;
	temp1->back=temp;
	if(nextn==NULL)
		temp1->next=NULL;
	else
	{
		temp1->next=nextn;
		nextn->back=temp1;
	}
	return start;
}
node* insertafter(node* start,int val,int newdata)
{
	node *temp=start,*temp1,*nextn;
	while(temp!=NULL&&temp->data!=val)
		temp=temp->data;
	if(temp==NULL)
	{
		printf("Insertion Unsucessfull!");
		return start;
	}
	temp1=(node*)malloc(sizeof(node));
	temp1->data=newdata;
	nextn=temp->next;
	temp->next=temp1;
	temp1->back=temp;
	if(nextn==NULL)
		temp1->next=NULL;
	else
	{
		temp1->next=nextn;
		nextn->back=temp1;
	}
	return start;
}
node* insertbefore(node* start,int val,int newdata)
{
	node *temp=start,*temp1,*prev=NULL;
	while(temp!=NULL&&temp->data!=val)
	{
		prev=temp;
		temp=temp->data;
	}
	if(temp==NULL)
	{
		printf("Insertion Unsuccessfull!");
		return start;
	}
	temp1=(node*)malloc(sizeof(node));
	temp1->data=newdata;
	temp1->next=temp;
	temp->back=temp1;
	if(prev==NULL)
	{
		temp1->back=NULL;
		return temp1;
	}
	prev->next=temp1;
	temp1->back=prev;
	return start;
}
node* deleteatpos(node* start,int pos,int newdata)
{
	node *temp=start->next,*prev,*nextn;
	int i=2;
	if(pos==1)
	{
		free(start);
		temp->back=NULL;
		return temp;
	}
	while(temp!=NULL&&i<pos)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("Deletion Unsucessfull!");
		return start;
	}
	prev=temp->back;
	nextn=temp->next;
	prev->next=nextn;
	if(nextn!=NULL)
		nextn->back=prev;
	return start;
}
