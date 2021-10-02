#include<stdio.h>
#include<stdlib.h>
void merge(int * ptr, int l, int mid, int r)
{
    int i,k,j;
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    for(i=1;i<n1;i++)
        L[i]=ptr[l+i];
    for(i=0;i<n2;i++)
        R[i]=ptr[mid+i+1];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]>R[i])
        {
            ptr[k]=R[j];
            j++;

        }
        else if(L[i]<=R[j])
        {
            ptr[k]=L[i];
            i++;
        }
        k++;
    }
    while(i<n1)
    {
        ptr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        ptr[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(int *ptr, int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        merge_sort(ptr,l,mid);
        merge_sort(ptr,mid+1,r);
        merge(ptr,l,mid, r);
    }

}
 int main()
 {
     int size;
     printf("Enter the size of list");
     scanf("%d", &size);
     int list[size];
     printf("Enter the list");
     for(int i=0; i<size; i++)
     {
         scanf("%d", &list[i]);
    }
    int *p;
    p=&list[0];
    merge_sort(p,0,size);
    printf("The sorted list is   ");
    for(int i=0; i<size;i++)
    {
        printf("%d\t", list[i]);
    }
 }

