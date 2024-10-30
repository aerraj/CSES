
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int n,T;
    cin>>n>>T;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    cin>>coins[i];
    vector<int> prev(T + 1, 1e9);
    vector<int> cur(T + 1, 0);

    //base case being filled in previous state 
    for (int i = 0; i <= T; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
    }
    //previous state is dp[i-1][j] helpful to calculate dp[i][j]
    
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            int notTake = prev[target];
            int take = 1e9;
            if (coins[ind] <= target)
                take = 1 + cur[target - coins[ind]];
            cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    int ans = prev[T];
    if (ans >= 1e9)
        cout<<-1;
        else
    cout<<ans;
    return 0;
}
