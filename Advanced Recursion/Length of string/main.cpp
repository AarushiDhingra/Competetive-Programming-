#include <iostream>
using namespace std;

int length(char s[])
{
  if(s[0]=='\0')
  return 0;

  int stringSmaller =  length(s+1);
  return 1+stringSmaller;
}
int main() {
char str[100];
cout<<"Enter a string"<<endl;
cin>>str;
int l = length(str);
cout<<l;
}