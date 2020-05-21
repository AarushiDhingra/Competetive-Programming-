/*
Min. Absolute Difference In Array
Send Feedback
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
Constraints :
1 <= N <= 10^6
Sample Input :
5
2 9 0 4 5
Sample Input :
1
*/
#include <iostream>
using namespace std;

// arr - input array
// n - size of array
#include<bits/stdc++.h>
#include<algorithm>
int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    std::sort(arr,arr+n);
    int min = INT_MAX;
    for(int i = 0;i < n;i++)
    {
       int diff = abs(arr[i] - arr[i+1]);
        if(diff < min)
        {
            min = diff;
        }
        
    }
    return min;

}


int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	
	return 0;

}
