#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc x<<1
#define rc x<<1|1
const int N=1e5+5,Q=1e5+5,LOG=18;
template <typename T>
inline void read(T &x){
	x=0;char ch=getchar();bool f=false;
	while(!isdigit(ch)){f^=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
	x=f?-x:x;
}
template <typename T>
inline void print(T x){
	if(x<0){putchar('-');x=-x; }
	if(x>9){print(x/10);}
	putchar(x%10+48);
}
int head[N],to[N],minn[N],Next[N],tot,n,q,root;
int fson[LOG][N],len[N];
int dep[N],fa[N],siz[N],son[N];
vector<pair<int,int> > edge[N];
inline bool cmp(pair<int,int> x,pair<int,int> y){return x.first<y.first;}
inline void add(int u,int v){to[++tot]=v;Next[tot]=head[u],head[u]=tot;}
inline void dfs1(int x,int f){
	dep[x]=dep[f]+1;siz[x]=1;fa[x]=f;minn[x]=x;
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		dfs1(y,x);
		siz[x]+=siz[y];minn[x]=min(minn[x],minn[y]);
		edge[x].push_back(make_pair(minn[y],y));
		if(siz[y]>siz[son[x]]){son[x]=y;}
	}
}
int top[N],seg[N],rev[N],dnt;
inline void dfs2(int x){
	top[x]=son[fa[x]]==x? top[fa[x]] : x;
	len[top[x]]++;
	seg[x]=++dnt;rev[dnt]=x;
	if(son[x]){dfs2(son[x]);}
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y!=son[x]){dfs2(y);}
	}
}
struct seg_tree{
	int l,r,sum,lazy;
	#define l(x)	c[x].l
	#define r(x)	c[x].r
	#define sum(x)	c[x].sum
	#define lazy(x)	c[x].lazy
}c[N<<2];
inline void update(int x){sum(x)=sum(lc)+sum(rc);}
inline void build(int x,int l,int r){
	l(x)=l,r(x)=r;
	if(l==r){return;}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	return;
}
inline void change(int x,int d){sum(x)=(r(x)-l(x)+1);lazy(x)=1;}
inline void push_down(int x){if(lazy(x)){change(lc,lazy(x));change(rc,lazy(x));lazy(x)=0;}}
inline void modify_1(int x,int l,int r,int d){
	if(l(x)>=l&&r(x)<=r){change(x,d);return;}
	push_down(x);
	int mid=(l(x)+r(x))>>1;
	if(mid>=l){modify_1(lc,l,r,d);}
	if(mid<r){modify_1(rc,l,r,d);}
	update(x);
	return;
}
inline void modify_2(int x,int l,int d){
	if(l(x)==r(x)){sum(x)+=d;return;}
	push_down(x);
	int mid=(l(x)+r(x))>>1;
	if(mid>=l){modify_2(lc,l,d);}
	else{modify_2(rc,l,d);}
	update(x);
	return;
}
inline int query(int x,int l,int r){
	if(l(x)>=l&&r(x)<=r){return sum(x);}
	push_down(x);
	int mid=(l(x)+r(x))>>1;
	int res=0;
	if(mid>=l){res+=query(lc,l,r);}
	if(mid<r){res+=query(rc,l,r);}
	return res;
}
inline int uptoroot(int x){
	int res=0,tep=0,last=0;
	while(top[x]!=root){
		tep=query(1,seg[top[x]],seg[x]);
		if(tep==seg[x]-seg[top[x]]+1){
			res+=tep;
			last=top[x];
			x=fa[top[x]];
		}
		else{break;}
	}
	tep=query(1,seg[top[x]],seg[x]);
	if(tep==0){modify_2(1,seg[last],-1);}
	else{res+=tep;modify_2(1,seg[x]-tep+1,-1);}
	return res-1;
}
int main(){
	read(n),read(q);
	for(register int i=1;i<=n;++i){
		int u;read(u);
		if(!u){root=i;}
		else{add(u,i);}
	}
	dfs1(root,0);
	dfs2(root);
	int lim=log2(n)+1;
	for(register int i=1;i<=n;++i){
		sort(edge[i].begin(),edge[i].end(),cmp);
		if(!edge[i].empty())	fson[0][i]=edge[i][0].second;
	}
	for(register int j=1;j<=lim;++j){for(register int i=1;i<=n;++i){fson[j][i]=fson[j-1][fson[j-1][i]];}}
	build(1,1,n);
	while(q--){
		int op,num;
		read(op),read(num);
		if(op==1){
			bool flag=false;
			int teproot=root;
			int now=teproot;
			while(!flag){
				now=teproot;
				if(siz[now]-query(1,seg[now],seg[now]+siz[now]-1)==num){flag=true;break;}
				for(register int i=lim;i>=0;--i){
					int y=fson[i][now];
					if(!y){continue;}
					if(siz[y]-query(1,seg[y],seg[y]+siz[y]-1)<num){continue;}
					else if(siz[y]-query(1,seg[y],seg[y]+siz[y]-1)==num){flag=true;now=y;break;}
					else{now=fson[i][now];}
				}
				for(register int i=0;i<edge[now].size();++i){
					int y=edge[now][i].second;
					int tep=query(1,seg[y],seg[y]+siz[y]-1);
					if(siz[y]-tep<num){
						num-=siz[y]-tep;
						modify_1(1,seg[y],seg[y]+siz[y]-1,1);
					}
					else{teproot=y;break;}
				}
			}
			print(now);putchar('\n');
			modify_1(1,seg[now],seg[now]+siz[now]-1,1);
		}
		else{print(uptoroot(num));putchar('\n');}

	}
	return 0;
} 
