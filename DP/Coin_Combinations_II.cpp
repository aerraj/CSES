
#include<bits/stdc++.h>
#define MOD 1000000007 
using namespace std;
int main(){
int n;
cin>>n;
int t;
cin>>t;
vector<int>c(n);
for(int i=0;i<n;i++)
cin>>c[i];

vector<int>dp(t+1,0);
dp[0]=1;
 for(int j=0;j<n;j++)
{
   for(int i=0;i<=t;i++)
    {
        if(c[j]<=i)
        {
            dp[i]=(dp[i]+dp[i-c[j]])%MOD;
        }
    }
}
cout<<dp[t]<<endl;
    return 0;
}
