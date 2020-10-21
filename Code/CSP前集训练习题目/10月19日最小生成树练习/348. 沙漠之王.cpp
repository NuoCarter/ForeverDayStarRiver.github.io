#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e6+5;
const double eps=1e-6,INF=1e10;
struct node{
  int x,y,z;
  #define x(t) city[t].x
  #define y(t)  city[t].y
  #define z(t)  city[t].z
}city[N];
int n,root;
double edge[N][N];
double dist[N];bool vis[N];
inline double get_dist(int i,int j){return sqrt((x(i)-x(j))*(x(i)-x(j))+(y(i)-y(j))*(y(i)-y(j)));}
inline bool check(double mid){
  for(int i=1;i<=n;++i){dist[i]=INF;}
  memset(vis,false,sizeof(vis));
  dist[1]=0;double res=0;
  for(int i=1;i<=n;++i){
    double maxdist=INF;int x=1;
    for(int j=1;j<=n;++j){if(!vis[j]&&maxdist>dist[j]){x=j;maxdist=dist[j];}}
    vis[x]=true;res+=dist[x];
    for(int j=1;j<=n;++j){
      if(!vis[j]&&dist[j]>fabs(z(x)-z(j))-mid*get_dist(x,j)){
        dist[j]=fabs(z(x)-z(j))-mid*(get_dist(x,j));}
    }
  }
  return res>=0.0;
}
int main(){
  root=1;
  while(scanf("%d",&n)!=EOF&&n){
    for(int i=1;i<=n;++i){scanf("%d%d%d",&city[i].x,&city[i].y,&city[i].z);}
    double l=0,r=100000.0,ans=0.0;
    while(l+eps<r){
      double mid=(l+r)/2.0;
      if(check(mid)){ans=mid,l=mid;}
      else{r=mid;}
    }
    printf("%.3lf\n",ans);
  }

  return 0;
}
