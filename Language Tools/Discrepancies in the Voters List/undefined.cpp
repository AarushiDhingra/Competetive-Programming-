#include <bits/stdc++.h>
using namespace std;

vector<int> getVoters(int arr[],int n)
{
    vector<int> voters;
    sort(arr,arr+n);
    for(int i = 0; i<n;)
    {
        int count = 0;
        int j = i;
        while(j<n && arr[i] == arr[j])
        {
        count++;
        j++;
        }
         
         if(count >= 2)
         {
            voters.push_back(arr[i]);   
         }
         
         i = j;
             
    }
    return voters;
}

int main() {
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int n = n1+n2+n3;
	int arr[n];
	for(int i = 0;i < n;i++)
	{
	    cin>>arr[i];
	}
    
    std::vector<int> voters = getVoters(arr,n) ;
    
    cout<<voters.size()<<endl;
    for(int i  = 0;i<voters.size();i++)
    {
        cout<<voters[i]<<endl;
    }
	return 0;
}
