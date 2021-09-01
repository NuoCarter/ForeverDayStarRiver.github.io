#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+3,MOD=1e9+7;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int n,k,tot,f[N][4],head[N<<1];
struct node{
    int next,to;
} edge[N<<1];
inline void Add(int u,int v){
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
inline void Dfs(int x,int fa){
    for(int i=1;i<=3;i++){
        if(f[x][i]){
            for(int j=1;j<i;j++) f[x][j]=0;
            break;
        }
        f[x][i]=1;
    }
    for(int i=head[x];i;i=edge[i].next){

        int v=edge[i].to;
        if(v!=fa){
            Dfs(v,x);
            f[x][1]=f[x][1]*((f[v][2]+f[v][3])%MOD)%MOD;
            f[x][2]=f[x][2]*((f[v][1]+f[v][3])%MOD)%MOD;
            f[x][3]=f[x][3]*((f[v][1]+f[v][2])%MOD)%MOD;
        }
    }
}
signed main(){
    read(n),read(k);
    for(int i=1,u,v;i<n;i++){
    	read(u),read(v);
    	Add(u,v);Add(v,u);
    }
    for(int i=1,u,v;i<=k;i++){
        read(u),read(v);
    	f[u][v]=1;
    }
    Dfs(1,0);
    print((f[1][1]+f[1][2]+f[1][3])%MOD);

    return 0;
}
