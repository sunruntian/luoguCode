#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
const ll N=16; 
ll a[N][N]; 
ll f[N][N*N][N][N][2][2]; 
ll n,m,k; 
struct Node{
	ll i,j,l,r,x,y;
}path[N][N*N][N][N][2][2];
void dfs(Node p){
	if(p.j==0)return;
	dfs(path[p.i][p.j][p.l][p.r][p.x][p.y]);
	for(ll i=p.l;i<=p.r;i++){
		cout<<p.i<<" "<<i<<"\n";
	} 
}
int main(){ 
	cin>>n>>m>>k; 
	for(ll i=1;i<=n;i++) 
		for(ll j=1;j<=m;j++) 
			cin>>a[i][j]; 
	for(ll i=1;i<=n;i++) 
		for(ll j=1;j<=k;j++) 
			for(ll l=1;l<=m;l++) 
				for(ll r=l;r<=m;r++){ 
					ll sum=0; 
					for(ll p=l;p<=r;p++)sum+=a[i][p]; 
					if(j<r-l+1)continue; 
					ll res=-1; 
					for(ll p=l;p<=r;p++) 
						for(ll q=p;q<=r;q++) 
							if(f[i-1][j-(r-l+1)][p][q][1][1]>res) 
								res=f[i-1][j-(r-l+1)][p][q][1][1],path[i][j][l][r][1][1]={i-1,j-(r-l+1),p,q,1,1}; 
					f[i][j][l][r][1][1]=sum+res; 
					
					res=-1; 
					for(ll p=1;p<=l;p++) 
						for(ll q=l;q<=r;q++) 
							for(ll x=0;x<=1;x++) 
								if(f[i-1][j-(r-l+1)][p][q][x][1]>res) 
									res=f[i-1][j-(r-l+1)][p][q][x][1],path[i][j][l][r][0][1]={i-1,j-(r-l+1),p,q,x,1}; 
					f[i][j][l][r][0][1]=sum+res; 
					
					res=-1;
					for(ll p=l;p<=r;p++) 
						for(ll q=r;q<=m;q++) 
							for(ll x=0;x<=1;x++) 
								if(f[i-1][j-(r-l+1)][p][q][1][x]>res) 
									res=f[i-1][j-(r-l+1)][p][q][1][x],path[i][j][l][r][1][0]={i-1,j-(r-l+1),p,q,1,x}; 
					f[i][j][l][r][1][0]=sum+res; 
					
					res=-1; 
					for(ll p=1;p<=l;p++) 
						for(ll q=r;q<=m;q++) 
							for(ll x=0;x<=1;x++) 
								for(ll y=0;y<=1;y++) 
									if(f[i-1][j-(r-l+1)][p][q][x][y]>res) 
										res=f[i-1][j-(r-l+1)][p][q][x][y],path[i][j][l][r][0][0]={i-1,j-(r-l+1),p,q,x,y}; 
					f[i][j][l][r][0][0]=sum+res; 
					
				} 
	ll ans=-1; 
	Node p;
	for(ll i=1;i<=n;i++) 
		for(ll l=1;l<=m;l++) 
			for(ll r=l;r<=m;r++) 
				for(ll x=0;x<=1;x++) 
					for(ll y=0;y<=1;y++) 
						if(f[i][k][l][r][x][y]>ans) 
							ans=f[i][k][l][r][x][y],p={i,k,l,r,x,y}; 
	cout<<"Oil : "<<ans<<"\n";
	dfs(p);
	return 0; 
} 