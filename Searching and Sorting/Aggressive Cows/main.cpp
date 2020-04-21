/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool check(int c,long long positions[],int n, long long distance)
{
    int count=1;
    long long last_pos = positions[0];
    for(int i=1;i<n;i++)
    {
        if(positions[i]-last_pos >= distance)
        {
            last_pos = positions[i];
            count++;
        }
        	if(count==c)
            {
                return true;
            }
    }
return false;
}
int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        long long positions[n];
        for(int i=0;i<n;i++)
        {
            cin>>positions[i];
        }
        sort(positions,positions+n);
        long long start = 0;
        long long end = positions[n-1] - positions[0];
        long long ans = -1;
        
        while(start<=end)
        {
            long long mid = (start + end)/2;
            if(check(c,positions,n,mid)){
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
            cout<<ans;
    }

    return 0;
}