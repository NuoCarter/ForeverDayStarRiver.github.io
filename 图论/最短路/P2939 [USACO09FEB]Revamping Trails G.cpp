#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5,K=15,INF=0x3f3f3f3f;
int n,m,k;
int dist[N][K],head[N],edge[M<<1],to[M<<1],tot,Next[M<<1];
bool vis[N][K];
int en,st;
inline void add(int u,int v,int w){Next[++tot]=head[u];head[u]=tot;to[tot]=v;edge[tot]=w;}
struct node{
  int loc,val,cnt;
  friend bool operator < (const node &x,const node &y){
    return x.val==y.val ? x.cnt>y.cnt : x.val>y.val;
  }
};
inline int dj(){
  memset(dist,INF,sizeof(dist));
  memset(vis,false,sizeof(vis));
  priority_queue<node> pq;
  dist[st][0]=0;
  pq.push({st,0,0});
  while(!pq.empty()){
    int x=pq.top().loc,tcnt=pq.top().cnt;pq.pop();
    if(vis[x][tcnt]){continue;}
    if(x==en){return dist[x][tcnt];}
    vis[x][tcnt]=true;
    for(int i=head[x];i;i=Next[i]){
      int y=to[i];
      if(tcnt<k){
        if(dist[y][tcnt+1]>dist[x][tcnt]){
          dist[y][tcnt+1]=dist[x][tcnt];
          pq.push({y,dist[y][tcnt+1],tcnt+1});
        }
      }
      if(dist[y][tcnt]>dist[x][tcnt]+edge[i]){
        dist[y][tcnt]=dist[x][tcnt]+edge[i];
        pq.push({y,dist[y][tcnt],tcnt});
      }
    }
  }
  return -1;
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  st=1,en=n;
  for(int i=1,u,v,w;i<=m;++i){
    scanf("%d%d%d",&u,&v,&w);
    add(u,v,w);add(v,u,w);
  }
  printf("%d\n",dj());
  return 0;
}
