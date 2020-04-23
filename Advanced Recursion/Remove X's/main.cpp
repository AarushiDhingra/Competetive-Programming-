#include <bits/stdc++.h>
using namespace std;

void removeX(char s[])
{
  if(s[0] == '\0')
  return;

  if(s[0]!='x')
  {
    removeX(s+1);
  }
  else{
    int i=1;
    for(;s[i]!='\0';i++)
    {
     s[i-1] = s[i]; 
    }
     s[i-1] = s[i];
     removeX(s);
  }
}

int main() {
char str[100];
cout<<"Enter a string"<<endl;
cin>>str;
removeX(str);
cout<<str;
}