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
#define int long long
const int N=2e5+3,MOD=1e9+7;
inline int Inc(int a,int b){a+=b;return a>=MOD ?a-MOD :a;}
inline int Dec(int a,int b){a-=b;return a<0 ? a+MOD :a;}
int head[N],to[N<<1],Next[N<<1],tot,op[N],n,m1,m2,jc[N];
inline void Addedge(int u,int v,int w){
    to[++tot]=v,Next[tot]=head[u],head[u]=tot,op[tot]=w;
    return;
}
bool vis[N],ring;
int siz[N],ed[N],tp;
inline void Dfs(int x,int fa,int bel,int edop){
    if(vis[x]){ring=true;return;}
    vis[x]=true,siz[bel]++;
    bool fl=0;
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];if(y==fa)   continue;
        Dfs(y,x,bel,op[i]);fl=true;
    }
    if(!fl) ed[bel]=edop;
    return;
}
int res[N][2],b[N];
signed main(){
    int num;read(num);
    read(n),read(m1),read(m2);jc[0]=1;
    for(register int i=1;i<=n;++i) jc[i]=1ll*jc[i-1]*i%MOD;
    for(register int i=1;i<=m1;++i){
        int u,v;read(u),read(v);
        Addedge(u,v,1),Addedge(v,u,1);
    }
    for(register int i=1;i<=m2;++i){
        int u,v;read(u),read(v);
        Addedge(u,v,0),Addedge(v,u,0);
    }
    memset(ed,-1,sizeof(ed));int ans=1;
    for(register int i=1;i<=n;++i){
        if(!vis[i]){
            ring=false;++tp;
            Dfs(i,0,tp,1);
            if(!ring){
                res[siz[tp]][ed[tp]]++;
                if(siz[tp]%2==0) ans=(ans*2)%MOD;
            }
            else ans=ans*siz[tp],b[siz[tp]]++;
        }
    }

    for(register int i=1;i<=n;++i){
        if((i&1)) ans=ans*jc[res[i][0]+res[i][1]]%MOD;
        else for(register int j=0;j<=1;++j) ans=ans*jc[res[i][j]]%MOD;
        ans=ans*jc[b[i]]%MOD;
    }
    ans=Dec(jc[n],ans);
    print(ans);
    return 0;
}
/*
3
7 3 2
3 1
4 2
5 7
1 4
2 3

*/
