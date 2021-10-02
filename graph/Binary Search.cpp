#include<iostream>
using namespace std;
int binary_search(int arr[],int n,int val);
int main(){
  int n,i,val;
  cout<<"Enter the number of elements you want to insert in the list:";
  cin>>n;
  int arr[n];
  cout<<"Enter "<<n<<" numbers in the array in sorted order:\n";
  for(i=0;i<n;i++)
  	cin>>arr[i];
  cout<<"Enter the number that you want to search in the list:";
  cin>>val;
  int pos=binary_search(arr,n,val);
  if(pos==-1)
  cout<<val<<" does not exist in the list.\n";
  else
  cout<<val<<" is found at position="<<pos+1;
  return 0;
}

int binary_search(int arr[],int n,int val){
  int mid,pos=-1,beg=0,end=n-1;
   while(beg<=end){
    mid=(beg+end)/2;
    if(arr[mid]==val){
      pos=mid;
      break;
    }
    else if(arr[mid]>val)
      end=mid-1;
    else
       beg=mid+1;
  }
  return pos;
}
