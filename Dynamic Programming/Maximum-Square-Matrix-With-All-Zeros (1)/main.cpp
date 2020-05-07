/*
Maximum Square Matrix With All Zeros
Send Feedback
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

#include<iostream>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **dp = new int*[row];
    for(int i=0;i<row;i++)
    {
        dp[i] = new int[col];
    }
    
    //filling the base case
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0)
            {
                if(arr[i][j] == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            if(j==0)
            {
                if(arr[i][j] == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
    }
   for(int i=1;i<row;i++)
   {
       for(int j=1;j<col;j++)
       {	
           if(arr[i][j] == 1)
               dp[i][j] = 0;
           
           if(arr[i][j] == 0)
          dp[i][j] = 1 + std::min(dp[i-1][j],std::min(dp[i-1][j-1],dp[i][j-1])); 
       }
   }
    int max = -1;
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            if(max<dp[i][j])
            {
                max = dp[i][j];
            }
        }
    }
    for(int i=0;i<row;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    
    return max;
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}