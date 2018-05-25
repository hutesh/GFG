bool isInterleave(string A, string B, string C)
{
     int l1=B.length();
     int l2=A.length();
     int IL[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0&&j==0)
                IL[i][j]=1;

            else if (j==0 && B[i-1]==C[i-1])
                IL[i][j] = IL[i-1][j];

            // B is empty
            else if (i==0 && A[j-1]==C[j-1])
                IL[i][j] = IL[i][j-1];

            // Current character of C matches with current character of A,
            // but doesn't match with current character of B
            else if(A[j-1]==C[i+j-1] && B[i-1]!=C[i+j-1])
                IL[i][j] = IL[i][j-1];

            // Current character of C matches with current character of B,
            // but doesn't match with current character of A
            else if (A[j-1]!=C[i+j-1] && B[i-1]==C[i+j-1])
                IL[i][j] = IL[i-1][j];

            // Current character of C matches with that of both A and B
            else if (A[j-1]==C[i+j-1] && B[i-1]==C[i+j-1])
                IL[i][j]=(IL[i-1][j] || IL[i][j-1]) ;
            else
                IL[i][j]=0;
        }
    }
    /*for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            cout<<IL[i][j]<<" ";
        }
      cout<<"\n";
    }*/
    if(IL[l1][l2]==1)
        return true;
    else
        return false;
}

