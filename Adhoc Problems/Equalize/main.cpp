#include<bits/stdc++.h>
using namespace std;

void flip(int f)
{
f = ~f;
}

int main(){
  int len;
  int cost = 0;
  cin>>len;
  string s,t;
  cin>>s>>t;
for(int i=0;i<len;)
{
if(s[i] != t[i])
{
  if(i+1<len && s[i+1]!=s[i])
    {
      swap(s[i],s[i+1]);
      i+=2;
      cost++;
    }
  else{
    flip(s[i]);
    i++;
    cost++;
  }

}else{
  i++;
}
}
cout<<cost;
  return 0;
}