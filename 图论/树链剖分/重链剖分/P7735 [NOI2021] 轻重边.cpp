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
const int N=2e5+3;
//Graph
int head[N],to[N<<1],Next[N<<1],tot,n,m;
inline void Addedge(int u,int v){
    to[++tot]=v,Next[tot]=head[u],head[u]=tot;
    return ;
}
//Tree
int fa[N],son[N],siz[N],dep[N];
inline void Dfs1(int x,int f){
    siz[x]=1,dep[x]=dep[f]+1,fa[x]=f;
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];
        if(y==f)    continue;
        Dfs1(y,x);siz[x]+=siz[y];
        son[x]=siz[y] > siz[son[x]] ? y : son[x];
    }
    return;
}
int top[N],seg[N],rev[N],dnt;
inline void Dfs2(int x){
    top[x]=son[fa[x]] == x ? top[fa[x]] : x;
    seg[x]=++dnt,rev[dnt]=x;
    if(son[x])  Dfs2(son[x]);
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];if(y==fa[x]||y==son[x]) continue;
        Dfs2(y);
    }
    return;
}
#define debug(x)    cout<<x<<"????\n"
#define lc x<<1
#define rc x<<1|1
struct node{
    int l,r,sum,lazy,lval,rval;
    #define sum(x)  c[x].sum
    #define l(x)    c[x].l
    #define r(x)    c[x].r
    #define lazy(x) c[x].lazy
    #define lval(x) c[x].lval
    #define rval(x) c[x].rval
    node(){l=r=sum=lazy=lval=rval=0;}
    node(int _l,int _r,int _sum,int _lazy,int _lval,int _rval){
        l=_l,r=_r,lazy=_lazy,sum=_sum,lval=_lval,rval=_rval;
    }
}c[N<<2];
inline void Push_up(int x){
    sum(x)=sum(lc)+sum(rc);
    sum(x)+=(rval(lc)==lval(rc)&&lval(rc)!=0) ? 1 : 0;
    lval(x)=lval(lc),rval(x)=rval(rc);
    return;
}
inline void Build(int x,int l,int r){
    l(x)=l,r(x)=r;
    if(l==r){lval(x)=rval(x)=sum(x)=lazy(x)=0;return;}
    int mid=(l+r)>>1;
    Build(lc,l,mid),Build(rc,mid+1,r);
    Push_up(x);return;
}
inline void Change(int x,int d){
    lval(x)=rval(x)=d;sum(x)=(r(x)-l(x));
    lazy(x)=d;
    return;
}
inline void Push_down(int x){
    if(lazy(x)>0) Change(lc,lazy(x)),Change(rc,lazy(x)),lazy(x)=0;
    return;
}
inline void Cover(int x,int L,int R,int d){
    if(L>R) return;
    if(l(x)>=L&&r(x)<=R){Change(x,d);return;}
    Push_down(x);int mid=(l(x)+r(x))>>1;
    if(mid>=L)  Cover(lc,L,R,d);
    if(mid<R)   Cover(rc,L,R,d);
    Push_up(x);return;
}
inline node Add(node x,node y){
    x.sum+=y.sum;
    x.sum+=(x.rval==y.lval&&x.rval!=0)  ? 1 : 0;
    x.rval=y.rval;
    return x;
}
inline node Query(int x,int L,int R){
    if(L>R) return node(0,0,0,0,0,0);
    if(l(x)>=L&&r(x)<=R){return c[x];}
    Push_down(x);
    int mid=(l(x)+r(x))>>1;node res;bool fl=false;
    if(mid>=L)  res=Query(lc,L,R),fl=true;
    if(mid<R){
        if(fl) res=Add(res,Query(rc,L,R));
        else res=Query(rc,L,R);
    }
    return res;
}
inline void ModifyLCA(int u,int v,int d){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]) Cover(1,seg[top[u]],seg[u],d),u=fa[top[u]];
        else Cover(1,seg[top[v]],seg[v],d),v=fa[top[v]];
    }
    if(dep[u]<dep[v])   swap(u,v);
    Cover(1,seg[v],seg[u],d);
    return;
}
inline node QueryLCA(int u,int v){
    node res1,res2;bool fl1=false,fl2=false;
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            if(!fl1)    res1=Query(1,seg[top[u]],seg[u]),fl1=true;
            else res1=Add(Query(1,seg[top[u]],seg[u]),res1);
            u=fa[top[u]];
        }
        else{
            if(!fl2)    res2=Query(1,seg[top[v]],seg[v]),fl2=true;
            else res2=Add(Query(1,seg[top[v]],seg[v]),res2);
            v=fa[top[v]];
        }
    }
    if(dep[u]>dep[v]){
    	if(!fl1) res1=Query(1,seg[v],seg[u]),fl1=true;
    	else res1=Add(Query(1,seg[v],seg[u]),res1);
	}
    else{
    	if(!fl2) res2=Query(1,seg[u],seg[v]),fl2=true;
    	else res2=Add(Query(1,seg[u],seg[v]),res2);
	}
	swap(res1.lval,res1.rval);
    if(fl1&&fl2) return Add(res1,res2);
    if(fl1) return res1;
    return res2;
}
int main(){
    // system("fc edge.out edge2.ans");
	// freopen("edge2.in","r",stdin);
	// freopen("edge.out","w",stdout);
    int T;read(T);
    while(T--){
        read(n),read(m);int tmp=0;
        for(register int i=1;i<n;++i){int u,v;read(u),read(v);Addedge(u,v),Addedge(v,u);}
        Dfs1(1,0),Dfs2(1);int op,u,v;Build(1,1,n);
        while(m--){
            read(op),read(u),read(v);
            if(op==1) ++tmp,ModifyLCA(u,v,tmp);
            else{
                node ans=QueryLCA(u,v);
                print(ans.sum),putchar('\n');
            }
        }
        for(register int i=1;i<=n;++i)  head[i]=0;
        for(register int i=1;i<=2*n-2;++i)    Next[i]=to[i]=0;
        for(register int i=1;i<=n;++i)  fa[i]=seg[i]=rev[i]=dep[i]=siz[i]=son[i]=0;
        dnt=0;memset(c,0,sizeof(c));
        tot=0;
    }
    return 0;
}
/*
1
7 3
6 2
3 1
1 6
5 3
2 7
1 4
1 5 6
1 5 1
2 6 5

*/
