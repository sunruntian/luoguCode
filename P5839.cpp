#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ch(char c){
    return c-'a'+1;
}
ll n,m,K;
ll dist[30][30];
ll sum[30][100005];
ll now[30];
ll dp[100005];
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>K;
    cin>>s;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++){
            cin>>dist[i][j];
        }
    }
    for(ll k=1;k<=m;k++){
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+dist[ch(s[j-1])][i];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    memset(now,0x3f,sizeof(now));
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        if(i>=K){
            ll j=i-K;
            for(ll k=1;k<=m;k++){
                now[k]=min(now[k],dp[j]-sum[k][j]);
            }
            for(ll k=1;k<=m;k++){
                dp[i]=min(dp[i],now[k]+sum[k][i]);
            }
        }
    }
    cout<<dp[n];
    return 0;
}