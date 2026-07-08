#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,ans=1e18;
ll dp[1<<21][21];
ll a[22][22];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][1]=0;
    for(ll i=0;i<(1<<n);i++){
        for(ll j=1;j<=n;j++){
            if(((1<<j-1)&i)==0){
                for(ll k=1;k<=n;k++){
                    if(((1<<k-1)&i)){
                        dp[i|(1<<j-1)][j]=min(dp[i|(1<<j-1)][j],dp[i][k]+a[k][j]);
                    }
                }
            }
        }
    }
    for(ll i=2;i<=n;i++){
        ans=min(ans,dp[(1<<n)-1][i]+a[i][1]);
    }
    cout<<ans;
    return 0;
}