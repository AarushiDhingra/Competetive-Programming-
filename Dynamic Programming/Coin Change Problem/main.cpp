/*
Coin Change Problem
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/
#include<iostream>
using namespace std;

int coin_change(int n,int k,int *denominations,int **output)
{
    if(n == 0)
        return 1;
    
    if(k == 0)
        return 0;
    
    if(n < 0)
        return 0;
    
    if(output[n][k] > -1)
        return output[n][k];
    
    int first = coin_change(n-denominations[0],k,denominations,output);
    int second = coin_change(n,k-1,denominations+1,output);
    
    output[n][k] = first+second;
    return first+second;

}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int n = value;
    int k = numDenominations;
    
    int** output = new int *[n+1];
    //adding rows to the array of pointers, making it 2D array 
    for(int i=0;i<n+1;i++)
    {
        output[i] = new int[k+1];
    }
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            output[i][j] = -1;
        }
    }
    
    return coin_change(n,k,denominations,output);
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


