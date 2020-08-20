#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int makeSeive(long long n)
{
    int count = 0;
    bool *isPrime = new bool[n+1];

    for(int i= 0;i < n;i++)
    {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2;i*i < n;i++)
    {
        if(isPrime[i])
        {
            for(int j = i*i;j < n; j+=i)
            {
                 isPrime[j] = false;
            }
        }
    }

    //print prime or not prime
    for(int i = 0; i < n; i++)
    {
        if(isPrime[i])
        count++;
    }
return count;
}

int main(){
	// Write your code here
    long long n;
    cin>>n;
    cout<<makeSeive(n);
	return 0;
}
