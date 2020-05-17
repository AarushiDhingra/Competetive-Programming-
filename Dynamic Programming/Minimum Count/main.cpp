/*
Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/
#include<iostream>
#include<algorithm>
using namespace std;


int minCount(int n){
    
 	if(n < 4)
    	 return n;
    
    int count[n+1];
    count[0] = 0;
    count[1] = 1;
    count[2] = 2;
    count[3] = 3;
    for(int i = 4;i <= n;i++)
    {
        int ans = i;
        for(int j = 1;j <= (i/2);j++)
        {
           int k = i - (j*j);
            if(k>=0)
            {
                ans = min(ans,count[k]+1);
            }
        }
        
        count[i] = ans;
    }
	  
 return count[n];   
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}

