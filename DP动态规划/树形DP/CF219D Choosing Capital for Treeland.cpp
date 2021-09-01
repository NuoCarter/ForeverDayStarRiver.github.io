#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,INF=0x3f3f3f3f;
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
int n,tot,head[N],f[N];
struct node{
    int Next,to;
    bool op;
    #define Next(x) edge[x].Next
    #define op(x)   edge[x].op
    #define to(x)   edge[x].to

}edge[N<<1];

inline void Add(int u,int v,bool oiu){Next(++tot)=head[u],op(tot)=oiu,to(tot)=v,head[u]=tot;}

inline void Dfs1(int x,int fa){

    for(register int i=head[x];i;i=Next(i)){
        int y=to(i);
        if(y==fa)   continue;
        Dfs1(y,x);
        f[x]+=f[y]+(op(i) ? 0 : 1);
    }

}

inline void Dfs2(int x,int fa){
    for(register int i=head[x];i;i=Next(i)){
        int y=to(i);
        if(y==fa)   continue;
        f[y]=f[x]+(op(i) ? 1 : -1);
        Dfs2(y,x);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        tot=0;memset(edge,0,sizeof(edge));memset(head,0,sizeof(head));
        memset(f,0,sizeof(f));
        for(int i=1,u,v;i<n;++i){
            read(u),read(v);
            Add(u,v,1);Add(v,u,0);
        }
        Dfs1(1,0);Dfs2(1,0);
        int minn=INF;
        for(register int i=1;i<=n;++i)  minn=min(minn,f[i]);
        print(minn),putchar('\n');
        for(register int i=1;i<=n;++i)    if(f[i]==minn)  print(i),putchar(' ');
        putchar('\n');
    }



    return 0;
}
