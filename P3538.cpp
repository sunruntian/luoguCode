#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll n,m;
ll g[500005],h[500005],p[500005];
string s;
bool vis[500005];
vector<ll>pri;
void ola(){
    for(ll i=2;i<=n;i++){
        if(!vis[i]) pri.push_back(i),g[i]=i;
        for(ll j=0;j<pri.size()&&pri[j]*i<=n;j++){
            vis[pri[j]*i]=1,g[pri[j]*i]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
}
ll sub(ll l,ll r){return ((h[r]-h[l-1]*p[r-l+1])%MOD+MOD)%MOD;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    s=" "+s;
    ola();
    for(ll i=1;i<=n;i++)h[i]=(h[i-1]*29+s[i]-'a'+1)%MOD;
    p[0]=1; for(ll i=1;i<=n;i++)p[i]=p[i-1]*29%MOD;
    cin>>m;
    while(m--){
        ll l,r,len,ans;
        cin>>l>>r;
        ans=len=r-l+1;
        if(sub(l+1,r)==sub(l,r-1)){cout<<"1\n";continue;}
        while(len>1){
            if(sub(l+ans/g[len],r)==sub(l,r-ans/g[len]))ans/=g[len];
            len/=g[len];
        }
        cout<<ans<<"\n";
    }
    return 0;
}