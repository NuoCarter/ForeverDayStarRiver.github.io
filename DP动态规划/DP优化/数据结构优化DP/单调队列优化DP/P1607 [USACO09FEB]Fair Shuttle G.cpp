#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
const int N=2e5+3,K=5e4+3,C=103,INF=0x3f3f3f3f;
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
int k,n,c;
struct node{
    int s,e,m;

    #define s(x)    cow[x].s
    #define e(x)    cow[x].e
    #define m(x)    cow[x].m
}cow[N];

struct seg{
    int l,r,maxn;
    int lazy;
    #define l(x)    t[x].l
    #define r(x)    t[x].r
    #define maxn(x) t[x].maxn
    #define lazy(x) t[x].lazy
}t[N<<2];

inline void Push_up(int x){maxn(x)=max(maxn(lc),maxn(rc));return;}

inline void Change(int x,int d){maxn(x)+=d;lazy(x)+=d;return;}

inline void Push_down(int x){
    if(lazy(x)){Change(lc,lazy(x)),Change(rc,lazy(x));lazy(x)=0;}
}

inline void Build(int x,int l,int r){
    l(x)=l,r(x)=r;
    if(l==r){maxn(x)=0;return;}
    int mid=(l+r)>>1;
    Build(lc,l,mid);
    Build(rc,mid+1,r);
    Push_up(x);
    return;
}
inline void Modify(int x,int L,int R,int d){
    if(l(x)>=L&&r(x)<=R){
        Change(x,d);return;
    }
    Push_down(x);
    int mid=(l(x)+r(x))>>1;
    if(mid>=L)  Modify(lc,L,R,d);
    if(mid<R)   Modify(rc,L,R,d);
    Push_up(x);
    return;
}

inline int Query(int x,int L,int R){
    if(l(x)>=L&&r(x)<=R)    return maxn(x);
    Push_down(x);
    int mid=(l(x)+r(x))>>1;
    int res=-INF;
    if(mid>=L)  res=max(res,Query(lc,L,R));
    if(mid<R)   res=max(res,Query(rc,L,R));
    return res;
}

inline bool Cmp(node x,node y){return x.e==y.e ? x.s<y.s : x.e<y.e;}
int main(){
    read(k),read(n),read(c);
    for(register int i=1;i<=k;++i)    read(s(i)),read(e(i)),read(m(i));

    sort(cow+1,cow+k+1,Cmp);
    Build(1,1,n);

    int ans=0;

    for(register int i=1;i<=k;++i){
        int tep=Query(1,s(i),e(i)-1);
        int res=min(c-tep,m(i));
        ans+=res;
        // cout<<tep<<" "<<res<<endl;
        Modify(1,s(i),e(i)-1,res);
    }
    print(ans);
    return 0;
}
