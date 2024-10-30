#include <bits/stdc++.h>
#define int long long int
using namespace std;
int n=2e5+5;
vector<vector<int>> tree(n); 
vector<int>subSize(n+1,0); //dp values to compute
 
bool isLeaf(int u)
{
    if(u!=1 && tree[u].size()==1) return true;
    return false;
}
 
 
void dfs(int u,int p)//computes the dp values
{
 
    if(isLeaf(u))
    {
        subSize[u]=1;
        return;
    }
    for(auto it: tree[u])
    {
            if(it==p)continue;
            dfs(it,u);
    }
 
    for(int v:tree[u])
    {
        if(v==p)continue;
        subSize[u]+=subSize[v];
    }
 
    subSize[u]++;
}
 
int32_t main()
{
    int n;
    cin >> n;
    
    // tree.resize(n+1); 
    int x;
    // creating the tree
    for(int i = 2; i <=n; i++)
    {
        cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    
   
    dfs(1, -1); 
    
    // Output the result
    for(int i = 1; i <= n; i++)
    {
        cout << subSize[i]-1 << " ";
    }
    
    return 0;
}