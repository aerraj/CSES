#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;





int32_t main()
{
       int n;
    cin >> n;
    cout << n << " ";
    while (n > 1)
    {
        if (n & 1)
        {
            n = n * 3 + 1;
            cout << n << " ";
        }
        else
        {
            n = n / 2;
            cout << n << " ";
        }
    }
    cout << endl;
return 0;
}
