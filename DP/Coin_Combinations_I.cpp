#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
int n;
cin>>n;
int t;
cin>>t;
vector<int>c(n);
for(int i=0;i<n;i++)
cin>>c[i];
 
vector<int>dp(t+1,0);
dp[0]=1;
 
for(int i=0;i<=t;i++)
{
    for(int j=0;j<n;j++)
    {
        if(c[j]<=i)
        {
            dp[i]=(dp[i]+dp[i-c[j]])%mod;
        }
    }
}
 
cout<<dp[t]<<endl;
return 0;
}