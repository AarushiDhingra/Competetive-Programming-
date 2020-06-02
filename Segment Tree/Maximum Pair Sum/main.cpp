/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int maximum;
    int smaximum;
};

void build(int *arr,node *tree,int start,int end,int treeNode)
{
    //base case
    if(start == end)
    {
        tree[treeNode].maximum = arr[start];
        tree[treeNode].smaximum = INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    
    build(arr,tree,start,mid,2*treeNode);
    build(arr,tree,mid+1,end,2*treeNode+1);
    
    tree[treeNode].maximum = max(tree[2*treeNode].maximum,tree[2*treeNode+1].maximum);
    tree[treeNode].smaximum = min(max(tree[2*treeNode].smaximum,tree[2*treeNode+1].maximum),max(tree[2*treeNode].maximum,tree[2*treeNode+1].smaximum));
    
}

void update(int *arr,node *tree,int start,int end,int indx,int value,int treeNode)
{
    //base case
	if(start == end)
    {
        tree[treeNode].maximum = value;
        tree[treeNode].smaximum = INT_MIN;
        return ;
    }
    
    else
    {
    int mid = (start+end)/2;
    
    if(indx > mid)
    {
        update(arr,tree,mid+1,end,indx,value,2*treeNode+1);
    }
    else
    {
        update(arr,tree,start,mid,indx,value,2*treeNode);
    }
    
    tree[treeNode].maximum = max(tree[2*treeNode].maximum,tree[2*treeNode+1].maximum);
    tree[treeNode].smaximum = min(max(tree[2*treeNode].smaximum,tree[2*treeNode+1].maximum),max(tree[2*treeNode].maximum,tree[2*treeNode+1].smaximum));
	return;
    }}

node query(int *arr,node *tree,int start,int end,int l,int r,int treeNode)
{
	//outside range
    if(start > r || end < l)
    {
        node zero;
        zero.maximum = INT_MIN;
        zero.smaximum = INT_MIN;
        return zero;
    }
    //inside range 
    else if(start >= l && end <= r)
        return tree[treeNode];
     
    int mid = (start+end)/2;
    node q1 = query(arr,tree,start,mid,l,r,2*treeNode);
    node q2 = query(arr,tree,mid+1,end,l,r,2*treeNode+1);
    node q3;
    q3.maximum = max(q1.maximum,q2.maximum);
    q3.smaximum = min(max(q1.maximum,q2.smaximum),max(q1.smaximum,q2.maximum));
    
    return q3;
}

int main() {
	int n;
    cin>>n;
    int *input = new int[n];
    node *tree = new node[4*n];
    for(int i = 0;i < n;i++)
    {
        cin>>input[i];
    }
    
    int start = 0;
    int end = n-1;
    int treeNode = 1;
    
    build(input,tree,start,end,treeNode);
    int q;
    cin>>q;
    while(q--)
    {
        char st;
        cin>>st;
        int l,r;
        cin>>l>>r;
        	if(st == 'q' || st == 'Q')
        	{
            node ans = query(input,tree,start,end,l-1,r-1,treeNode);
            int sum = 0;
                sum = ans.maximum+ans.smaximum;
                cout<<sum<<endl;
        	}
        	else if(st == 'u' || st == 'U')
        	{
            update(input,tree,start,end,l-1,r,treeNode);
        	}
    }
}