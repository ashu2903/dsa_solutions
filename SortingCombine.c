//Quick, Merge, Heap Sorting
#include<stdio.h>
 
void create(int []);
void down_adjust(int [],int);
 
void heap(){
	int heap[30],n,i,last,temp;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);
	
	heap[0]=n;
	create(heap);
	
	while(heap[0] > 1){
		last=heap[0];
		temp=heap[1];
		heap[1]=heap[last];
		heap[last]=temp;
		heap[0]--;
		down_adjust(heap,1);
	}
	
	printf("\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		printf("%d ",heap[i]);
}
 
void create(int heap[]){
	int i,n;
	n=heap[0]; 
	for(i=n/2;i>=1;i--)
		down_adjust(heap,i);
}
 
void down_adjust(int heap[],int i){
	int j,temp,n,flag=1;
	n=heap[0];
	
	while(2*i<=n && flag==1){
		j=2*i;	
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}


void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int mymerge(){
	int a[30],n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter array elements:");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	mergesort(a,0,n-1);
	
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		
	return 0;
}
 
void mergesort(int a[],int i,int j){
	int mid;
		
	if(i<j){
		mid=(i+j)/2;
		mergesort(a,i,mid);	
		mergesort(a,mid+1,j);	
		merge(a,i,mid,mid+1,j);	
	}
}
 
void merge(int a[],int i1,int j1,int i2,int j2){
	int temp[50];	
	int i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	
	while(i<=j1 && j<=j2){
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=j1)	
		temp[k++]=a[i++];
		
	while(j<=j2)	
		temp[k++]=a[j++];
		
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}

void quick_sort(int[],int,int);
int partition(int[],int,int);
 
int quick(){
	int a[50],n,i;
	printf("How many elements?");
	scanf("%d",&n);
	printf("\nEnter array elements:");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	quick_sort(a,0,n-1);
	printf("\nArray after sorting:");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return 0;		
}
 
void quick_sort(int a[],int l,int u){
	int j;
	if(l<u){
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}
 
int partition(int a[],int l,int u){
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;
	do
	{
		do
			i++;	
		while(a[i]<v&&i<=u);
		
		do
			j--;
		while(v<a[j]);
		
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	
	a[l]=a[j];
	a[j]=v;
	return(j);
}

int main(){
	int a;
	printf(" press 1 for heap sort.. \n press 2 for merge sort.. \n press 3 for quick sort..");
	scanf("%d",&a);
	if(a==1){
		printf("heap sort \n");
		heap();
	}
	else if(a==2){
		printf("merge sort \n");
		mymerge();
	}
	else if(a==3){
		printf("quick sort \n");
		quick();
	}
	else {
		printf("invalid choice");
	}
	
	return 0;
}
 
