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
const int N=1e3+3,INF_in=0x3f3f3f3f,M=1e6+3,MOD=9987;
const double INF_db=10000000;
int head[N],to[M],res[M],Next[M],tot,n,m,preedge[M];
double edge[M],dist[N];
bool vis[N];
inline void Addedge(int x,int y,int z){to[++tot]=y,Next[tot]=head[x],head[x]=tot;preedge[tot]=z;edge[tot]=double(log2(z));}

priority_queue<pair<double,int> > pq;
inline void Dj(){
    memset(res,INF_db,sizeof(res));memset(vis,false,sizeof(vis));
    for(register int i=1;i<=n;++i) dist[i]=INF_in;
    pq.push(make_pair(0.0,1));dist[1]=0;res[1]=1;
    while(!pq.empty()){
        int x=pq.top().second;pq.pop();
        if(vis[x])  continue;
        vis[x]=true;
        for(register int i=head[x];i;i=Next[i]){
            int y=to[i];
            if(dist[y]>dist[x]+edge[i]){
                res[y]=res[x]*preedge[i]%MOD;
                dist[y]=dist[x]+edge[i];
                pq.push(make_pair(-dist[y],y));
            }
        }
    }
    print(res[n]),putchar('\n');
    return;
}

int main(){
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        int x,y,z;read(x),read(y),read(z);
        Addedge(x,y,z);
    }
    Dj();
    return 0;
}
