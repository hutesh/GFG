#include<bits/stdc++.h>
using namespace std;
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
       for(int j=0;j<n;j++)
       {
           int count=0;
           for(int k=j;k>=0;k--)
           {
               if(arr[k]>=arr[j])
                  count++;
                else
                    break;
           }
           cout<<count<<"\n";
       }
       cout<<"\n";
    }
    return 0;
}
