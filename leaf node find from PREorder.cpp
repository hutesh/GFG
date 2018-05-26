#include<bits/stdc++.h>
using namespace std;
void leafnode(int arr[],int s,int l)
{
    if(s==l)
    {
        cout<<arr[s]<<" ";
        return ;
    }
    else if(s>l)
      return ;
    int first=arr[s];
    int i=s+1;
    while(i<=l&&first>arr[i])
        i++;
    int mid=i-1;

    leafnode(arr,s+1,mid);
    leafnode(arr,mid+1,l);
    return;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       int n;
       cin>>n;
       int arr[n];
       for(int j=0;j<n;j++)
            cin>>arr[j];
       leafnode(arr,0,n-1);
       cout<<"\n";
    }
    return 0;
}
