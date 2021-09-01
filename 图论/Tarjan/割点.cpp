#include<bits/stdc++.h>
using namespace std;
int head[100005],Next[200005],to[200005],tot;
inline void add(int u,int v){
  to[++tot]=v;
  Next[tot]=head[u];
  head[u]=tot;
}
int n,m,num;
int root;
int res[100005];
int low[100005],dfn[100005];
inline void dfs(int x){
  low[x]=dfn[x]=++num;
  int tep=0;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(!dfn[y]){
      dfs(y);
      low[x]=min(low[x],low[y]);
      if(low[y]>=dfn[x]){
        tep++;
        if(x!=root||tep>1){res[x]=true;}
      }
    }
    else{low[x]=min(low[x],dfn[y]);}
  }
}
int main(){
  scanf("%d%d",&n,&m);
  int u,v;
  for(int i=1;i<=m;++i){
      scanf("%d%d",&u,&v);
      add(u,v);
      add(v,u);
  }
  for(int i=1;i<=n;++i){
    if(!dfn[i]){
      root=i;
      dfs(i);
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i){

    if(res[i]){ans++;}
  }
  printf("%d\n",ans);
  for(int i=1;i<=n;++i){
    if(res[i]){
      printf("%d ",i);
    }
  }
  return 0;
}
