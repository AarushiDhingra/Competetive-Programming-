#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll kadane(int arr[],int n)
{
    ll curr_sum = 0;
    ll best_so_far = INT_MIN;
    
    for(int i = 0;i < n;i++)
    {
        curr_sum += arr[i];
        
        if(curr_sum > best_so_far)
        best_so_far = curr_sum;
        
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    
    return best_so_far;
}

ll maxSubarraySum(int arr[],int n,int k)
{
  ll kadanes_sum = kadane(arr,n); 
  
  if(k == 1)
  {
  return kadanes_sum;
  }
  
  ll best_prefix_sum = INT_MIN;
  ll best_suffix_sum = INT_MIN;
  ll curr_prefix_sum = 0;
  ll curr_suffix_sum = 0;
  
  //best prefix sum 
  for(int i = 0;i < n;i++)
  {
      curr_prefix_sum = curr_prefix_sum + arr[i];
      best_prefix_sum = max(best_prefix_sum,curr_prefix_sum);
  }
  
  ll totalSum = curr_prefix_sum;
  //best suffix sum
  
  for(int i = n-1;i >= 0;i--)
  {
      curr_suffix_sum  = curr_suffix_sum + arr[i];
      best_suffix_sum = max(best_suffix_sum,curr_suffix_sum);
  }
  
  ll ans=0;
  
  if(totalSum < 0){
      ans = max(best_prefix_sum+best_suffix_sum,kadanes_sum);
  
  }
  else{
  ans = max(best_suffix_sum+best_prefix_sum+totalSum*(k-2),kadanes_sum);
  }
  
  return ans;
}
int main() {
    int t;
    cin>>t;
    while(t != 0)
    {
        int n,k;
        cin>>n>>k;
        int input[n];
        for(int i = 0;i < n;i++)
        {
            cin>>input[i];
        }
        cout<<maxSubarraySum(input,n,k);
        cout<<endl;
        t--;
    }
	return 0;
}