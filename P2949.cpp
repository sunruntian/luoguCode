#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,ans;
pair<ll,ll> a[100005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1);
	priority_queue<ll,vector<ll>,greater<ll>> q;
	for(ll i = 1; i <= n; i ++){
		if(a[i].first <= q.size()){
			if(a[i].second>q.top()){
				ans-=q.top();
				ans+=a[i].second;
				q.pop();
				q.push(a[i].second);
			}
		}else q.push(a[i].second),ans+=a[i].second;
	}
    cout<<ans<<"\n";
	return 0;
}
