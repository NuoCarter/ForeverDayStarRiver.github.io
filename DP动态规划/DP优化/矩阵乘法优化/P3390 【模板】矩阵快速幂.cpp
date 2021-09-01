#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{ll a[106][106];node(){memset(a,0,sizeof(a));}};
const ll mod=1e9+7;
ll p;
int n;
node operator * (const node &x,const node &y){
	node tep;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				tep.a[j][k]=(tep.a[j][k]+x.a[j][i]*y.a[i][k])%mod;
			}
		}
	}
	return tep;
}
inline node quick_pow(node b,ll p){
	node res;
	for(int i=1;i<=n;++i){res.a[i][i]=1;res.a[i][i]%=mod;}
	while(p){
		if(p&1){res=res*b;}
		b=b*b;
		p>>=1;
	}
	return res;
}

int main(){
	node b;
	scanf("%d%lld",&n,&p);
	for(int i=1;i<=n;++i){for(int j=1;j<=n;++j){scanf("%lld",&b.a[i][j]);}}
	node ans=quick_pow(b,p);
	for(int i=1;i<=n;++i){for(int j=1;j<=n;++j){printf("%d ",ans.a[i][j]);}puts("");}
	return 0;
}
