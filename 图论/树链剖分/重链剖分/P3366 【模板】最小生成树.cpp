#include<bits/stdc++.h>
using namespace std;
int n,k;
int fa[200005];
struct node{
	int  x,y,z;
}e[200005];
int sum,ans;
inline bool cmp(node x,node y){return x.z<y.z;}
inline int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
inline void merge(int x,int y){fa[get(x)]=get(y);}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);sum+=e[i].z;}
	for(int i=1;i<=n;++i){fa[i]=i;}
	sort(e+1,e+k+1,cmp);
	for(int i=1;i<=k;++i){
		int tx=e[i].x;
		int ty=e[i].y;
		if(get(tx)==get(ty)){continue;}
		else{
			ans+=e[i].z;
			merge(tx,ty);
		}
	}
	printf("%d\n",ans);
	return 0;
}
