#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    int X,N;
    cin>>N>>X;

    int price[N];

    for(int i=0;i<N;i++)
    cin>>price[i];

    int pages[N];
    for(int i=0;i<N;i++)
    cin>>pages[i];

    
        vector<int> dp(X + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int C = X; C > 0; C--) {
            if (price[i] > C)
                continue;
            dp[C] = max(dp[C], pages[i] + dp[C - price[i]]);
        }
    }
    cout<<dp[X];
return 0;
}
