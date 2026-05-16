#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x,y,k;
        cin>>x>>y>>k;
        if(x==0&y==0)cout<<0<<"\n";
        else if(x==0)cout<<((k%y==0)?1:0)<<"\n";
        else if(y==0)cout<<((k%x==0)?1:0)<<"\n";
        else{
            ll m=max(x,y);
            cout<<k/m<<"\n";
        }
    }
    return 0;
}