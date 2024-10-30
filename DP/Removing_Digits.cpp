#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    int n;
    cin>>n;
    int dp[n+1]={0};

    for(int i=1;i<=n;i++)
    {
        string s=to_string(i);
        char maxi=*max_element(s.begin(),s.end());
        int mi=maxi-'0';
        int curr=i-mi;
        dp[i]=1+dp[curr];
    }

  cout<<dp[n]<<endl;
return 0;
}
