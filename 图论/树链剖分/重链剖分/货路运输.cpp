#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
int n,m;
int q;
int fa_bingchaji[100005],fa[100005],size[100005],dep[100005];
bool vis[100005];
int a[10005],son[10005];
int val[10005];
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}
inline int get(int x){return x==fa_bingchaji[x] ? x : fa_bingchaji[x]=get(fa_bingchaji[x]);}
inline void merge(int x,int y){fa_bingchaji[get(x)]=get(y);}
struct node{int x,y,w;}e[100005];
inline bool cmp(node o,node p){return o.w>p.w;}
int head[10005],Next[100005],to[100005],edge[100005],tot,cnt,dfn[100005];
int top[10005];
inline void add(int u,int v,int w){
  edge[++tot]=w;
  to[tot]=v;
  Next[tot]=head[u];
  head[u]=tot;
}
inline void dfs1(int x,int f){
  dep[x]=dep[f]+1,fa[x]=f,size[x]=1;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==f) continue;
    a[y]=edge[i];
    dfs1(y,x);
    size[x]+=size[y];
    if(size[y]>size[son[x]]){son[x]=y;}
  }
}
inline void dfs2(int x){
  if(son[fa[x]]!=x) top[x]=x;
  else{top[x]=top[fa[x]];}
  val[++cnt]=a[x];
  dfn[x]=cnt;
  if(son[x]){dfs2(son[x]);}
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==fa[x]||y==son[x]) continue;
    dfs2(y);
  }
}

struct dfn_tree{
  int l,r;
  int minn;
  dfn_tree(){minn=0x3f3f3f3f;}
  #define l(x)  c[x].l
  #define r(x)  c[x].r
  #define minn(x) c[x].minn
}c[40005];
inline void update(int x){minn(x)=min(minn(lc),minn(rc));}
inline void build(int x,int l,int r){
  l(x)=l;r(x)=r;
  if(l==r){
    minn(x)=val[l];
    return;
  }
  int mid=(l+r)>>1;
  build(lc,l,mid);
  build(rc,mid+1,r);
  update(x);
  return ;
}
inline void modify(int x,int go,int v){
  if(l(x)==r(x)){
    minn(x)=v;
    return;
  }
  int mid=(l(x)+r(x))>>1;
  if(mid>=go){modify(lc,go,v);}
  else{modify(rc,go,v);}
  update(x);
  return;
}
inline int query(int x,int L,int R){
  if(l(x)>=L&&r(x)<=R){return minn(x);}
  int mid=(l(x)+r(x))>>1;
  int ans=0x3f3f3f3f;
  if(mid>=L){ans=min(ans,query(lc,L,R));}
  if(mid<R){ans=min(ans,query(rc,L,R));}
  return ans;
}
inline int LCA(int u,int v){
  int ans=0x3f3f3f3f;
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){ans=min(ans,query(1,dfn[top[u]],dfn[u]));u=fa[top[u]];}
    else{ans=min(query(1,dfn[top[v]],dfn[v]),ans);v=fa[top[v]];}
  }
  if (dep[u]<dep[v])swap(u,v);
  ans=min(ans,query(1,dfn[v]+1,dfn[u]));
  return ans;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;++i){scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);}
  sort(e+1,e+m+1,cmp);
  for(int i=1;i<=n;++i){fa_bingchaji[i]=i;}
  for(int i=1;i<=m;++i){
      if(get(e[i].x)==get(e[i].y)){continue;}
      add(e[i].x,e[i].y,e[i].w);
      add(e[i].y,e[i].x,e[i].w);
      merge(e[i].x,e[i].y);
  }
  dfs1(1,0);
//  cout<<"cao"<<endl;
  dfs2(1);
//  cout<<"?"<<endl;
  build(1,1,n);
  modify(1,1,0x3f3f3f3f);
  scanf("%d",&q);
  int x,y;
/*  for(int i=1;i<=tot;++i){
    cout<<edge[i]<<endl;
  }*/
  while(q--){
    scanf("%d%d",&x,&y);
    if(get(x)!=get(y)){puts("-1");continue;}
    printf("%d\n",LCA(x,y));
  }
  return 0;
}
