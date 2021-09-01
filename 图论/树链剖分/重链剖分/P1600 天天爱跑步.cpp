#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=3e5+5,LOG=30;
int head[N],to[N<<1],Next[N<<1],tot,n,m;
inline void add(int u,int v){to[++tot]=v,Next[tot]=head[u],head[u]=tot;}
int dep[N],fa[N][30],w[N];
inline void dfs1(int x,int f){
	fa[x][0]=f,dep[x]=dep[f]+1;
	for(int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==f)	continue;
		dfs1(y,x);
	}
}
inline int LCA(int x,int y){
	if(x==y){return x;}
	if(dep[x]<dep[y]){swap(x,y);}
	int tep=(int)log2(dep[x]-dep[y]);
	for(int i=tep;i>=0;--i){
		if(dep[fa[x][i]]>=dep[y]){x=fa[x][i];}
		if(x==y){return x;}
	}
	tep=(int)log2(dep[x]);
	for(int i=tep;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){x=fa[x][i],y=fa[y][i];}
	}
	return fa[x][0];
}
struct player{int st,en;}a[M];
vector<int> op[N][4];int c[N<<1][3],ans1[N],ans2[N];
inline void dfs(int x){
	int cnt=c[w[x]+dep[x]][0];
	int siz1=op[x][0].size();
	int siz2=op[x][1].size();
	for(int i=0;i<siz1;++i){c[op[x][0][i]][0]++;}
	for(int i=0;i<siz2;++i){c[op[x][1][i]][0]--;}
	for(int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==fa[x][0])	continue;
		dfs(y);
	}
	ans1[x]=c[w[x]+dep[x]][0]-cnt;
}
inline void dfs2(int x){
	int cnt=c[w[x]-dep[x]+n][1];
	int siz1=op[x][2].size();
	int siz2=op[x][3].size();
	for(int i=0;i<siz1;++i){c[op[x][2][i]][1]++;}
	for(int i=0;i<siz2;++i){c[op[x][3][i]][1]--;}
	for(int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==fa[x][0])	continue;
		dfs2(y);
	}
	ans2[x]=c[w[x]-dep[x]+n][1]-cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs1(1,0);
	for(int i=1;i<=n;++i){
		for(int j=1;(1<<j)<=dep[i];++j){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	// puts("??????");
	for(register int i=1;i<=n;++i){scanf("%d",&w[i]);}
	for(register int i=1;i<=m;++i){
		scanf("%d%d",&a[i].st,&a[i].en);
		int lca=LCA(a[i].st,a[i].en);
		op[a[i].st][0].push_back(dep[a[i].st]);
		op[fa[lca][0]][1].push_back(dep[a[i].st]);
		op[lca][3].push_back(dep[a[i].st]-2*dep[lca]+n);
		op[a[i].en][2].push_back(dep[a[i].st]-2*dep[lca]+n);
		// puts("?????");
	}
	dfs(1);
	dfs2(1);
	// puts("??????");
	for(int i=1;i<=n;++i){
		printf("%d ",ans1[i]+ans2[i]);
	}


	return 0;
}
