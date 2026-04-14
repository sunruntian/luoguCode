#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll lowbit(ll x){
	return x&-x;
}
ll bit[2000005];ll n,c,m;
ll last2[2000005],last1[2000005];
ll a[2000005];
struct Node{
    ll l,r,id;
}q[2000005];
ll ans[2000005];
void add(ll x,ll k){
    for(ll i=x;i<=n;i+=lowbit(i))
        bit[i]+=k;
}
ll sum(ll k){
    ll ret=0;
    for(ll i=k;i>0;i-=lowbit(i))
        ret+=bit[i];
    return ret;
}
ll query(ll l,ll r){
    return sum(r)-sum(l-1);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>c>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+m+1,[](Node a,Node b){
        return a.r<b.r;
    });
    ll pos=1;
    for(ll i=1;i<=m;i++){
        while(pos<=q[i].r){
            ll t=a[pos];
            if(last2[t])add(last2[t],-1);
            if(last1[t])add(last1[t],1);
            last2[t]=last1[t];
            last1[t]=pos;
            pos++;
        }
        ans[q[i].id]=query(q[i].l,q[i].r);
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}