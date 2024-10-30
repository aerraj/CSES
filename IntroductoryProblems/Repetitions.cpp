#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    string s;
    cin >> s;
    int maxl = 0;
    char ch = s[0];
    int currcnt = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (ch == s[i])
            currcnt++;
        else
        {
            ch = s[i];
            currcnt = 0;
        }
        maxl = max(maxl, currcnt);
    }
    cout << maxl + 1 << endl;

return 0;
}
