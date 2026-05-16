#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll a[250];
ll f[250][250];ll ans;
ll vis[250][250];
ll dfs(ll l,ll r){
    if(l>r)return 0;
    if(vis[l][r])return f[l][r];
    vis[l][r]=1;
    for(ll i=l;i<r;i++){
        ll t=dfs(l,i);
        if(t==dfs(i+1,r)&&t!=0){
            f[l][r]=max(f[l][r],t+1);
        }
    }
    return f[l][r];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)f[i][i]=a[i],vis[i][i]=1;
    dfs(1,n);
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans;
    return 0;
}