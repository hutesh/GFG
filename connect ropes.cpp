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
        int x;
        queue<int>q;
        for(int j=0;j<n;j++)
        {
            cin>>x;
            q.push(x);
        }
        int total=0;
        while(!q.empty())
        {
            int l=q.size();
            int a=q.front();
            q.pop();
            int b=q.front();
            q.pop();
            int f=max(a,b);
            int s=min(a,b);
            for(int j=3;j<l;j++)
            {
                if(q.front()>=f)
                {
                    q.push(q.front());
                    q.pop();
                }
                else if(q.front()<=s)
                {
                    int temp=f;
                    f=s;
                    s=q.front();
                    q.pop();
                    q.push(temp);
                }
                else if(q.front()<f&&q.front()>s)
                {
                    int temp=f;
                    f=q.front();
                    q.push(temp);
                    q.pop();
                }
            }
            cout<<"f==  "<<f<<"s->"<<s<<"\n";
            if(q.empty())
            {
                total=total+f+s;
                cout<<total<<"\n";
                 cout<<"total =="<<total<<"\n";
                break;
            }
            else{
                q.push(f+s);
                total=total+f+s;
                 cout<<"total =="<<total<<"\n";
            }

        }

    }
    return 0;
}
