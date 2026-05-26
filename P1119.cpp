#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[205][205];
ll t[205];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(a,0x3f,sizeof a);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>t[i];
    }
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u++,v++;
        a[u][v]=w;
        a[v][u]=w;
    }
    ll q;
    cin>>q;
    ll pos=1;
    while(q--){
        ll x,y,t0;
        cin>>x>>y>>t0;
        x++,y++;
        if(t[x]>t0||t[y]>t0){
            cout<<"-1\n";
            continue;
        }
        for(ll k=pos;k<=n;k++){
            if(t[k]<=t0){
                pos++;
                for(ll i=1;i<=n;i++){
                    for(ll j=1;j<=n;j++){
                        if(a[i][j]>a[i][k]+a[k][j]){
                            a[i][j]=a[i][k]+a[k][j];
                        }
                    }
                }
            }else{
                break;
            }
        }
        if(a[x][y]==a[0][0])cout<<"-1\n";
        else cout<<a[x][y]<<"\n";
    }
    return 0;
}