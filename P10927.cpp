#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll e[105][105];
ll dist[105][105];
ll split[105][105];
vector<ll>ans;
ll mn=1e18;
vector<ll> path(ll u,ll v){
    if(split[u][v]==0){
        return {u,v};
    }
    ll mid=split[u][v];
    auto l=path(u,mid);
    auto r=path(mid,v);
    l.pop_back();
    l.insert(l.end(),r.begin(),r.end());
    return l;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    memset(e,0x3f,sizeof e);
    for(ll i=1;i<=n;i++)dist[i][i]=e[i][i]=0;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        if(w<e[u][v]){
            e[u][v]=e[v][u]=w;
            dist[u][v]=dist[v][u]=w;
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=k-1;i++){
            for(ll j=i+1;j<=k-1;j++){
                if(dist[i][j]==dist[0][0]&&e[i][k]==dist[0][0]&&e[k][j]==dist[0][0])continue;
                ll t=dist[i][j]+e[i][k]+e[k][j];
                if(t<mn){
                    mn=t;
                    ans=path(i,j);
                    ans.push_back(k);
                }
            }  
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    split[i][j]=k;
                }
            }
        }
    }
    if(mn==1e18){
        cout<<"No solution."<<"\n";
    }
    else{
        for(auto i:ans)cout<<i<<" ";
    }
    return 0;
}