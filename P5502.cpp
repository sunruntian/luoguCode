#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll n,a[N],ans;
struct Block{ll v,l;};
Block l[100],r[100];
ll lc,rc;

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

void get_left(ll L,ll mid){
    lc=0;
    ll g=0;
    for(ll i=mid;i>=L;i--){
        g=gcd(g,a[i]);
        if(lc==0||l[lc].v!=g){
            l[++lc]={g,mid-i+1};
        }else{
            l[lc].l=mid-i+1;
        }
    }
}

void get_right(ll mid,ll R){
    rc=0;
    ll g=0;
    for(ll i=mid+1;i<=R;i++){
        g=gcd(g,a[i]);
        if(rc==0||r[rc].v!=g){
            r[++rc]={g,i-mid};
        }else{
            r[rc].l=i-mid;
        }
    }
}

void dfs(ll L,ll R){
    if(L==R){
        ans=max(ans,a[L]);
        return;
    }
    ll mid=(L+R)/2;
    dfs(L,mid);
    dfs(mid+1,R);
    
    get_left(L,mid);
    get_right(mid,R);
    
    for(ll i=1;i<=lc;i++){
        for(ll j=1;j<=rc;j++){
            ans=max(ans,gcd(l[i].v,r[j].v)*(l[i].l+r[j].l));
        }
    }
}

int main(){
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    dfs(1,n);
    cout<<ans;
    return 0;
}