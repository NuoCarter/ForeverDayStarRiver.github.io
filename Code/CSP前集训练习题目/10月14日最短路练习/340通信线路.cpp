#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,P=1e3+5,M=1e4+5,INF=0x3f3f3f3f;
int dist[N][P],n,p,k,tot,head[N],Next[M<<2],to[M<<2],edge[M<<2];bool vis[N][P];
inline void add(int u,int v,int w){to[++tot]=v,Next[tot]=head[u],head[u]=tot,edge[tot]=w;}
struct node{int cnt,val,loc;friend bool operator < (const node &x,const node &y){return x.val!=y.val ? x.val>y.val : x.cnt>y.cnt ;}};
priority_queue<node> pq;
inline int dj(){
  memset(dist,INF,sizeof(dist));
  pq.push({0,0,1});
  while(!pq.empty()){
    node tep=pq.top();pq.pop();
    if(tep.loc==n){return dist[n][tep.cnt];}
    if(vis[tep.loc][tep.cnt]) continue;
    vis[tep.loc][tep.cnt]=true;
    int x=tep.loc,sum=tep.cnt;
    for(int i=head[x];i;i=Next[i]){
      int y=to[i];
      if(edge[i]==0){
        if(sum<k){
          if(dist[y][sum+1]>tep.val){dist[y][sum+1]=tep.val;pq.push({sum+1,tep.val,y});}
          else{continue;}
        }
      }
      else{if(dist[y][sum]>max(tep.val,edge[i])){dist[y][sum]=max(tep.val,edge[i]);pq.push({sum,max(tep.val,edge[i]),y});}}
    }
  }
  return -1;
}
int main(){
  scanf("%d%d%d",&n,&p,&k);
  for(int i=1,u,v,w;i<=p;++i){
    scanf("%d%d%d",&u,&v,&w);
    add(u,v,w);add(v,u,w);add(u,v,0);add(v,u,0);
  }
  int ans=dj();
  printf("%d\n",ans);
  return 0;
}
