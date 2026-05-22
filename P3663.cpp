#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k,r,cnt,ans,a[100005],vis[105][105],w[105][105][5];
void dfs(ll x,ll y){
    vis[x][y]=cnt;
    if(x!=1)
        if(!w[x][y][1]&&!vis[x-1][y])
            dfs(x-1,y);
    if(x!=n)
        if(!w[x][y][2]&&!vis[x+1][y])
            dfs(x+1,y);
    if(y!=1)
        if(!w[x][y][3]&&!vis[x][y-1])
            dfs(x,y-1);
    if(y!=n)
        if(!w[x][y][4]&&!vis[x][y+1])
            dfs(x,y+1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>r;
    while(r--){
        ll x,y,z,t;
        cin>>x>>y>>z>>t;
        if(x==z+1)w[x][y][1]=w[z][t][2]=1;
        if(z==x+1)w[x][y][2]=w[z][t][1]=1;
        if(y==t+1)w[x][y][3]=w[z][t][4]=1;
        if(t==y+1)w[x][y][4]=w[z][t][3]=1;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(!vis[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
    while(k--){
        ll u,v;
        cin>>u>>v;
        a[vis[u][v]]++;
    }
    for(ll i=1;i<=cnt-1;i++){
        for(ll j=i+1;j<=cnt;j++){
            ans+=a[i]*a[j];
        }
    }
    cout<<ans;
    return 0;
}