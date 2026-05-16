#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,D;
struct Node{
    ll x,y;
}a[100005];
bool cmp(Node x,Node y){
    return x.x<y.x;
}
ll qmax[100005],qmin[100005];
ll h1,t1,h2,t2;
bool check(ll W){
    h1=0,t1=-1;
    h2=0,t2=-1;
    ll j=1;
    for(ll i=1;i<=n;i++){
        while(j<=n&&(h1>t1||h2>t2||a[qmax[h1]].y-a[qmin[h2]].y<D)){
            while(h1<=t1&&a[qmax[t1]].y<=a[j].y)t1--;
            qmax[++t1]=j;
            while(h2<=t2&&a[qmin[t2]].y>=a[j].y)t2--;
            qmin[++t2]=j;
            j++;
        }
        if(h1<=t1&&h2<=t2&&a[qmax[h1]].y-a[qmin[h2]].y>=D){
            if(a[j-1].x-a[i].x<=W)return true;
        }
        if(h1<=t1&&qmax[h1]==i)h1++;
        if(h2<=t2&&qmin[h2]==i)h2++;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>D;
    for(ll i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    ll maxy=a[1].y,miny=a[1].y;
    for(ll i=2;i<=n;i++){
        maxy=max(maxy,a[i].y);
        miny=min(miny,a[i].y);
    }
    if(maxy-miny<D){
        cout<<-1<<endl;
        return 0;
    }
    ll l=0,r=1000005,ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}