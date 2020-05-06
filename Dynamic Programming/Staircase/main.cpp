/*
StairCase Problem
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/
#include<iostream>
using namespace std;


long dp(long *arr,int n)
{
    if(n == 0)
        return 1;
    
    if(n == 1)
        return 1;
    
    if(n == 2)
        return 2;
    
    if(arr[n]!=0)
        return arr[n];
    
    long first = dp(arr,n-1);
	long second = dp(arr,n-2);
    long third = dp(arr,n-3);
    
    arr[n] = first+second+third;
    return first+second+third;
}

long staircase(int n){
	
    long *arr = new long[n+1];

    for(int i=0;i<n;i++)
    {
        arr[i] = 0;
    }
    
    return dp(arr,n);
    
}

int main(){

  int n; 
  cin >> n ;
  cout << staircase(n) << endl;

}


