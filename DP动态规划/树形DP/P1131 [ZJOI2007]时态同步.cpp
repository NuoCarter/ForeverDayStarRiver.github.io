#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int n,head[N],Next[2*N],to[2*N],tot,root;
ll ans,dist[N],edge[N*2];
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}inline ll read_LL(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}
inline void add(int u,int v,ll w){
  Next[++tot]=head[u];
  to[tot]=v;
  edge[tot]=w;
  head[u]=tot;
}
inline void dfs(int x,int fa){
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==fa) continue;
    dfs(y,x);
    dist[x]=max(dist[x],dist[y]+edge[i]);
  }
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==fa) continue;
    ans+=dist[x]-(dist[y]+edge[i]);
  }
}
int main(){
  n=read(),root=read();
  for(int i=1,u,v,w;i<n;++i){
    u=read(),v=read(),w=read_LL();
    add(u,v,w);add(v,u,w);
  }
  dfs(root,0);
  printf("%lld\n",ans);
  return 0;
}
