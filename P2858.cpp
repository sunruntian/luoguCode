#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll v[1005],f[1005][1005];
ll dfs(ll l,ll r,ll d){
    if(l>r)return 0;
    if(f[l][r]) return f[l][r];
    f[l][r]=max(dfs(l+1,r,d+1)+v[l]*d,dfs(l,r-1,d+1)+v[r]*d);
    return f[l][r];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>v[i];
    cout<<dfs(1,n,1);
    return 0;
}