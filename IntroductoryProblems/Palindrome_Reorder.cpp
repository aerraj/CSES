#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    map<char, int> mp;
    int oddc = 0;
    char one;
    string s;
    cin >> s;
    
    for (char it : s) {
        mp[it]++;
    }
    
    for (auto it : mp) {
        if (it.second % 2 != 0) {
            one = it.first;
            mp[one]--;
            oddc++;
        }
    }
    
    if (oddc > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    
    string s1 = "";
    if (oddc == 1) s1 += one;
    
    string left = "";
    for (auto it : mp) {
        string temp(it.second / 2, it.first);
        left += temp;
    }
    
    string right = left;
    reverse(right.begin(), right.end());
    s1 = left + s1 + right;
    
    cout << s1 << endl;
    return 0;
}
