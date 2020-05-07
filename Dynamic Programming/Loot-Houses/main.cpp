/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/
#include <iostream>
using namespace std;

int getMaxMoney(int arr[], int n){
int *dp = new int[n];
	dp[0] = arr[0];
    dp[1] = std::max(arr[0],arr[1]);
    
    for(int i=2;i<n;i++)
    {
        dp[i] = std::max(dp[i-2]+arr[i],dp[i-1]);
    }
return dp[n-1];
}

int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

