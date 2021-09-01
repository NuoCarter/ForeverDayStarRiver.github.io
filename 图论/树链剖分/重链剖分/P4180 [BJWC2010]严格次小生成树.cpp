#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc x<<1
#define rc x<<1|1
#define PLL pair<ll,ll>
const int N=4e5+5,M=6e5+5;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}
inline ll read_LL(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}
int head[N],idx,nex[N],to[N];
ll wl[N];
inline void add(int u,int v,ll w){
    nex[++idx]=head[u];
    head[u]=idx;
    wl[idx]=w;
    to[idx]=v;
}
bool vis[M];
int fa[N],dep[N],size[N],son[N],dfn[N],rev[N],dnt,top[N],fa_bingchaji[N];
ll val[N];
ll mod;
inline void dfs1(int x,int f){
    fa[x]=f,dep[x]=dep[f]+1;
    size[x]=1;
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];
        if(y!=f){
            dfs1(y,x);
            size[x]+=size[y];
            if(size[y]>size[son[x]]){
                son[x]=y;
            }
        }
    }
    return;
}
inline void dfs2(int x){
    if(son[fa[x]]!=x) top[x]=x;
    else top[x]=top[fa[x]];
    dfn[x]=++dnt;
    rev[dnt]=x;
    if(son[x])dfs2(son[x]);
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];
        if(y!=fa[x]&&y!=son[x])dfs2(y);
    }
}
struct segment_tree{
    int l,r;
    ll sum,sum1;
    #define l(x) c[x].l
    #define r(x) c[x].r
    #define sum(x) c[x].sum
    #define sum1(x) c[x].sum1
}c[800005];
inline void update(int x){
    if(sum(lc)>sum(rc)){sum(x)=sum(lc);sum1(x)=max(sum1(lc),sum(rc));}
    else if(sum(lc)==sum(rc)){sum(x)=sum(lc);sum1(x)=max(sum1(lc),sum1(rc));}
    else{sum(x)=sum(rc);sum1(x)=max(sum(lc),sum1(rc));}
    return;
}
inline void build(int x,int L,int R){
    l(x)=L,r(x)=R;
    if(L==R){sum(x)=val[rev[L]];return;}
    int mid=(L+R)>>1;
    build(lc,L,mid);
    build(rc,mid+1,R);
    update(x);
}
inline PLL query(int x,int L,int R){
    if(l(x)>=L&&r(x)<=R) return make_pair(sum(x),sum1(x));
    int mid=(l(x)+r(x))>>1;
    PLL lson,rson;
    lson.first=0,lson.second=0,rson.first=0,rson.second=0;
    if(mid>=L) lson=query(lc,L,R);
    if(mid<R) rson=query(rc,L,R);
    PLL now;
    now.first=max(lson.first,rson.first);
    if(lson.first>rson.first) now.second=max(lson.second,rson.first);
    else if(lson.first<rson.first) now.second=max(lson.first,rson.second);
    else now.second=max(rson.second,lson.second);
    return now;
}
inline PLL query_LCA(int u,int v){
    PLL now;
    now.first=0,now.second=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            PLL k=query(1,dfn[top[u]],dfn[u]);
            if(k.first>now.first) now.second=max(k.second,now.first),now.first=k.first;
            else if(k.first<now.first) now.second=max(k.first,now.second);
            else now.second=max(k.second,now.second);
            u=fa[top[u]];
        }
        else{
            PLL k=query(1,dfn[top[v]],dfn[v]);
            if(k.first>now.first) now.second=max(k.second,now.first),now.first=k.first;
            else if(k.first<now.first) now.second=max(k.first,now.second);
            else now.second=max(k.second,now.second);
            v=fa[top[v]];
        }
    }
    if(dep[u]<dep[v]) swap(u,v);
    PLL k=query(1,dfn[v],dfn[u]);
    if(k.first>now.first) now.second=max(k.second,now.first),now.first=k.first;
    else if(k.first<now.first) now.second=max(k.first,now.second);
    else now.second=max(k.second,now.second);
    return now;
}
struct node{
    int u,v;
    ll w;
}edge[M];
inline bool cmp(node a,node b){return a.w<b.w;}
int n,m,root;
ll tot;
int find(int x){return x==fa_bingchaji[x]?x:fa_bingchaji[x]=find(fa_bingchaji[x]);}
void merge(int x,int y){fa_bingchaji[find(x)]=find(y);return ;}
void kurskal(){
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=n;i++) fa_bingchaji[i]=i;
    for(int i=1;i<=m;i++){
        int u=edge[i].u,v=edge[i].v;
        ll w=edge[i].w;
        if(find(u)!=find(v)){
            vis[i]=true;
            tot+=w;
            add(u,v,w);add(v,u,w);
            merge(u,v);
        }
    }
    return ;
}
void dfs0(int x,int f){
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];
        if(y==f) continue;
        val[y]=wl[i];
        dfs0(y,x);
    }
    return ;
}
ll final_ans=2147483647000000,now;
int main(){
    n=read(),m=read(),root=1;
    for(int i=1;i<=m;i++)edge[i].u=read(),edge[i].v=read(),edge[i].w=read_LL();
    kurskal();
    dfs0(root,0);
    dfs1(root,0);
    dfs2(root);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            if(edge[i].u==edge[i].v){continue;}
            now=2147483647000000;
            PLL k=query_LCA(edge[i].u,edge[i].v);
            if(k.first==edge[i].w&&k.second) now=tot-k.second+edge[i].w;
            else if(k.first!=edge[i].w)now=tot-k.first+edge[i].w;
            final_ans=min(now,final_ans);
        }
    }
    printf("%lld\n",final_ans);
    return 0;
}
