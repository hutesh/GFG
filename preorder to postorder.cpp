#include<bits/stdc++.h>
using namespace std;
int postorder(int arr[],int s,int l)
{
    if(s==l)
    {
        cout<<arr[s]<<" ";
        return 1;
    }
    else if(s>l)
      return 1;
    int first=arr[s];
    int i=s+1;
    while(i<=l&&first>arr[i])
        i++;
    int mid=i-1;
    for(int j=i;j<=l;j++)
    {
        if(arr[j]<first)
            return 0;
    }
    if(postorder(arr,s+1,mid))
    {
        if(postorder(arr,mid+1,l))
        {
            cout<<arr[s]<<" ";
            return 1;
        }
    }
    return 0;
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

       if(!postorder(arr,0,n-1))
           cout<<"NO\n";
       else
           cout<<"\n";
    }
    return 0;
}
