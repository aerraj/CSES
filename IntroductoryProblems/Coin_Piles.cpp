#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;





int32_t main()
{

    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if((2*a-b)>=0 and(2*b-a)>=0 and (2*a-b)%3==0 and (2*b-a)%3==0)
        {
             cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
return 0;
}
