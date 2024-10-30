//कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int MOD = 1e9 + 7;
//datatypes
#define int long long int
#define ll long long
#define lld long double
#define very ios_base::sync_with_stdio(false);
#define fast cin.tie(NULL);
#define IO cout.tie(NULL);
typedef pair<int, int> pii;
typedef vector<int> vi;
#define forn for (int i = 0; i < n; i++)

void solve()
{
int n;
  cin>>n;
  vi v(n);
  forn
  cin>>v[i];
  int ans=0;
  for(int i=1;i<n;i++)  
  {
      int k = v[i - 1] - v[i];
       if (k>0)
      {
          ans = ans + k;
          v[i]=v[i]+k;
    }
  }
  cout<<ans<<endl;

 
}
int32_t main() {
very fast IO
solve();
}