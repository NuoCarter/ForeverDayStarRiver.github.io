#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
#define lc x<<1
#define rc x<<1|1
int n,head[N],to[N<<1],Next[N<<1],tot,st[N];
char op[10];
ll val[N];
inline int read_INT(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
  return x*f;
}
inline ll read_LL(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
  return x*f;
}

inline void add(int u,int v,ll w){Next[++tot]=head[u];head[u]=tot;to[tot]=v;if(tot&1){val[u]=w;}}
int fa[N],son[N],size[N],dep[N];
inline void dfs1(int x,int f){
  fa[x]=f,size[x]=1,dep[x]=dep[f]+1;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==f)  continue;
    dfs1(y,x);
    size[x]+=size[y];
    if(size[y]>size[son[x]]){son[x]=y;}
  }
}
int seg[N],rev[N],dnt,top[N];
inline void dfs2(int x){
  if(son[fa[x]]==x){top[x]=top[fa[x]];}
  else{top[x]=x;}
  seg[x]=++dnt;rev[dnt]=x;
  if(son[x]){dfs2(son[x]);}
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==son[x]||y==fa[x]) continue;
    dfs2(y);
  }
}
struct SEG_Tree{
  int l,r;ll  maxn,lazy1,lazy2;
  #define l(x)  c[x].l
  #define r(x)  c[x].r
  #define maxn(x)  c[x].maxn
  #define lazy1(x) c[x].lazy1
  #define lazy2(x)  c[x].lazy2
}c[N<<2];
inline void update(int x){maxn(x)=max(maxn(lc),maxn(rc));}
inline void build(int x,int L,int R){
    l(x)=L,r(x)=R;
    if(L==R){maxn(x)=val[rev[L]];lazy1(x)=0,lazy2(x)=-1;return;}
    int mid=L+R>>1;
    build(lc,L,mid);
    build(rc,mid+1,R);
    update(x);
    return;
}
inline void change(int x,ll d,int op){
  if(op){
    maxn(x)+=d;
    lazy1(x)+=d;
    return;
  }
  else{
    lazy1(x)=0;
    maxn(x)=d;
    lazy2(x)=d;
  }
}
inline void push_down(int x){
  if(lazy2(x)!=-1){
    change(lc,lazy2(x),0);change(rc,lazy2(x),0);lazy2(x)=-1;
  }
  if(lazy1(x)){
    change(lc,lazy1(x),1),change(rc,lazy1(x),0);
    lazy1(x)=0;
  }
}
inline void modify(int x,int L,int R,ll d,int op){
  if(l(x)>=L&&r(x)<=R){
    change(x,d,op);
    return;
  }
  push_down(x);int mid=l(x)+r(x)>>1;
  if(mid>=L){modify(lc,L,R,d,op);}
  if(mid<R){modify(rc,L,R,d,op);}
  update(x);
  return;
}
inline ll query(int x,int L,int R){
  if(l(x)>=L&&r(x)<=R){return maxn(x);}
  push_down(x);int mid=l(x)+r(x)>>1;ll res=0;
  if(mid>=L){res=max(res,query(lc,L,R));}
  if(mid<R){res=max(query(rc,L,R),res);}
  return res;
}
inline void modify_LCA(int u,int v,ll d,int op){
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){modify(1,seg[top[u]],seg[u],d,op);u=fa[top[u]];}
    else{modify(1,seg[top[v]],seg[v],d,op);v=fa[top[v]];}
  }
  if(dep[v]>dep[u]){swap(v,u);}
  modify(1,seg[v],seg[u],d,op);
}
inline ll query_LCA(int u,int v){
  ll res=0;
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){res=max(res,query(1,seg[top[u]],seg[u]));u=fa[top[u]];}
    else{res=max(res,query(1,seg[top[v]],seg[v]));v=fa[top[v]];}
  }
  if(dep[v]>dep[u]) swap(u,v);
  res=max(res,query(1,seg[v],seg[u]));
  return res;
}
int main(){
  n=read_INT();ll w;
  for(int i=1,u,v;i<n;++i){
    u=read_INT(),v=read_INT(),w=read_LL();
    add(u,v,w),add(v,u,w);
    st[i]=u;
  }
  dfs1(1,0);
  dfs2(1);
  build(1,1,n);
  while(scanf("%s",op+1)!=EOF){
    if(op[1]=='S'){return 0;}int u,v,k;ll w;
    if(op[1]=='C'&&op[2]=='h'){
      k=read_INT(),w=read_LL();
      u=st[k];
      modify(1,seg[u],seg[u],w,0);
    }
    else if(op[1]=='C'){
      u=read_INT(),v=read_INT(),w=read_LL();
      modify_LCA(u,v,w,0);
    }
    else if(op[1]=='A'){
      u=read_INT(),v=read_INT(),w=read_LL();
      modify_LCA(u,v,w,1);
    }
    else{
      u=read_INT(),v=read_INT();
      printf("%d\n",query_LCA(u,v));
    }
  }
  return 0;
}
