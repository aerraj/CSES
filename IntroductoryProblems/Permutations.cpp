#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int32_t main()
{
     int n;
    cin>>n;
    if(n==1)
    cout<<1<<endl;
    else if(n>1 and n<=3)
    cout<<"NO SOLUTION"<<endl;
    else
    {
        vector<int> ans;
        for(int i=2;i<=n;i+=2)
        {
              ans.push_back(i);
        }
        for (int i = 1; i <= n; i += 2)
        {
            ans.push_back(i);
        }
        for(auto it:ans)
        cout<<it<<" ";
        cout<<endl;
    }

return 0;
}
