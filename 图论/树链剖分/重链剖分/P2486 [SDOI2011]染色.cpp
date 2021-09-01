#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
const int N=1e5+5,M=1e5+5;
int head[N],to[M<<1],Next[M<<1],tot,n,m;char op[3];
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
  return x*f;
}
inline void add(int u,int v){
  to[++tot]=v;
  Next[tot]=head[u];
  head[u]=tot;
}
int fa[N],dep[N],size[N],son[N],val[N];
inline void dfs1(int x,int f){
  size[x]=1,dep[x]=dep[f]+1,fa[x]=f;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==f)  continue;
    dfs1(y,x);
    size[x]+=size[y];
    if(size[y]>size[son[x]]){son[x]=y;}
  }
}
int top[N],seg[N],rev[N],dnt;
inline void dfs2(int x){
  if(son[fa[x]]==x){top[x]=top[fa[x]];}
  else{top[x]=x;}
  seg[x]=++dnt;
  rev[dnt]=x;
  if(son[x]){dfs2(son[x]);}
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==fa[x]||y==son[x]) continue;
    dfs2(y);
  }
}
struct seg_treee{
  int l,r,lcol,rcol,cnt,lazy;
  #define l(x)  c[x].l
  #define r(x)  c[x].r
  #define lcol(x) c[x].lcol
  #define rcol(x) c[x].rcol
  #define cnt(x)  c[x].cnt
  #define lazy(x) c[x].lazy
}
inline void update(int x){cnt(x)=rcol(lc)==lcol(rc) ? cnt(lc)+cnt(rc)-1 : cnt(lc)+cnt(rc);lcol=lcol(lc),rcol=rcol(rc);}
inline void build(int x,int l,int r){
  l(x)=l,r(x)=r;
  if(l==r){cnt(x)=1;lcol=val[rev[l]],rcol=val[rev[l]];return;}
  int mid=(l+r)>>1;
  build(lc,l,mid);
  build(rc,mid+1,r);
  update(x);
}
inline void change(int x,int d){cnt(x)=1,lcol(x)=d,rcol(x)=d;lazy(x)=d;}
inline void push_down(int x){if(lazy(x)){change(lc,lazy(x)),change(rc,lazy(x));lazy(x)=0;}}
inline void modify(int x,int l,int r,int d){
  if(l(x)>=l&&r(x)<=r){change(x,d);return;}
  push_down(x);
  int mid=l(x)+r(x)>>1;
  if(mid>=l)  modify(lc,l,r,d);
  if(mid<r) modify(rc,l,r,d);
  update(x);
}
inline int query(int x,int l,int r){
  if(l(x)>=l&&r(x)<=r){return cnt(x);}
  push_down(x);
  int mid=l(x)+r(x)>>1,totcnt=0;
  if(mid>=l)  totcnt+=query(lc,l,r);
  if(mid<r) totcnt+=query(rc,l,r);
  return totcnt;
}
inline void modify_uv(int u,int v,int d){
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){modify(1,seg[top[u]],seg[u],d);u=fa[top[u]];}
    else{modify(1,seg[top[v]],seg[v],d);v=fa[top[v]];}
  }
  dep[u]>dep[v] ? modify(1,seg[v],seg[v],d) : modify(1,seg[u],seg[v],d);
  return;
}
inline void query_uv(int u,int v){
  int res=0;
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){res+=query(1,seg[top[u]],seg[u]);u=fa[top[u]];}
    else{res+=query(1,seg[top[v]],seg[v]);v=fa[top[v]];}
  }
}
int main(){
  n=read();
  for(register int i=1;i<=n;++i){val[i]=read();}
  for(register int i=1,u,v;i<n;++i){u=read(),v=read();add(u,v),add(v,u);}
  dfs1(1,0);
  dfs2(1);
  build(1,1,n);
  while(m--){
    scanf("%s",op+1);
    if()
  }
  return 0;
}
