#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc x<<1
#define rc x<<1|1

const int N=2e5+5;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
  return x*f;
}
int head[N],tot,Next[N],to[N];
inline void add(int u,int v){
  Next[++tot]=head[u];
  head[u]=tot;
  to[tot]=v;
}

int fa[N],dep[N],size[N],son[N],dfn[N],rev[N],dnt,val[N],top[N];
ll mod;
inline void dfs1(int x,int f){
  fa[x]=f,dep[x]=dep[f]+1;
  size[x]=1;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y!=f){
      dfs1(y,x);
      size[x]+=size[y];
      if(size[y]>size[son[x]]){
        son[x]=y;
      }
    }
  }
  return;
}
inline void dfs2(int x){
  if(son[fa[x]]!=x){top[x]=x;}
  else{top[x]=top[fa[x]];}
  dfn[x]=++dnt;
  rev[dnt]=x;
  if(son[x]){dfs2(son[x]);}
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y!=fa[x]&&y!=son[x]){dfs2(y);}
  }
}
struct seg_tree{
  int l,r;
  ll sum,lazy;
  #define l(x)  c[x].l
  #define r(x)  c[x].r
  #define sum(x)  c[x].sum
  #define lazy(X) c[x].lazy
}c[800005];
inline void update(int x){sum(x)=(sum(lc)+sum(rc))%mod;}
inline void build(int x,int L,int R){
  l(x)=L,r(x)=R;
  if(L==R){
    sum(x)=val[rev[L]]%mod;
    return;
  }
  int mid=(L+R)>>1;
  build(lc,L,mid);
  build(rc,mid+1,R);
  update(x);
}
inline void change(int x,ll d){
  sum(x)=(sum(x)+(r(x)-l(x)+1)*d)%mod;
  lazy(x)=(lazy(x)+d)%mod;
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
  int mid=(l(x)+r(x))>>1;
  if(mid>=L){modify(lc,L,R,d);}
  if(mid<R){modify(rc,L,R,d);}
  update(x);
  return;
}
inline ll query(int x,int L,int R){
  if(l(x)>=L&&r(x)<=R){return sum(x);}
  push_down(x);
  int mid=(l(x)+r(x))>>1;
  ll ans=0;
  if(mid>=L){ans+=query(lc,L,R);ans%=mod;}
  if(mid<R){ans+=query(rc,L,R);ans%=mod;}
  return ans;
}
inline void modify_LCA(int u,int v,int d){
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){
      modify(1,dfn[top[u]],dfn[u],d);
      u=fa[top[u]];
    }
    else{
      modify(1,dfn[top[v]],dfn[v],d);
      v=fa[top[v]];
    }
  }
  if(dep[u]<dep[v])  swap(u,v);
  modify(1,dfn[v],dfn[u],d);
  return;
}
inline ll query_LCA(int u,int v){
  ll ans=0;
  while(top[u]!=top[v]){
    if(dep[top[u]]>dep[top[v]]){
      ans=(ans+query(1,dfn[top[u]],dfn[u]))%mod;
      u=fa[top[u]];
    }
    else{
      ans=(ans+query(1,dfn[top[v]],dfn[v]))%mod;
      v=fa[top[v]];
    }
  }
  if(dep[u]<dep[v]) swap(u,v);
  ans=(ans+query(1,dfn[v],dfn[u]));
  return ans;
}
int n,m,root;
int main(){
  n=read(),m=read(),root=read(),mod=read();
  for(int i=1;i<=n;++i){
    val[i]=read();
  }
  int u,v;
  for(int i=1;i<n;++i){
    u=read(),v=read();
    add(u,v);
    add(v,u);
  }
  dfs1(root,0);
  dfs2(root);
  build(1,1,n);
  int op,x,y;
  ll z;
  while(m--){
  //  cout<<"wocao?"<<endl;
    op=read();
    if(op==1){
      x=read(),y=read(),z=read();
      modify_LCA(x,y,z);
    }
    else if(op==2){
      x=read(),y=read();
      printf("%lld\n",query_LCA(x,y));
    }
    else if(op==3){
      x=read(),z=read();
      modify(1,dfn[x],dfn[x]+size[x]-1,z);
    }
    else{
      x=read();
      printf("%lld\n",query(1,dfn[x],dfn[x]+size[x]-1));
    }
  }
  return 0;
}
