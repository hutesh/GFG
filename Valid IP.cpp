
#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		char s[10000];
		cin>>s;
		cout<<isValid(s)<<endl;
	}
	return 0;
}
int isValid(char *s)
{
   int p,valid=1,j=0;
        stack<int>st;
       while(s[j]!='\0')
        {
            if(s[j]=='.')
            {
                if(st.empty()||j==0||s[j+1]=='\0'||s[j+1]=='.')
                {
                    valid=0;
                    break;
                }
                else
                {
                    int sum=0,k=0;
                    while(!st.empty())
                    {
                        sum=sum+(st.top())*pow(10,k);
                        k++;
                        st.pop();
                    }
                    if(sum>255)
                    {
                        valid=0;
                        break;
                    }
                }
            }
            else
            {
                if(s[j]-'0'>=0&&s[j]-'0'<=9)
                {
                p=s[j]-'0';
                st.push(p);
                }
            }
       }
            if(valid==1)
            {
                   int sum=0,k=0;
                    while(!st.empty())
                    {
                        sum=sum+pow(10,k);
                        k++;
                    }
                    if(sum>255)
                    {
                        valid=0;
                    }
            }
return valid;
}
