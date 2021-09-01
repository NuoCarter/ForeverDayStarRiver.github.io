#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lc x<<1
#define rc x<<1|1
const int N=3e5+5;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
  return x*f;
}
int n,tot,to[2*N],head[N],Next[N*2],a[N];
inline void add(int u,int v){
  to[++tot]=v;
  Next[tot]=head[u];
  head[u]=tot;
}
int fa[N],dep[N],son[N],size[N];
inline void dfs1(int x,int f){
  size[x]=1,fa[x]=f,dep[x]=dep[f]+1;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y!=f){
      dfs1(y,x);
      size[x]+=size[y];
      if(size[y]>size[son[x]]){son[x]=y;}
    }
  }
  return;
}
int top[N],seg[N],rev[N],dnt;
inline void dfs2(int x){
  if(son[fa[x]]!=x) top[x]=x;
  else top[x]=top[fa[x]];
  seg[x]=++dnt;
  rev[dnt]=x;
  if(son[x]) dfs2(son[x]);
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y!=fa[x]&&y!=son[x]){dfs2(y);}
  }
}
struct node{
  int l,r,sum,lazy;
  #define l(x) c[x].l
  #define r(x) c[x].r
  #define sum(x)  c[x].sum
  #define lazy(x) c[x].lazy
}c[4*N];
inline void update(int x){sum(x)=sum(lc)+sum(rc);}
inline void build(int x,int L,int R){
  l(x)=L,r(x)=R;
  if(L==R){sum(x)=0,lazy(x)=0;return;}
  int mid=(L+R)>>1;
  build(lc,L,mid);
  build(rc,mid+1,R);
  update(x);
  return;
}
inline void change(int x,int d){
  sum(x)+=d*(r(x)-l(x)+1);
  lazy(x)+=d;
  return;
}
inline void push_down(int x){
  if(lazy(x)){
    change(lc,lazy(x));
    change(rc,lazy(x));
    lazy(x)=0;
  }
  return;
}
inline void modify(int x,int L,int R,int d){
  if(l(x)>=L&&r(x)<=R){
    change(x,d);
    return;
  }
  push_down(x);
  int mid=l(x)+r(x)>>1;
  if(mid>=L) modify(lc,L,R,d);
  if(mid<R) modify(rc,L,R,d);
  update(x);
}
inline int query(int x,int L,int R){
  if(l(x)>=L&&r(x)<=R){return sum(x);}
  push_down(x);
  int mid=l(x)+r(x)>>1,ans=0;
  if(mid>=L)  ans+=query(lc,L,R);
  if(mid<R) ans+=query(rc,L,R);
  return ans;
}
inline void LCA(int u,int v){
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){
      modify(1,seg[top[u]],seg[u],1);
      u=fa[top[u]];
    }
    else{
      modify(1,seg[top[v]],seg[v],1);
      v=fa[top[v]];
    }
  }
  if(dep[v]>dep[u]){swap(u,v);}
  modify(1,seg[v],seg[u],1);
}
int main(){
  n=read();
  for(int i=1;i<=n;++i){a[i]=read();}
  for(int i=1,u,v;i<n;++i){
    u=read(),v=read();
    add(u,v),add(v,u);
  }
  dfs1(1,0);
  dfs2(1);
  build(1,1,n);
  for(int i=1;i<n;++i){
    LCA(a[i],a[i+1]);
    modify(1,seg[a[i+1]],seg[a[i+1]],-1);
  }
  for(int i=1;i<=n;++i){
    printf("%d\n",query(1,seg[i],seg[i]));
  }
  return 0;
}
