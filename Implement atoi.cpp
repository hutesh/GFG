#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
 int l=s.length();
        int flag=0;
        int num=0;
        if(s[0]!='-')
        {
        for(int i=0;i<l;i++)
        {
           if(s[i]-'0'>=0&&s[i]-'0'<=9)
           {
               int p=s[i]-'0';
               num=num+p*pow(10,l-i-1);
           }
           else
           {
               flag=1;
               break;
           }
        }
        if(flag==1)
            return -1;
        else
            return num;
        }
        else
        {
           for(int i=1;i<l;i++)
        {
           if(s[i]-'0'>=0&&s[i]-'0'<=9)
           {
               int p=s[i]-'0';
               num=num+p*pow(10,l-i-1);
           }
           else
           {
               flag=1;
               break;
           }
        }
        if(flag==1)
            return -1;
        else
            return -num;
        }
        }
    }
    return 0;
}
