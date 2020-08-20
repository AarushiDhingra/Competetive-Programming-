#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b,a%b);
}

int main()
{
    int x1,x2;
    int a,b;
    cin>>x1>>x2;

    b = min(x1,x2);
    a = max(x1,x2);

    cout<<gcd(a,b);
}
