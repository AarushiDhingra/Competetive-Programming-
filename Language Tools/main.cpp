#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,q;
	cin>>n>>q;
	ll arr[n];
	for(int i = 0;i < n;i++)
	{
	    cin>>arr[i];
	}
	
	sort(arr,arr+n);
	queue<ll> hq;

	while(q--)
	{   int curr_count;
	    cin>>curr_count;
	    int count = 0;
	    int endptr = n-1;
	    ll ans;
	    for(;count < curr_count;count++)
	    {
	        if(endptr >= 0 && (hq.empty() || hq.front() < arr[endptr]))
	        {
	            ans = arr[endptr];
	            endptr--;
	            
	        }
	        else
	        {
	            ans = hq.front();
	            hq.pop();
	        }
	        
	        hq.push(ans/2);
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
