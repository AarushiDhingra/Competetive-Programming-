/*
Minimum In SubArray
Send Feedback
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;

void build(int *arr,int *tree,int start,int end,int treeNode)
{
    int mid = (start+end)/2;
    
    if(start == end)
    {
      	tree[treeNode] = arr[start];  
    	return;
    }
    build(arr,tree,start,mid,2*treeNode);
    build(arr,tree,mid+1,end,2*treeNode+1);
    
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
	
}

int query(int *tree,int l,int r,int start,int end,int treeNode)
{
   //query by user is completely outside range
    if(start > r || end < l)
    {
        return INT_MAX;
    }
    //query by user is completely inside the range
    if(start >= l && end <= r)
    {
        return tree[treeNode];
    }
    //query by user partially inside partially outside
  	int mid = (start+end)/2;
    int ans1 = query(tree,l,r,start,mid,2*treeNode);
    int ans2 = query(tree,l,r,mid+1,end,2*treeNode+1);
    
    int ans = min(ans1,ans2);
    return ans;
}

void update(int *arr,int *tree,int indx,int value,int start,int end,int treeNode)
{
    int mid = (start+end)/2;
    
   if(start == end)
    {
        arr[indx] = value;
        tree[treeNode] = value;
        return;
    }
    
    if(indx > mid)
    {
        //right hand side traversal
        update(arr,tree,indx,value,mid+1,end,2*treeNode+1);
    }
        
    else
    {
       //left side traversal 
        update(arr,tree,indx,value,start,mid,2*treeNode);
    }
	
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
  
}
    
    
    
int main() {

	// Write your code here
    int n,q;
    cin>>n>>q;
    int *arr = new int[n];
    
    for(int i = 0;i < n;i++)
    {
        cin>>arr[i];
    }
    
    int *tree = new int[4*n];
    
    int treeNode = 1;
    int start = 0;
    int end = n-1;
    
    build(arr,tree,start,end,treeNode);
    
    
    while(q--)
    {
        int l,r;
        char str;
        cin>>str>>l>>r;
        	if(str == 'q')
        	{
            	int ans = query(tree,l-1,r-1,start,end,treeNode);
                cout<<ans<<endl;
        	}
    		
        	else if(str == 'u')
            {
                update(arr,tree,l-1,r,start,end,treeNode);
            }
    }
    
    return 0;
}