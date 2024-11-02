#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;

int32_t main()
{
    int n;
    cin>>n;
    cout << 0 << endl;
    for (long long i = 2 ; i <= n ; i++) {
      cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << endl;
    }
return 0;
}
