#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       int n,m;
       cin>>n>>m;
       int arr[n][m];
       for(int j=0;j<n;j++)
        for(int k=0;k<m;k++)
           cin>>arr[j][k];

        int row[n][m];
        int col[n][m];
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(arr[j][k]==0)
                    row[j][k]=0;
                else
                {
                    if(k!=0)
                    row[j][k]=1+row[j][k-1];
                    else
                    row[j][k]=1;
                }
            }
        }
        for(int k=0;k<m;k++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j][k]==0)
                    col[j][k]=0;
                else
                {
                    if(j!=0)
                    col[j][k]=1+col[j-1][k];
                    else
                    col[j][k]=1;
                }
            }
        }
        int maxi=-1;
        for(int j=0;j<n;j++)
        {
            int count=0;
            int mini=INT_MAX;
            int sam=0,samC=0;
            for(int k=0;k<m-1;k++)
            {
               if(col[j][k]==col[j][k+1])
               {
                    mini=min(col[j][k],mini);
                    sam=col[j][k];
                    samC++;
                    count++;
               }
                else if(col[j][k]!=col[j][k+1]&&col[j][k]!=0)
                {
                    mini=min(mini,col[j][k]);
                    maxi=max(maxi,(count+1)*mini);
                    maxi=max(maxi,(samC+1)*sam);
                    maxi=max(maxi,col[j][k]);
                    sam=0;
                    samC=0;
                    count++;
                }
                else
                {
                    count=0;
                    sam=0;
                    samC=0;
                    mini=INT_MAX;
                }
            }
        }

        for(int k=0;k<m;k++)
        {
            int count=0;
            int mini=INT_MAX;
            int sam=0,samC=0;
            for(int j=0;j<n-1;j++)
            {
               if(row[j][k]==row[j+1][k])
               {
                    mini=min(row[j][k],mini);
                    sam=row[j][k];
                    samC++;
                    count++;
               }
                else if(row[j][k]!=row[j+1][k]&&row[j][k]!=0)
                {
                    mini=min(mini,row[j][k]);
                    maxi=max(maxi,(count+1)*mini);
                    maxi=max(maxi,(samC+1)*sam);
                    maxi=max(maxi,row[j][k]);
                    sam=0;
                    samC=0;
                    count++;
                }
                else
                {
                    count=0;
                    sam=0;
                    samC=0;
                    mini=INT_MAX;
                }
            }
        }


        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
              cout<<row[j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"-----------------------------";
        cout<<"\n";
         for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
              cout<<col[j][k]<<" ";
            }
            cout<<"\n";
        }
       return max(col[n-1][m-1],max(maxi,row[n-1][m-1]));
    }
    return 0;
}
