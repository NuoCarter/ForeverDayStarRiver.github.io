#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e5+5;
int head[N],Next[M<<1],to[M<<1],tot,n,m,a[N],maxn[N],minn[N];
int head1[N],Next1[M<<1],to1[M<<1],tot1;
bool vis[N];queue<int> q_max,q_min;
inline void add1(int u,int v){to[++tot]=v;Next[tot]=head[u];head[u]=tot;}
inline void add2(int u,int v){to1[++tot1]=v,Next1[tot1]=head1[u],head1[u]=tot1;}
inline void spfa_max(){
  memset(vis,false,sizeof(vis));
  vis[n]=true;
  maxn[n]=a[n];
  q_max.push(n);
  while(!q_max.empty()){
    int x=q_max.front();
    q_max.pop();
    vis[x]=false;
    for(int i=head1[x];i;i=Next1[i]){
      int y=to1[i];
      if(maxn[y]<max(maxn[x],a[y])){
        maxn[y]=max(maxn[x],a[y]);
        if(!vis[y]){q_max.push(y);vis[y]=true;}
      }
    }
  }
}
inline void spfa_min(){
  memset(vis,false,sizeof(vis));
  memset(minn,0x3f3f3f3f,sizeof(minn));
  vis[1]=true;
  minn[1]=a[1];
  q_min.push(1);
  while(!q_min.empty()){
    int x=q_min.front();
    q_min.pop();
    vis[x]=false;
    for(int i=head[x];i;i=Next[i]){
      int y=to[i];
      if(minn[y]>min(minn[x],a[y])){
        minn[y]=min(minn[x],a[y]);
        if(!vis[y]){q_min.push(y);vis[y]=true;}
      }
    }
  }
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i){scanf("%d",&a[i]);}
  while(m--){
    int u,v,op;
    scanf("%d%d%d",&u,&v,&op);
    if(op==1){add1(u,v);add2(v,u);}
    else{add1(u,v),add1(v,u);add2(u,v),add2(v,u);}
  }
  spfa_max();
  spfa_min();
  int ans=0;
  for(int i=1;i<=n;++i){ans=max(ans,maxn[i]-minn[i]);}
  printf("%d\n",ans);
  return 0;
}
