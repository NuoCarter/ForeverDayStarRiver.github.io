#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
const int N=1e4+3,M=2e5+3,INF=0x3f3f3f3f;
int head[N],to[M],Next[M],tot;
int n,m;
inline void Addedge(int u,int v){Next[++tot]=head[u],head[u]=tot,to[tot]=v;return;}
int dist[N];queue<int> q;
bool vis[N];
bool res[N];
inline void Dfs(int x){
    vis[x]=true;
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];
        if(!vis[y]) Dfs(y);
    }
}
int main(){
    int s,t;
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        int u,v;read(u),read(v);
        if(u==v) continue;
        Addedge(v,u);
    }
    read(s),read(t);
    Dfs(t);
    for(register int i=1;i<=n;++i){
        if(!vis[i]){
            for(register int j=head[i];j;j=Next[j]){
                int y=to[j];
                res[y]=true;
            }
        }
    }

    if(res[s]){puts("-1");return 1;}
    memset(dist,INF,sizeof(dist));
    memset(vis,false,sizeof(vis));
    dist[t]=0;
    q.push(t);vis[t]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        if(x==s)    break;
        for(register int i=head[x];i;i=Next[i]){
            int y=to[i];
            if(!vis[y]&&!res[y]){
                dist[y]=dist[x]+1;
                vis[y]=true;
                q.push(y);
            }
        }
    }
    if(dist[s]==INF)    puts("-1");
    else print(dist[s]);
    return 0;
}
