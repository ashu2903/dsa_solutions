#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int exp,coeff;
	struct node* ptr;
}node;
node* create();
node* add(node*,node*);
void display(node*);
main()
{
	node *poly1,*poly2,*poly3;
	poly1=create();
	poly2=create();
	poly3=add(poly1,poly2);
	display(poly3);
}
node* create()
{
	node* start=NULL,*curr,*prev=NULL;
	int n,i;
	printf("Enter no. of terms : ");
	scanf("%d",&n);
	printf("Enter exp and coeff respectively : ");
	for(i=0;i<n;i++)
	{
		curr=(node*)malloc(sizeof(node));
		scanf("%d %d",&curr->exp,&curr->coeff);
		if(start==NULL)
			start=curr;
		else
			prev->ptr=curr;
		prev=curr;
	}
	if(start!=NULL)
		prev->ptr=NULL;
	return start;
}
node* add(node* poly1,node* poly2)
{
	int sum;
	node *start=NULL,*curr=NULL,*prev=NULL;
	while(poly1!=NULL&&poly2!=NULL)
	{
		if((poly1->exp)>(poly2->exp))
		{
			curr=(node*)malloc(sizeof(node));
			curr->coeff=poly1->coeff;
			curr->exp=poly1->exp;
			poly1=poly1->ptr;
		}
		else if((poly2->exp)>(poly1->exp))
		{
			curr=(node*)malloc(sizeof(node));
			curr->coeff=poly2->coeff;
			curr->exp=poly2->exp;
			poly2=poly2->ptr;
		}
		else
		{
			sum=poly1->coeff+poly2->coeff;
			if(sum!=0)
			{
				curr=(node*)malloc(sizeof(node));
				curr->coeff=sum;
				curr->exp=poly1->exp;		
			}
			poly1=poly1->ptr;
			poly2=poly2->ptr;
		}
		if(start==NULL)
			start=curr;
		else
			prev->ptr=curr;
		prev=curr;
	}
	while(poly1!=NULL)
	{
		curr=(node*)malloc(sizeof(node));
		curr->coeff=poly1->coeff;
		curr->exp=poly1->exp;
		poly1=poly1->ptr;
		if(start==NULL)
			start=curr;
		else
			prev->ptr=curr;
		prev=curr;	
	}
	while(poly2!=NULL)
	{
		curr=(node*)malloc(sizeof(node));
		curr->coeff=poly2->coeff;
		curr->exp=poly2->exp;
		poly2=poly2->ptr;
		if(start==NULL)
			start=curr;
		else
			prev->ptr=curr;
		prev=curr;	
	}
	if(start!=NULL)
		prev->ptr=NULL;
	return start;
}
void display(node* start)
{
	node* temp=start;
	while(temp!=NULL)
	{
		printf("\n%d %d",temp->exp,temp->coeff);
		temp=temp->ptr;
	}
}
