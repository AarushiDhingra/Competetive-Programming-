#include <iostream>
#include <string>
using namespace std;

bool isMatching(string s,string p)
{
  int m = s.length();
  int n = p.length();

  for(int i = 0;i <(m - n);i++)
  {
    bool isFound = true;
    for(int j = 0;j < n;j++)
    {
      if(s[i+j] != p[j])
      {
        isFound = false;
          break;
      }
    }
    if(isFound)
    return true;
  }

  return false;
}

int main() {
  string s,p;
  cin>>s;
  cin>>p;

if(isMatching(s,p))
cout<<"Matching";

else 
cout<<"Not matching";
return 0;
}