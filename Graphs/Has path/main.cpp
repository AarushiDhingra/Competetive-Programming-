/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
*/

#include <iostream>
#include <queue>
using namespace std;

bool haspath(int **edges,int n,int start,int end,bool *visited)
{
  queue<int> q;
  bool found = false;

  q.push(start);
  visited[start] = true;

  while(!q.empty())
  {
    int curr = q.front();
    q.pop();
    if(curr == end)
    found = true;
for(int i =0;i < n;i++)
{
  if(i == curr)
  continue;
  if(edges[curr][i] == 1 && !visited[i])
  {
    visited[i] = true;
    q.push(i);
  }
}

  }
  return found;
}


int main(){
  int n;
  int e;
  cin >> n >> e;

  int** edges = new int*[n];
  for(int i=0; i<n; i++){
    edges[i]=new int[n];
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  for(int i=0; i<e; i++){
    int f,s;
    cin >> f >> s;
    edges[f][s]=1;
    edges[s][f]=1;
  }

  bool* visited = new bool[n];

  for(int i=0; i<n; i++){
    visited[i]=false;
  }
    int st,end;
    cin>>st>>end;

  if(haspath(edges,n,st,end,visited))
  cout<<"true";
  else
  cout<<"false";


  for(int i = 0;i <n;i++)
  {
    delete [] edges[i];
  }

delete [] edges;
delete [] visited;
  return 0;
}