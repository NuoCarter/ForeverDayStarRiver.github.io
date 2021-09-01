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
const int N=3e5+3;
string s[N];
multiset<int> val[N];
int ch[N][26],past[N],m,tot=1,root=1,rev[N],head[N],Next[N],to[N],cnt,n,fail[N];
inline void Addedge(int u,int v){
    Next[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
    return;
}
inline void Insert(string str,int pos){
    int len=str.size(),p=root;
    for(register int i=0;i<len;++i){
        int o=str[i]-'a';if(!ch[p][o])  ch[p][o]=++tot;
        p=ch[p][o];
    }
    rev[pos]=p;return;
}
inline void Getfail(){
    queue<int> q;
    for(register int i=0;i<26;++i)  if(ch[root][i]) fail[ch[root][i]]=root,q.push(ch[root][i]);
    for(register int i=0;i<26;++i)  if(!ch[root][i])    ch[root][i]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(register int i=0;i<26;++i){
            if(ch[x][i])    fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
            else ch[x][i]=ch[fail[x]][i];
        }
    }
    for(register int i=2;i<=tot;++i)    Addedge(fail[i],i);
    return;
}
int dfn[N],fa[N],top[N],siz[N],son[N],dnt;
inline void Dfs1(int x,int f){
    siz[x]=1,fa[x]=f;
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];Dfs1(y,x);
        siz[x]+=siz[y];
        if(siz[son[x]]<siz[y])  son[x]=y;
    }
    return;
}
inline void Dfs2(int x){
    dfn[x]=++dnt;top[x]=son[fa[x]]==x ? top[fa[x]] : x;
    if(son[x])  Dfs2(son[x]);
    for(register int i=head[x];i;i=Next[i]){
        int y=to[i];if(y==son[x])   continue;
        Dfs2(y);}
    return;
}
struct node{
    int l,r,maxn,lazy;
    #define l(x)    c[x].l
    #define r(x)    c[x].r
    #define maxn(x) c[x].maxn
    #define lazy(x) c[x].lazy
}c[N<<2];
#define lc x<<1
#define rc x<<1|1
inline void Push_up(int x){maxn(x)=max(maxn(lc),maxn(rc));return;}
inline void Build(int x,int l,int r){
    l(x)=l,r(x)=r;
    if(l==r){maxn(x)=-1,lazy(x)=0;return;}
    int mid=(l+r)>>1;
    Build(lc,l,mid);Build(rc,mid+1,r);
    Push_up(x);return;
}
inline void Modify(int x,int g,int d){
    if(l(x)==r(x)){maxn(x)=d;return;}
    int mid=(l(x)+r(x))>>1;
    if(mid>=g)  Modify(lc,g,d);
    else Modify(rc,g,d);
    Push_up(x);return;
}
inline int Query(int x,int L,int R){
    if(l(x)>=L&&r(x)<=R)    return maxn(x);
    int mid=(l(x)+r(x))>>1,res=-1;
    if(mid>=L)  res=max(res,Query(lc,L,R));
    if(mid<R)   res=max(res,Query(rc,L,R));
    return res;
}
inline int Get(int x){
    int res=-1;
    while(x) res=max(res,Query(1,dfn[top[x]],dfn[x])),x=fa[top[x]];
    return res;
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)
        cin>>s[i],Insert(s[i],i);
    Getfail();Dfs1(root,0),Dfs2(root);Build(1,1,tot);
    for(register int i=1;i<=n;++i){
        val[rev[i]].insert(0);
        Modify(1,dfn[rev[i]],0);
    }
    while(m--){
        int op;string ptr;
        read(op);
        if(op==1){
            int x,v;read(x),read(v);
            val[rev[x]].erase(val[rev[x]].lower_bound(past[x]));
            val[rev[x]].insert(v);
            Modify(1,dfn[rev[x]],*val[rev[x]].rbegin());
            past[x]=v;
        }
        else{
            cin>>ptr;
            int len=ptr.size(),p=root,res=-1;
            for(register int i=0;i<len;++i){
                p=ch[p][ptr[i]-'a'];
                res=max(res,Get(p));
            }
            print(res),putchar('\n');
        }
    }

    return 0;
}
