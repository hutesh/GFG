#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;cin>>s;
        int l=s.length();
        int flag=0;
        for(int j=1;j<=6;j++)
        {
            int last=-1;
            int miss=0;
            int missNO,k,h=0;
            for(k=0;k<l;)
            {
                int sum=0;
                for(int r=1;r<=j+h;r++)
                {
                    int p=s[k]-'0';
                    sum=sum+p*pow(10,j+h-r);
                    k++;
                }
                cout<<"sum is here "<<sum<<"\n";
                if(1+floor(log10(sum))==floor(log10(sum+1)))
                     h++;
                else if(last>sum&&(1+floor(log10(last))==floor(log10(last+2))))
                    {
                        h++;
                        k=k-j;
                        continue;
                    }
                if(last==-1)
                    last=sum;
                else if(sum==last+1)
                     last=sum;
                else if(sum==last+2)
                     {
                         miss++;
                         missNO=last+1;
                         last=sum;
                         cout<<"this time miss no is "<<missNO<<"\n";
                     }
                else
                    break;
            }
            if(k==l&&miss==1)
            {
                cout<<missNO<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"-1\n";
    }
    return 0;
}
