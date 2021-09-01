#include<bits/stdc++.h>
using namespace std;
int n;
double l;
double eps=1e-10;

double f[1005][1005];

const int INF=0x3f3f3f3f;
double ud[1005];
struct node{
	double x,b;
}a[1005];
int mypath[1005];
inline bool check(double x){
	for(int i=1;i<=n;++i){ud[i]=INF;}
	ud[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			f[i][j]=sqrt(fabs(a[i].x-a[j].x-l))-x*a[i].b;
			//ud[i]=min(ud[i],f[i][j]+ud[j]);
			if(dp[i]>f[i][j]+dp[j]){mypath[i]=j;dp[i]=f[i][j]+dp[j];}
		}
	}
	return ud[n]<=0;
}
int pre[1005];
inline void print(int x){
	if(!x){return;}
	print(mypath[x]);
	printf("%d ",x);
}
int main(){
	// freopen("hiking.in","r",stdin);
	// freopen("hiking.out","w",stdout);
	scanf("%d%lf",&n,&l);
	double L=0,R=0;
	double suma=0,sumb=0;
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&a[i].x,&a[i].b);
		suma+=a[i].x;
	}
	R=1e7;
	double mid,res;
	while(L+eps<R){
		mid=(L+R)/2.0;
		if(check(mid)){
			R=mid;
			res=mid;
		}
		else{L=mid;}
	}
	print(n);
	return 0;
}
/*
5 9
10 10
20 10
30 1
31 5
40 10

*/
