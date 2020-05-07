#include <bits/stdc++.h>
using namespace std;

int magicGrid(int **input,int r,int c)
{   
    int **dp = new int*[r];
    for(int i = 0;i<r;i++)
        dp[i] = new int[c];
    
    for(int i=0; i<r; i++){
            for(int j=0; j<c; j++)
                dp[i][j] = 0;
        }
    
    //minimum case health = 1 at the end
    dp[r-1][c-1] = 1;
    dp[r-2][c-1] = 1;
    dp[r-1][c-2] = 1;
    
    //base case row-wise
    for(int i=r-3;i>=0;i--)
    {
        if(dp[i+1][c-1]-input[i+1][c-1]<1)
                dp[i][c-1]=1;
        else
                dp[i][c-1] = dp[i+1][c-1]-input[i+1][c-1];
   
    }
    //base case for column wise
    for(int j=c-3;j>=0;j--)
    {
        if(dp[r-1][j+1]-input[r-1][j+1]<1)
                dp[r-1][j]=1;
            else
                dp[r-1][j] = dp[r-1][j+1]-input[r-1][j+1];

    }
    
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            
            	int op1 = dp[i+1][j]-input[i+1][j];
                if(op1<1)
                    op1 =1;
                int op2 = dp[i][j+1]-input[i][j+1];
                if(op2<1)
                    op2 =1;
                dp[i][j] = min(op1, op2);
 
        }
    }
    
    return dp[0][0];
}

int main()
{
	int test;
    int r,c;
    cin>>test;
    while(test--)
    {
     cin>>r>>c;
        
    int **input = new int*[r];
    for(int i=0;i<r;i++)
    {
       input[i] = new int[c];  
    }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>input[i][j];
            }
        }
    
   cout<<magicGrid(input,r,c)<<endl;
    }
    return 0;
}