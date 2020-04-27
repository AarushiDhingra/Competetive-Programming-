/*
Turn off 1st set bit
Send Feedback
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8
*/
#include <iostream>

using namespace std;

int turnOffFirstSetBit(int n){
	int z =  ~n+1;
  //z is the 2s compliment of the number
    int a = z^n;
  //XORing a and z
    int final = n&a;
    return final;
    
}

int main() {
	int n;

	cin >> n;
	
	cout<< turnOffFirstSetBit(n) <<endl;
		
	return 0;
}

