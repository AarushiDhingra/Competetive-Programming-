/*
Find first set bit
Send Feedback
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :
Integer N
Output Format :
Integer M
Sample Input 1 :
7
Sample Output 1 :
1
Sample Input 2 :
12
Sample Output 2 :
4
*/
#include <iostream>

using namespace std;
int returnFirstSetBit(int n){
 
	int z;
  //z is the 2's complement of the number
    z=	~n + 1;   
    int a;
    a= z&n;
    return a;
}

int main() {
	int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}

