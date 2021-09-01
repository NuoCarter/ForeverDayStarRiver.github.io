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
const int N=1e5+200;
#define ll long long
const ll MOD=1e9+7,bas=139;
int rt[N],n,m,head[N],to[N<<1],Next[N<<1],edge[N<<1],tot,cnt,maxn,s,t;
inline void Addedge(int u,int v,int w){
    to[++tot]=v,Next[tot]=head[u],head[u]=tot,edge[tot]=w;
    return ;
}
ll po1[N],po2[N];

struct node{
    ll sum,has;int ls,rs;
    bool tag;
    #define tag(x)  c[x].tag
    #define has(x)  c[x].has
    #define ls(x)   c[x].ls
    #define rs(x)   c[x].rs
    #define sum(x)  c[x].sum
}c[N*200];
inline ll Inc(ll a,ll b){a+=b;return a>=MOD ? a-MOD : a;}
inline void Push_up(int x){
    sum(x)=Inc(sum(ls(x)),sum(rs(x)));
    has(x)=Inc(has(ls(x)),has(rs(x)));
    tag(x)=(tag(ls(x))&tag(rs(x)));
    return;
}
inline void Build(int &x,int l,int r,int d){
    x=++cnt;
    if(l==r){sum(x)=po2[l]*d,has(x)=po1[l]*d,tag(x)=d;return;}
    int mid=(l+r)>>1;
    Build(ls(x),l,mid,d),Build(rs(x),mid+1,r,d);
    Push_up(x);return;
}
inline void Cover(int &x,int pre,int l,int r,int L,int R){
    x=++cnt,c[x]=c[pre];
    if(l>=L&&r<=R){x=0;return;}
    int mid=(l+r)>>1;
    if(mid>=L)  Cover(ls(x),ls(pre),l,mid,L,R);
    if(mid<R)   Cover(rs(x),rs(pre),mid+1,r,L,R);
    Push_up(x);return;
}
inline void Modify(int &x,int pre,int l,int r,int d){
    x=++cnt,c[x]=c[pre];
    if(l==r){sum(x)=po2[l],has(x)=po1[l],tag(x)=true;return;}
    int mid=(l+r)>>1;
    if(mid>=d)  Modify(ls(x),ls(pre),l,mid,d);
    else Modify(rs(x),rs(pre),mid+1,r,d);
    Push_up(x);return;
}
inline bool Query(int x,int l,int r,int L,int R){
    if(!x)  return false;
    if(l>=L&&r<=R)  return tag(x);
    int mid=(l+r)>>1;bool res=true;
    if(mid>=L)  res=(res&Query(ls(x),l,mid,L,R));
    if(mid<R)   res=(res&Query(rs(x),mid+1,r,L,R));
    return res;
}
inline void Addone(int x,int loc){
    int l=loc,r=maxn,res=loc-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Query(rt[x],0,maxn,loc,mid)) res=mid,l=mid+1;
        else r=mid-1;
    }
    rt[n+1]=rt[x];
    if(res>=loc)    Cover(rt[n+1],rt[n+1],0,maxn,loc,res);
    Modify(rt[n+1],rt[n+1],0,maxn,res+1);
    return;
}
inline bool Cmp(int x,int pre,int l,int r){
    if(l==r) return (tag(x)==true&&tag(pre)==false);
    int mid=(l+r)>>1;
    if(sum(rs(x))!=sum(rs(pre))&&has(rs(x))!=has(rs(pre)))  return Cmp(rs(x),rs(pre),mid+1,r);
    else return Cmp(ls(x),ls(pre),l,mid);
}
struct Point{
    int x,nowrt;
    Point(){}
    Point(int _nowrt,int _x){nowrt=_nowrt,x=_x;}
    bool operator < (const Point &B) const {return Cmp(nowrt,B.nowrt,0,maxn);}
};
priority_queue<Point> pq;
int pre[N];bool vis[N];
inline void DJ(){
    read(s),read(t);
    Build(rt[s],0,maxn,0);
    Build(rt[0],0,maxn,1);
    for(register int i=1;i<=n;++i){if(i==s)    continue;rt[i]=rt[0];}
    pq.push(Point(rt[s],s));
    while(!pq.empty()){
        int x=pq.top().x;pq.pop();
        if(x==t)    break;
        if(vis[x])  continue;
        vis[x]=true;
        for(register int i=head[x];i;i=Next[i]){
            int y=to[i];
            Addone(x,edge[i]);
            if(Cmp(rt[y],rt[n+1],0,maxn)){
                rt[y]=rt[n+1],pre[y]=x;
                if(!vis[y]) pq.push(Point(rt[y],y));
            }
        }
    }
    return;
}
int path[N],pcnt;
int main(){
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        int u,v,x;read(u),read(v),read(x);
        Addedge(u,v,x),Addedge(v,u,x);
        maxn=max(maxn,x);
    }
    maxn+=22;
    po1[0]=po2[0]=1;
    for(register int i=1;i<=maxn;++i) po1[i]=po2[i-1]*bas%MOD,po2[i]=po2[i-1]*2%MOD;
    DJ();
    if(tag(rt[t])){puts("-1");return 0;}
    print(sum(rt[t])),putchar('\n');
    int now=t;while(now!=s) path[++pcnt]=now,now=pre[now];
    path[++pcnt]=s;
    print(pcnt),putchar('\n');
    for(register int i=pcnt;i>=1;--i) print(path[i]),putchar(' ');
    return 0;
}
/*
8 8
8 4 3
1 5 1
7 4 8
5 3 6
7 3 8
8 6 5
2 1 3
6 2 8
7 1
*/
