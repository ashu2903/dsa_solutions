// C++ program for selection sort
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
            
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int a[50],n,i;
	printf("How many elements?");
	scanf("%d",&n);
	printf("\nEnter array elements:");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	selectionSort(a,n);
	printf("\nArray after sorting:");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return 0;		
}
