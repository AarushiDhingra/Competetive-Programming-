#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long arr[n];
    for(int i = 0;i < n;i++)
    {
      cin>>arr[i];
    }
    long lp=1;
    long product[n];
    for(int i = 0;i < n;i++)
    {
      product[i] = lp;
      lp = lp*arr[i]; 
    }
    long rp = 1;
    for(int i = n-1;i>=0;i--)
    {
        product[i] = product[i]*rp;
        rp = rp*arr[i];
    }

    for(int i = 0;i < n;i++)
    {
      cout<<product[i]<<" ";
    }
  }
  return 0;
}