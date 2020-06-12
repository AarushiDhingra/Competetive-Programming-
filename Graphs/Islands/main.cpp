/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;



void helper(int **adj,int start,int n,bool *visited)
{
    visited[start] = true;
    for(int i = 0;i < n;i++)
    {
         if(start == i)
            continue;
        
       if (adj[start][i] == 1 && !visited[i])
		{
			helper(adj,i,n,visited);
		}
       
    }
    return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	bool *visited = new bool[n+1];
    for(int i = 0;i < n;i++)
    {
        visited[i] = false;
    }
    
    int **adj = new int*[n];
    for(int i = 0;i<n;i++)
    {
        adj[i] = new int[n];
    }
     for(int i = 0; i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
          adj[i][j] = 0;
        }
    }
    
    for(int i = 0; i<m;i++)
    {
          adj[u[i]-1][v[i]-1] = 1;
          adj[v[i]-1][u[i]-1] = 1;
    }
 	//int start = 0;
    //helper(adj,start,n,visited);
    int count = 0;
    for(int i = 0;i < n;i++)
    {
    if(!visited[i])
        {
            helper(adj,i,n,visited);
        	i = 0;
            count++;
        }
    }
return count;    
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
