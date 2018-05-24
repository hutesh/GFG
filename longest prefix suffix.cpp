#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
    string s;
    cin>>s;
    int l=s.length();
    int arr[l];
    arr[0]=0;
    int j=0;
    for(int i=1;i<l;)
    {
        if(s[j]==s[i])
        {
            arr[i]=j+1;
            i++;
            j++;
        }
        else
        {
            while(s[i]!=s[j])
            {
                if(j!=0)
                {
                    j=arr[j-1];
                }
                else
                {
                    arr[i]=0;
                    i++;
                    break;
                }
            }
        }
    }
        cout<<arr[l-1]<<"\n";
    }
    return 0;
}
