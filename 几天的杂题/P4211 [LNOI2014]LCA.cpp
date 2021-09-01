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
const int N=5e4+3,MOD=201314;
inline int Inc(int a,int b){a+=b;return a>=MOD ? a-MOD :a;}
inline int Dec(int a,int b){a-=b;return a<0 ? a+MOD :a;}
int Next[N<<1],to[N<<1],dep[N],head[N],tot,n,m,sum[N<<2],lazy[N<<2];
inline void Addedge(int u,int v){
    Next[++tot]=head[u],head[u]=tot,to[tot]=v;
    return;
}
int fa[N],son[N],siz[N],dnt,top[N],seg[N],rev[N];
inline void Dfs1(int x,int f){
    siz[x]=1,fa[x]=f,dep[x]=dep[f]+1;
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];if(y==f)    continue;
        Dfs1(y,x);siz[x]+=siz[y];
        son[x]=siz[y] > siz[son[x]] ? y : son[x];
    }
    return;
}
inline void Dfs2(int x){
    top[x]=son[fa[x]]==x ? top[fa[x]] : x;
    seg[x]=++dnt,rev[dnt]=x;
    if(son[x])  Dfs2(son[x]);
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];if(y==fa[x]||y==son[x]) continue;
        Dfs2(y);
    }
    return;
}
#define lc x<<1
#define rc x<<1|1
inline void Push_up(int x){
    sum[x]=Inc(sum[lc],sum[rc]);
    return;
}
inline void Change(int x,int l,int r,int d){
    sum[x]=Inc(sum[x],(r-l+1)*d%MOD);
    lazy[x]=Inc(lazy[x],d);
    return;
}
inline void Push_down(int x,int l,int r){
    if(lazy[x]){
        int mid=(l+r)>>1;
        Change(lc,l,mid,lazy[x]);
        Change(rc,mid+1,r,lazy[x]);
        lazy[x]=0;
    }
    return;
}
inline void Modify(int x,int l,int r,int L,int R,int d){
    if(l>=L&&r<=R){Change(x,l,r,d);return;}
    Push_down(x,l,r);int mid=(l+r)>>1;
    if(mid>=L)  Modify(lc,l,mid,L,R,d);
    if(mid<R)   Modify(rc,mid+1,r,L,R,d);
    Push_up(x);return;
}
inline int Query(int x,int l,int r,int L,int R){
    if(l>=L&&r<=R)  return sum[x];
    Push_down(x,l,r);int mid=(l+r)>>1,res=0;
    if(mid>=L)  res=Inc(res,Query(lc,l,mid,L,R));
    if(mid<R)   res=Inc(res,Query(rc,mid+1,r,L,R));
    return res;
}
inline void Change_root(int x,int d){
    while(top[x]!=1){Modify(1,1,n,seg[top[x]],seg[x],d);x=fa[top[x]];}
    Modify(1,1,n,seg[1],seg[x],d);return;
}
inline int Query_root(int x){
    int res=0;while(top[x]!=1){res=Inc(res,Query(1,1,n,seg[top[x]],seg[x]));x=fa[top[x]];}
    res=Inc(res,Query(1,1,n,seg[1],seg[x]));return res;
}
struct Ques{
    int op,z,id;
    Ques(){}
    Ques(int _op,int _z,int _id){op=_op,z=_z,id=_id;}
};
int ans[N];
vector<Ques> Q[N];
int main(){
    read(n),read(m);
    for(register int i=2;i<=n;++i){
        int y;read(y);y+=1;
        Addedge(i,y),Addedge(y,i);
    }
    Dfs1(1,0);Dfs2(1);
    for(register int i=1;i<=m;++i){
        int l,r,z;read(l),read(r),read(z);
        l+=1,r+=1,z+=1;
        Q[l-1].push_back(Ques(-1,z,i)),Q[r].push_back(Ques(1,z,i));
    }
    for(register int i=1;i<=n;++i){
        int tsiz=Q[i].size();Change_root(i,1);
        for(register int j=0;j<tsiz;++j){
            int tmp=Q[i][j].z,bel=Q[i][j].id;
            if(Q[i][j].op==-1) ans[bel]=Dec(ans[bel],Query_root(tmp));
            else ans[bel]=Inc(ans[bel],Query_root(tmp));
        }
    }
    for(register int i=1;i<=m;++i)  print(ans[i]),putchar('\n');
    return 0;
}
