#include<bits/stdc++.h>
using namespace std;
const int N=55,POW=35,INF=0x3f3f3f3f;
int n,m;
bool edge[N][N][POW];
int dist[N][N];
int main(){
  scanf("%d%d",&n,&m);
  memset(dist,INF,sizeof(dist));
  for(int i=1,u,v;i<=m;++i){
    scanf("%d%d",&u,&v);
    edge[u][v][0]=true;
    dist[u][v]=1;
  }
  for(int k=1;k<=32;++k){
    for(int i=1;i<=n;++i){
      for(int mid=1;mid<=n;++mid){
        for(int j=1;j<=n;++j){
          if(edge[i][mid][k-1]&&edge[mid][j][k-1]){edge[i][j][k]=true;dist[i][j]=1;}}
      }
    }
  }
  for(int k=1;k<=n;++k){
    for(int i=1;i<=n;++i){
      for(int j=1;j<=n;++j){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  printf("%d\n",dist[1][n]);
  return 0;
}
