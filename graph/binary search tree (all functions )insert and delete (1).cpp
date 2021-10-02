#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node*left,*right,*parent;
}node;
node*create(node*start);
node *insertbst(node* root,int data); //recursive
void insertinbst(node *st_root,int data); //non - recursive
void deleted(node**btroot,node *delnode);
node* successor(node* delnode);
node *predeccessor(node* delnode);
node* searchinbst(node* root,int data);//recursive
node * non_rsearchinbst(node *root,int data);
void inordertraversal(node* btroot);
int main()
{
  node* btroot,*search;
  search=NULL;
  btroot=NULL;
  int i,j,value;
  printf("1 to create\n2 to search\n3 to delete\n4 to traverse\n5 to exit\n");
  scanf("%d",&j);
  while(j!=5)
  {
    switch(j)
    {
    	case 1:
    		btroot=create(btroot);
    		break;
    	case 2:
    		printf("enter value to be searched\n");
    		scanf("%d",&value);
    		search=searchinbst(btroot,value);
    		if(search==NULL)
    		  printf("number not found\n");
    		else
    		  printf("number is present\n");
    		  printf("%d",search->data);
    		  printf("%d",(search->parent)->data);
    		break;
    	case 3:
    		printf("enter value to be deleted\n");
    		scanf("%d\n",&value);
    		search=searchinbst(btroot,value);
    	    deleted(&btroot,search);
    		break;
    	case 4:
    		inordertraversal(btroot);
    		break;
    	case 5:
    		j=0;
    		break;
    	default:
    		printf("entered wrong value\n");
   	 }
	 printf("1 to create\n2 to search\n3 to delete\n4 to traverse\n5 to exit\n");
	 scanf("%d",&j);
   }
}
node*create(node*start)
{
	int i,data;
	printf("want to enter data 1/0 \n");
	scanf("%d",&i);
	while(i)
	{
		if(i==1)
	    {
	       scanf("%d",&data);
		   start=insertbst(start,data);
	    }
	    printf("want to enter data 1/0 \n");
		scanf("%d",&i);
	}
	return start;
}
node *insertbst(node* root,int data) //recursive
{
	node *temp;
	temp=root;
	if(root==NULL)
	{
		node*newnode;
		newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->parent=NULL;
		return newnode;
	}
	else if(root->data>data || root->data==data)
   {
	   root->left=insertbst(root->left,data);
	   root->left->parent=root;
    }
    else
    {
	   root->right=insertbst(root->right,data);
       root->right->parent=root;
    }
    return root;
}
void insertinbst(node *st_root,int data) //non - recursive
{
   node *temp,*root;
   root=st_root;
   temp=NULL;
   while(root!=NULL)
   {
   	 temp=root;
   	 if(root->data>data || root->data==data)
   	    root=root->left;
   	 else
		root=root->right;
   }
   node *newnode;
   newnode=(node*)malloc(sizeof(node));
   newnode->data=data;
   newnode->left=NULL;
   newnode->right=NULL;
   if(temp!=NULL)
   {
   	if(temp->data > data || temp->data==data)
   	    temp->left=newnode;
   	else
   	    temp->right=newnode;
   }
   newnode->parent=temp;
}
void deleted(node**btroot,node *delnode)
{
	node*par;
	par=delnode->parent;
//	printf("%d",par->data);
	if(delnode->left==NULL&&delnode->right==NULL) //leaf node
	{
		if(*btroot==delnode)
		{
			free(delnode);
			*btroot=NULL;
		}
		else
		{
		  if(par->left==delnode)
		     par->left=NULL;
	      else
		     par->right=NULL;
		  free(delnode);
	    }
	}
	else if(delnode->left==NULL || delnode->right==NULL) //one sided only
	{

	  	if(*btroot==delnode)
		{
			if(delnode->right!=NULL)
			{
			   (delnode->right)->parent=NULL;
			   *btroot=delnode->right;
		    }
			else
			{
			     (delnode->left)->parent=NULL;
			     *btroot=delnode->left;
			}
			free(delnode);
		}
		else if(delnode->right!=NULL)
		{
			if(par->right==delnode)
			{
			    printf("%d",par->data);
				par->right=delnode->right;

		    }
			else
			{
			    printf("%d",par->data);
			    par->left=delnode->right;
			}
	    }
		else//if(delnode->left!=NULL)
		{
		  if(par->right==delnode)
			par->right=delnode->left;
	      else
			par->left=delnode->left;
		}
		free(delnode);
	}
	else// if delnode has both left and right node
	{
		node *n_swap;
		int t;
		n_swap=successor(delnode);
		t=n_swap->data;
		n_swap->data=delnode->data;
		delnode->data=n_swap->data;
		if(*btroot==delnode)
		   free(n_swap);
		else
		{
		  (n_swap->parent)->left=NULL;
	    }

	/*	n_swap=predecessor(delnode);
		t=n_swap->data;
		n_swap->data=delnode->data;
		delnode->data=swap->data;
		(n_swap->parent)->=NULL;
   */
         deleted(btroot,n_swap);
    }
}
node* successor(node* x)
{
/*	node *temp;
	temp=delnode->right;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;*/
	if(x->right!=NULL)
	{
		node *y;
		x=x->right;
		while(x!=NULL)
		{
			y=x;
			x=x->left;
		}
		return y;
	}
	else //if(x->right==NULL)
	{

		node* y;
		y=x->parent;
		while(y!=NULL&&y->left!=x)
		{
			y=y->parent;
			x=x->parent;
		}
		return y;
	}
}
node *predeccessor(node* x)
{
	if(x->left!=NULL)
	{
		node *y;
		x=x->left;
		while(x!=NULL)
		{
			y=x;
			x=x->right;
		}
		return y;
	}
	else //if(x->right==NULL)
	{

		node* y;
		y=x->parent;
		while(y!=NULL&&y->right!=x)
		{
			y=y->parent;
			x=x->parent;
		}
		return y;
	}

}
node* searchinbst(node* root,int data)   //recursive
{
	node*temp;
	if(root==NULL)
	   return NULL;
	else if(root->data==data)
       return root;
	else if(root->data>data)
	{
	    temp=searchinbst(root->left,data);
    }
	else
	{
		temp=searchinbst(root->right,data);
	}
    return temp;
}
node * non_rsearchinbst(node *root,int data)
{
	while(root!=NULL)
	{
		if(root->data==data)
		   return root;
		else if(root->data>data)
		    root=root->left;
		else
		   root=root->right;
    }
    return 0;
}
void inordertraversal(node* btroot)
{
	if(btroot!=NULL)
	{
	  inordertraversal(btroot->left);
      printf("%d\n",(btroot->data));
      inordertraversal(btroot->right);
    }
}
