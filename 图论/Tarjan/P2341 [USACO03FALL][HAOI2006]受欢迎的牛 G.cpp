#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=1e5+5;
struct ed{int from,to;}edge[M];
int head[N],n,m,to[M],Next[M],tot;
inline void add(int u,int v){
  Next[++tot]=head[u];
  head[u]=tot;
  to[tot]=v;
  edge[tot].from=u,edge[tot].to=v;
}
int sta[N],dfn[N],low[N],dnt,siz;bool vis[N];
int sizscc[N],belong[N],cntscc,out[N];
inline void tarjan(int x){
  sta[++siz]=x;vis[x]=true;dfn[x]=low[x]=++dnt;
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(!dfn[y]){tarjan(y);low[x]=min(low[x],low[y]);}
    else if(vis[y]){low[x]=min(low[x],dfn[y]);}
  }
  if(dfn[x]==low[x]){
    belong[x]=++cntscc;
    sizscc[cntscc]++;
    vis[x]=false;
    while(sta[siz]!=x){
      sizscc[cntscc]++;
      vis[sta[siz]]=false;
      belong[sta[siz]]=cntscc;
      siz--;
    }
    siz--;
  }
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1,u,v;i<=m;++i){
    scanf("%d%d",&u,&v);
    add(u,v);
  }
  for(int i=1;i<=n;++i){if(!dfn[i]){tarjan(i);}}
  for(int i=1;i<=m;++i){
    int x=edge[i].from,y=edge[i].to;
    if(belong[x]!=belong[y]){out[belong[x]]++;}
  }
  int ansorder=0,anscnt=0;
  for(int i=1;i<=cntscc;++i){
    if(!out[i]){
      anscnt++;
      ansorder=i;
    }
  }
  if(anscnt!=1){puts("0");}
  else{printf("%d\n",sizscc[ansorder]);}
  return 0;
}
