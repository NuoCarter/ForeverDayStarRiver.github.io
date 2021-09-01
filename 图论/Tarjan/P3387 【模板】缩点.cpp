#include<bits/stdc++.h>
using namespace std;
const int N=4e6+5,M=5e6+5;
int n,m,head[N],to[M],Next[M],tot,val[N],from[N];
inline void add(int u,int v){to[++tot]=v,Next[tot]=head[u],from[tot]=u,head[u]=tot;}
int fhead[N],fto[M],ftot,fNext[M],in[N];
inline void add2(int u,int v){fto[++ftot]=v,fNext[ftot]=fhead[u],fhead[u]=ftot;}
int cnt,siz,cntscc,dfn[N],low[N],sta[N],belong[N],dist[N];
int fval[N];
bool vis[N],visscc[N];
inline void tarjan(int x){
  dfn[x]=low[x]=++cnt;
  sta[++siz]=x;vis[x]=true;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(!dfn[y]){tarjan(y);low[x]=min(low[x],low[y]);}
    else if(vis[y]){low[x]=min(low[x],dfn[y]);}
  }
  if(dfn[x]==low[x]){
    cntscc++;
    belong[x]=cntscc;
    fval[cntscc]+=val[x];
    vis[x]=false;
    while(sta[siz]!=x){
      fval[cntscc]+=val[sta[siz]];
      belong[sta[siz]]=cntscc;
      vis[sta[siz--]]=false;
    }
    siz--;
  }
}
inline void topo(){
  queue<int> q;
  for(int i=1;i<=cntscc;++i){
    if(!in[i]){q.push(i);dist[i]=fval[i];}
  }
  while(!q.empty()){
    int x=q.front();q.pop();
    for(int i=fhead[x];i;i=fNext[i]){
      int y=fto[i];
      dist[y]=max(dist[y],dist[x]+fval[y]);
      in[y]--;
      if(in[y]==0){q.push(y);}
    }
  }
  int ans=0;
  for(int i=1;i<=cntscc;++i){ans=max(ans,dist[i]);}
  printf("%d\n",ans);
}
int main(){
  scanf("%d%d",&n,&m);
  for(register int i=1;i<=n;++i){scanf("%d",&val[i]);}
  for(register int i=1;i<=m;++i){int u,v;scanf("%d%d",&u,&v);add(u,v);}
  for(register int i=1;i<=n;++i){if(!dfn[i]){tarjan(i);}}
  for(register int i=1;i<=m;++i){
    if(belong[from[i]]!=belong[to[i]]){
      add2(belong[from[i]],belong[to[i]]);
      in[belong[to[i]]]++;
    }
  }
  topo();
  return 0;
}
