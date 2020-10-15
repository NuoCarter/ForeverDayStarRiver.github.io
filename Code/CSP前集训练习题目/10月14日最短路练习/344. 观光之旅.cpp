#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
const ll INF=1e15;
int n,m,to[N][N];
ll edge[N][N],dist[N][N];
int ansorder[N];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i){for(int j=1;j<=n;++j){edge[i][j]=dist[i][j]=INF;}}
  int x,y;
  ll w;
  while(m--){
    cin>>x>>y>>w;
    edge[x][y] = edge[y][x] = dist[x][y] = dist[y][x] = min(dist[x][y] , w) ;
    to[x][y]=y,to[y][x]=x;
  }
  ll ans=INF;
  // for(int i=1;i<=n;++i){
  //   for(int j=1;j<=n;++j){
  //     printf("%d ",dist[i][j]);
  //   }
  //   puts("");
  // }
  for(int k=1;k<=n;++k){
    // puts("?");
    for(int i=1;i<=n;++i){
      for(int j=i+1;j<=n;++j){
        // puts("?");
        if(ans>dist[i][j]+edge[i][k]+edge[k][j]){
        //  printf("%d\n",ans);

          ans=dist[i][j]+edge[i][k]+edge[k][j];
          // siz=0;
          // for(int o=i;o!=j;o=to[o][j]){ansorder[++siz]=o;}
          // ansorder[++siz]=j,ansorder[++siz]=k;
        }
      }
    }
    for(int i=1;i<=n;++i){
      for(int j=1;j<=n;++j){
        if(dist[i][j]>dist[i][k]+dist[k][j]){
          //printf("%d %d %d\n",dist[i][j],i,j);
          dist[i][j]=dist[i][k]+dist[k][j];
          to[i][j]=to[i][k];
        }
      }
    }
  }
  // puts("?");
  if(ans==INF){puts("No solution.");return 0;}
  else{printf("%lld\n",ans);}
  return 0;
}
