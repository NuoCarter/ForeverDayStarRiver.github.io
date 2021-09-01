#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
const int N=1e5+5;
int head[N],Next[2*N],to[2*N],tot,n,q;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
	if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void add(int u,int v){
	to[++tot]=v;
	Next[tot]=head[u];
	head[u]=tot;
}
int dep[N],fa[N],size[N],son[N];
inline void dfs1(int x,int f){
	dep[x]=dep[f]+1;
	size[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y!=f){
			dfs1(y,x);
			size[x]+=size[y];
			if(size[y]>size[son[x]]){son[x]=y;}
		}
	}
}
int top[N],seg[N],rev[N],dnt;
inline void dfs2(int x){
	if(son[fa[x]]!=x)	top[x]=x;
	else top[x]=top[fa[x]];
	seg[x]=++dnt;
	rev[dnt]=x;

	if(son[x]){dfs2(son[x]);}

	for(int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y!=fa[x]&&y!=son[x]){dfs2(y);}
	}

}
struct seg_tree{
	int l,r;
	int sum,lazy;
	#define l(x)	c[x].l
	#define r(x)	c[x].r
	#define sum(x)	c[x].sum
	#define lazy(x)	c[x].lazy
}c[4*N];
inline void update(int x){sum(x)=sum(lc)+sum(rc);}
inline void build(int x,int l,int r){
	l(x)=l,r(x)=r;
	if(l==r){
		sum(x)=0;
		lazy(x)=0;
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x);
}
inline void change(int x,int d){
	if(d==1){sum(x)=r(x)-l(x)+1;lazy(x)=1;}
	else{sum(x)=0;lazy(x)=2;}
	return;
}
inline void push_down(int x){
	if(lazy(x)){
		change(lc,lazy(x));
		change(rc,lazy(x));
		lazy(x)=0;
	}
}
inline void modify(int x,int L,int R,int d){
	if(l(x)>=L&&r(x)<=R){
		change(x,d);
		return;
	}
	push_down(x);
	int mid=(l(x)+r(x))>>1;
	if(mid>=L){modify(lc,L,R,d);}
	if(mid<R){modify(rc,L,R,d);}
	update(x);
	return;
}
inline int query(int x,int L,int R){
	if(l(x)>=L&&r(x)<=R){return sum(x);}
	push_down(x);
	int mid=(l(x)+r(x))>>1;
	int res=0;
	if(mid>=L){res+=query(lc,L,R);}
	if(mid<R){res+=query(rc,L,R);}
	return res;
}
inline int to_root_install(int u){
	int ans=0;
	while(top[u]!=1){
		ans+=query(1,seg[top[u]],seg[u]);
		modify(1,seg[top[u]],seg[u],1);
		u=fa[top[u]];
	}
	ans+=query(1,1,seg[u]);
	modify(1,1,seg[u],1);
	return ans;
}
int main(){
	n=read();
	int tep;
	for(int i=2;i<=n;++i){
		tep=read();
		add(tep+1,i);
		add(i,tep+1);
	}
	dfs1(1,0);
	dfs2(1);
	build(1,1,n);
	q=read();
	string op;
	int u;
//	cout<<"?";
	while(q--){
		cin>>op;
		u=read();
		u+=1;
		if(op=="install"){printf("%d\n",dep[u]-to_root_install(u));}
		else{
			printf("%d\n",query(1,seg[u],seg[u]+size[u]-1));
			modify(1,seg[u],seg[u]+size[u]-1,2);
		}
	}
	return 0;
}
/*
7
0 0 0 1 1 5
5
install 5
install 6
uninstall 1
install 4
uninstall 0

*/
