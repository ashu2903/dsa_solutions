#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
	int data;
	struct tnode *left, *right;
	struct tnode *parent;
}node;
node* createEbst();
node*insertbst(node *root, int data);
void inorder_trv(node*bst);
void insertion_sort(int list[],int n);
node * createBST(int list[],int start,int end);
int main()
{
	int x=0,val,n,i,list[100];
	node *bst1;
	while(i!=8)
	{
		printf("\nEnter operation that you want to perform:\n1.Create empty BST\n2.Create BST\n3.Insert in BST\n4.In order traversal\n");
		scanf("%d",&x);
		switch (x)
		{
			case 1:
				bst1=createEbst();
				break;
			case 2:
				printf("Enter number of values in BST ");
				scanf("%d",&n);
				printf("Enter all values in BST ");
				for(i=0;i<n;i++)
					scanf("%d", &list[i]);
				insertion_sort(list,n);
				bst1=createBST(list,0,n-1);
				break;
			
			
			case 3:
				printf("Enter value to insert ");
				scanf("%d",&val);
				bst1=insertbst(bst1,val);
				break;
			case 4:
				inorder_trv(bst1);
				break;
		}
	}
}
node* createEbst()
{
	return NULL;
}
node*insertbst(node *root, int data)
{
	if(root==NULL)
	{
		node *newnode;
		newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->parent=root;
		return newnode;
	}
	else if(root->data>=data)
		root->left=insertbst(root->left,data);
	else
		root->right=insertbst(root->right,data);
	return root;
}
void inorder_trv(node*bst)
{
	if(bst!=NULL)
	{
		inorder_trv(bst->left);
		printf("%d ",bst->data);
		inorder_trv(bst->right);
	}
}
void insertion_sort(int list[],int n)
{
	int i,j,temp,count=0;
	for(i=1;i<n;i++)
	{
		temp=list[i];
		j=i-1;
		while(j>=0&&temp<list[j])
		{
			list[j+1]=list[j];
			j--;
		}
		list[j+1]=temp;
	}
}
node * createBST(int list[],int start,int end)
{
	int mid;
	node* newnode;
	if(end==-1) return NULL;
	mid=(start+end)/2;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=list[mid];
	if(start<end)
	{
		
		if (start <=mid-1)
		{
		    newnode->left=createBST(list,start,mid-1);
		    newnode->left->parent=newnode;
		}
		else newnode->left = NULL;
		
		if (mid+1 <=end)
		{
			newnode->right=createBST(list,mid+1,end);
			newnode->right->parent=newnode;
	    }
		else newnode->right=NULL;   
	}
	else
	{
		newnode->left=NULL;
		newnode->right=NULL;
	}
	return newnode;
	
}
