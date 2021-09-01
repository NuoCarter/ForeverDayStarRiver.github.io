#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	x=0;char ch=getchar();bool f=false;
	while(!isdigit(ch))	f|=ch=='-',ch=getchar();
	while(isdigit(ch))	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;return;
}
template <typename T>
inline void print(T x){
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	print(x/10);
	putchar(x%10^48);return;
}
#define int long long
const int N=3e5+3;
int head[N],to[N<<1],Next[N<<1],edge[N<<1],tot=1,n,a[N],q;
inline void Addedge(int u,int v,int w){
	to[++tot]=v,edge[tot]=w,Next[tot]=head[u],head[u]=tot;
	return;
}
//Tree&DP
int fa[N],siz[N],son[N],dep[N],up[N],down[N];
inline void Dfs1(int x,int f){
	dep[x]=dep[f]+1,siz[x]=1,fa[x]=f;
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];if(y==f)	continue;
		down[y]=down[x]+edge[i],up[y]=up[x]+edge[i^1];
		Dfs1(y,x);siz[x]+=siz[y];
		son[x]=siz[son[x]]<siz[y] ? y :son[x];
	}
	return;
}
int top[N];
inline void Dfs2(int x){
	top[x]=son[fa[x]]==x ? top[fa[x]] : x;
	if(son[x])	Dfs2(son[x]);
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==fa[x]||y==son[x])	continue;
		Dfs2(y);
	}
	return;
}
inline int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]>dep[v] ? v: u;
}
//DP
int dp[N][2];
inline int Get(int v,int i){return dp[v][0]-edge[i]-edge[i^1];}
int g[N];
inline void Dfs(int x){
	dp[x][0]=a[x];
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==fa[x])	continue;
		Dfs(y);
		if(Get(y,i)>0)	dp[x][0]+=Get(y,i);
	}
	return;
}
inline void Croot(int x){
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==fa[x])	continue;
		int tmp=0;if(Get(y,i)>0)	tmp=Get(y,i);
		if(dp[x][1]-tmp-edge[i]-edge[i^1]>0) dp[y][1]=dp[y][0]+dp[x][1]-tmp-edge[i]-edge[i^1];
		else dp[y][1]=dp[y][0];
		g[y]=g[x]+dp[y][0]-tmp;
		Croot(y);
	}
	return;
}

signed main(){
	read(n),read(q);
	for(register int i=1;i<=n;++i)	read(a[i]);
	for(register int i=1;i<n;++i){
		int x,y,z1,z2;read(x),read(y),read(z1),z2=z1;
		Addedge(x,y,z1),Addedge(y,x,z2);
	}
	Dfs1(1,0),Dfs2(1);
	Dfs(1);dp[1][1]=dp[1][0];Croot(1);
	while(q--){
		int u,v;read(u),read(v);
		int l=LCA(u,v);
		int ans1=up[u]-up[l]+down[v]-down[l],ans2=g[u]+g[v]-2*g[l]+dp[l][1];
		print(ans2-ans1),putchar('\n');
	}
	return 0;
}
