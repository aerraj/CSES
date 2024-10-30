#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n - 1);
    bool found = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != i + 1)
        {
            cout << i + 1 << " " << endl;
            found = true;
            return 0;
        }
    }
    if (found == false)
        cout << n << endl;

return 0;
}
