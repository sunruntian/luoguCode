#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,k;
ll a[100005];
ll c[100005];
ll len;
ll cnt;
ll ans[100005];
ll kuai[100005];
ll now;
struct Node{
    ll l,r;
    ll id;
}q[1000005];
bool cmp(Node x,Node y){
    if(kuai[x.l]!=kuai[y.l])return kuai[x.l]<kuai[y.l];
    else{
        if(kuai[x.l]&1)return x.r<y.r;
        else return x.r>y.r;
    }
}
void add(ll x){
    now-=c[a[x]]*c[a[x]];
    c[a[x]]++;
    now+=c[a[x]]*c[a[x]];
}
void del(ll x){
    now-=c[a[x]]*c[a[x]];
    c[a[x]]--;
    now+=c[a[x]]*c[a[x]];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    ll len=sqrt(n)+1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i%len==1){
            kuai[i]=kuai[i-1]+1;
        }else{
            kuai[i]=kuai[i-1];
        }
    }
    for(ll i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    ll nl=1,nr=0;
    for(ll i=1;i<=m;i++){
        ll l=q[i].l,r=q[i].r;
        while(nl<l){
            del(nl);
            nl++;
        }
        while(nr>r){
            del(nr);
            nr--;
        }
        while(nl>l){
            nl--;
            add(nl);
        }
        while(nr<r){
            nr++;
            add(nr);
        }
        ans[q[i].id]=now;
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}

