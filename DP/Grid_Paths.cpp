#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    int n;
    cin>>n;
   
    vector<vector<char>>dp(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dp[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        if(dp[i][0]=='.')
        vis[i][0]=1;
        else
        break;
    }
     for(int i=0;i<n;i++)
    {
        if(dp[0][i]=='.')
        vis[0][i]=1;
        else
        break;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i][j]=='.')
            {
                vis[i][j]=(vis[i-1][j] % mod +vis[i][j-1] % mod)%mod;
            }
        }
    }
     cout<<vis[n-1][n-1]%mod<<endl;
return 0;
}
