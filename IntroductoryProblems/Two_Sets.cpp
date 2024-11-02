#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int32_t main()
{
int n;
cin>>n;
long long sum=(n*(n+1))/2;
    if((n+1)%4==0 or (n%4==0))
    {
        cout<<"YES"<<endl;

               set<int> set1, set2;
        vector<int> vis(n + 1, 0);

        ll currsum = 0;
        ll max_element = n;

        while (currsum < sum / 2) {
            ll remsum = sum / 2 - currsum;
            if (remsum > max_element) {
                set1.insert(max_element);
                vis[max_element] = 1;
                currsum += max_element;
                max_element--;
            }
            else {

                set1.insert(remsum);
                vis[remsum] = 1;
                currsum = sum / 2;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                set2.insert(i);
            }
        }

        // Print the size and elements of set1
        cout << set1.size() << "\n";
        for (auto x : set1) {
            cout << x << " ";
        }
        cout << "\n";

        // Print the size and elements of set2
        cout << set2.size() << "\n";
        for (auto x : set2) {
            cout << x << " ";
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
return 0;
}
