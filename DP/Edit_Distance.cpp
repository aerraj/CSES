#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int dp[n+1][m+1]={0};
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++)
    {
      dp[0][j]=j;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]= 1+ min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    cout<<dp[n][m]<<endl;
return 0;
}
