#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	x=0;char ch=getchar();bool f=false;
	while(!isdigit(ch)){if(ch=='-'){f=true;}ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return ;
}
template <typename T>
inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
	return ;
}
const int N=4e5+5;
int n,m,q,a[N],root[N],cnt,len,b[N];
int nex[N<<1],to[N<<1],head[N],idx;
int fa[N][18],dep[N],Fa[N],siz[N];
inline int Get(int x){return x==Fa[x]?x:Fa[x]=Get(Fa[x]);}
inline void Addedge(int u,int v){
	nex[++idx]=head[u];
	to[idx]=v;
	head[u]=idx;
	return ;
}
struct SGTree{
	int ls,rs,val,sum;
	#define ls(x) t[x].ls
	#define rs(x) t[x].rs
	#define val(x) t[x].val
	#define sum(x) t[x].sum
}t[N*150];
inline void Pushup(int x){sum(x)=sum(ls(x))+sum(rs(x));return ;}
inline void Modify(int &x,int pre,int l,int r,int pos,int v){
	x=++cnt;
	t[x]=t[pre];sum(x)++;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(pos<=mid) Modify(ls(x),ls(pre),l,mid,pos,v);
	else Modify(rs(x),rs(pre),mid+1,r,pos,v);
	return ;
}
inline void Update(int x,int f){
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=16;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	Modify(root[x],root[f],1,len,a[x],1);
	return ;
}
int QueryLca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=16;i>=0;i--) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=16;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline int QueryKth(int u,int v,int lca,int falca,int l,int r,int k){
	if(l==r) return l;
	int mid=(l+r)>>1,lsum=sum(ls(u))+sum(ls(v))-sum(ls(lca))-sum(ls(falca));
	if(k<=lsum) return QueryKth(ls(u),ls(v),ls(lca),ls(falca),l,mid,k);
	else return QueryKth(rs(u),rs(v),rs(lca),rs(falca),mid+1,r,k-lsum);
}
inline void Build(int x,int f){
	Update(x,f);
	for(int i=head[x];i;i=nex[i]){
		int y=to[i];
		if(y==f) continue;
		Build(y,x);
	}
	return ;
}
inline void Link(int u,int v){
	int x=Get(u),y=Get(v);
	if(siz[x]<siz[y]) swap(u,v),swap(x,y);
	siz[x]+=siz[y],Fa[y]=x;
	Addedge(u,v),Addedge(v,u);
	Build(v,u);
	return ;
}
bool vis[N];
inline void dfs(int x,int f){
	vis[x]=true;Update(x,f);
	for(int i=head[x];i;i=nex[i]){
		int y=to[i];
		if(y==f) continue;
		dfs(y,x);
	}
	return ;
}
int main(){
	int test;read(test);
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++) read(a[i]),Fa[i]=i,siz[i]=1,b[i]=a[i];
	sort(b+1,b+n+1);len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+len+1,a[i])-b,Modify(root[i],0,1,len,a[i],1);
	for(int i=1;i<=m;i++){
		int u,v;read(u),read(v);
		Addedge(u,v);Addedge(v,u);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
	int las=0;
	for(int i=1;i<=q;i++){
		char op[5];int u,v,w;
		scanf("%s",op);
		if(op[0]=='Q'){
			read(u),read(v),read(w);
			u^=las,v^=las,w^=las;int LCA=QueryLca(u,v);
			las=b[QueryKth(root[u],root[v],root[LCA],root[fa[LCA][0]],1,len,w)];
			write(las),putchar('\n');
		}
		else{
			read(u),read(v);u^=las,v^=las;
			Link(u,v);
		}
	}
	return 0;
}
