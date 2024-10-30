#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
const int mod=1e9+7;
 
 
const int N = 2e5 + 5;
vector<int> tree[N];
vector<vector<int>>dp(N,vector<int>(2));
int ans=0;
 
bool isLeaf(int u) {
    return (u != 1 && tree[u].size() == 1);
}
 
void dfs(int u, int p) {
 
vector<int>all;
 
    if (isLeaf(u)) {
       //Base Case       
        dp[u][0]=dp[u][1] = 0;
        return;
    }
 
    for (auto v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        all.push_back(dp[v][0]);
    }
 
    sort(all.rbegin(),all.rend());
    int numsChild=all.size();
    if(numsChild==1)
    {
        dp[u][0]=1+all[0];
        dp[u][1]=0;
    }
    else
    {
        dp[u][0]=1+all[0];
        dp[u][1]=(1+all[0])+1+all[1];
    }
     ans=max(ans,max(dp[u][0],dp[u][1]));
 
}
 
 
 
int32_t main()
{
 
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
 
    dfs(1,-1);
    cout<<ans<<endl;
return 0;
}