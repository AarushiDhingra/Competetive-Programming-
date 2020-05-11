/*
Hasan and Trip
Send Feedback
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/
#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
using namespace std;

struct city
{
    int x;
    int y;
    int happy;
};

double calcDist(city a,city b)
{
    double ans = 0;
    long long X = (long long) pow(a.x-b.x,2);
    long long Y = (long long) pow(a.y-b.y,2);
    
    ans = (double)sqrt(X+Y);
    return ans;
}

double calcHappy(vector<city> v,int n)
{
    vector<double> dp(n,0);
    dp[0] = v[0].happy;
    for(int i=1;i<n;i++)
    {
        double temp = INT_MIN;
        for(int j=0;j<i;j++)
        {
            temp = max(temp,dp[j]+v[i].happy-calcDist(v[i],v[j]));
        }
        
        dp[i] = temp;
    }
    
    return dp[n-1];
}
int main()
{
    int n,xi,yi,fi;
    cin>>n;
    std::vector<city> v;
    city temp;
    for(int i =0;i<n;i++)
    {
        cin>>xi;
        cin>>yi;
        cin>>fi;
        temp.x = xi;
        temp.y = yi;
        temp.happy = fi;
        v.push_back(temp);
    }
  cout<<fixed<<setprecision(6)<<calcHappy(v,n);      
}