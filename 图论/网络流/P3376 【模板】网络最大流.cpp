#include<bits/stdc++.h>
using namespace std;
const int N=1003,M=10000*2+3,INF=1<<29;
#define ll long long
template <typename T>
inline void read(T &x){
  x=0;char ch=getchar();bool f=false;
  while(!isdigit(ch)) f|=ch=='-',ch=getchar();
  while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
  x=f?-x:x;
}
int n,m,s,t,tot=1;
ll maxflow;
int head[N],to[M],Next[M];
ll c[M];
inline void Add(int u,int v,int w){
  c[++tot]=w;to[tot]=v,Next[tot]=head[u],head[u]=tot;
  c[++tot]=0;to[tot]=u,Next[tot]=head[v],head[v]=tot;
  return;
}
int vis[N],pre[N];
ll incf[N];
inline bool Bfs(){
  memset(vis,0,sizeof(vis));
  queue<int> q;
  q.push(s);vis[s]=1;incf=INF;
  while(!q.empty()){
    int x=q.front();q.pop();
    for(register int i=head[x];i;i=Next[i]){
      if(c[i]){
        int y=to[i];
        if(vis[y])  continue;
        incf[y]=min(incf[x],c[i]);
        pre[y]= i ;
        q.push(y),vis[y]=1;
        if(y==t)  return true;
      }
    }
  }return false;
}
inline void Update(){
  int u=t;
  while(u!=s){
    int i=pre[u];
    c[i]-=incf[t];
    c[i^1]+=incf[t];
    u=to[i^1];
  }
  maxflow+=incf[t];
}
int main(){
  read(n),read(m),read(s),read(t);
  maxflow=0;tot=1;
  while(m--){
    int u,v,w;
    read(u),read(v),read(w);
    Add(u,v,w);
  }
  while(Bfs())  Update();
  printf("%lld\n",maxflow);
  return 0;
}
