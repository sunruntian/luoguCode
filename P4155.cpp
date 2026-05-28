#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
struct Node{
    ll l,r,id;
}a[400005];
bool cmp(Node x,Node y){
    return x.l<y.l;
}
ll nxt[25][400005],ans[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        if(a[i].r<a[i].l){
            a[i].r+=m;
        }
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n;i++){
        a[i+n]=a[i];
        a[i+n].l=a[i].l+m;
        a[i+n].r=a[i].r+m;
    }
    ll pos=1;
    for(ll i=1;i<=2*n;i++){
        while(pos<=2*n&&a[pos].l<=a[i].r){
            pos++;
        }
        nxt[0][i]=pos-1;
    }
    for(ll i=1;i<=23;i++){
        for(ll j=1;j<=2*n;j++){
            nxt[i][j]=nxt[i-1][nxt[i-1][j]];
        }
    }
    for(ll i=1;i<=n;i++){
        ll r=a[i].l+m,t=i;
        ans[a[i].id]=1;
        for(ll j=23;j>=0;j--){
            if(nxt[j][t]!=0&&a[nxt[j][t]].r<r){
                ans[a[i].id]+=(1ll<<j);
                t=nxt[j][t];
            }
        }
        ans[a[i].id]+=1;
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}





