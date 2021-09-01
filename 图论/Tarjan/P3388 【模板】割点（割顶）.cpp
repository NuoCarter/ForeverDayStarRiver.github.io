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
const int N=2e4+3,M=1e5+3;
int dfn[N],dnt,low[N],n,m;
int head[N],to[M<<1],Next[M<<1],tot;
inline void Addedge(int u,int v){
    to[++tot]=v,Next[tot]=head[u],head[u]=tot;return;
}
int ans[N],root;
inline void Tarjan(int x){
    dfn[x]=low[x]=++dnt;int tmp=0;
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];
        if(!dfn[y]){
            Tarjan(y);
            low[x]=min(low[x],low[y]);
            if(low[y]>=dfn[x]){
                tmp++;
                if(x!=root||tmp>1) ans[x]=1;
            }
        }
        else    low[x]=min(low[x],dfn[y]);
    }
    return;
}
int main(){
    read(n),read(m);
    for(int u,v,i=1;i<=m;++i){
        read(u),read(v);
        Addedge(u,v),Addedge(v,u);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])    root=i,Tarjan(i);
    int cnt=0;
    for(register int i=1;i<=n;++i)  cnt+=ans[i];
    print(cnt),putchar('\n');
    for(register int i=1;i<=n;++i)
        if(ans[i])  print(i),putchar(' ');
    return 0;
}
