#include<bits/stdc++.h>
using namespace std;
const int N=25005,M=1e5+5,INF=0x3f3f3f3f;
int head[N],st,to[M<<1],Next[M<<1],edge[M<<1],tot,n,r,p,hav[N],dist[N];
bool vis[N];deque<int> q;
inline void add(int u,int v,int w){to[++tot]=v;Next[tot]=head[u];head[u]=tot;edge[tot]=w;}
inline void spfa(){
  memset(dist,INF,sizeof(dist));
  memset(vis,false,sizeof(vis));
  dist[st]=0;
  vis[st]=true;
  q.push_back(st);
  while(!q.empty()){
    int x=q.front();
    q.pop_front();
    vis[x]=false;
    for(int i=head[x];i;i=Next[i]){
      int y=to[i];
      if(dist[y]>dist[x]+edge[i]){
        dist[y]=dist[x]+edge[i];
        if(!q.empty()&&dist[y]<=dist[q.front()]){q.push_front(y);}
        else{q.push_back(y);}
      }
    }
  }

}
int main(){
  scanf("%d%d%d%d",&n,&r,&p,&st);
  for(int i=1,u,v,w;i<=r;++i){scanf("%d%d%d",&u,&v,&w);add(u,v,w),add(v,u,w);}
  for(int i=1,u,v,w;i<=p;++i){scanf("%d%d%d",&u,&v,&w);add(u,v,w);}
  spfa();
  for(int i=1;i<=n;++i){
    if(dist[i]==INF){puts("NO PATH");}
    else{printf("%d\n",dist[i]);}
  }
  return 0;
}
