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
const int N=2e6+3,INF=0x3f3f3f3f;
int maxn[N<<2],minn[N<<2],n,m;
#define lc x<<1
#define rc x<<1|1
inline void Change(int x,int mx,int mn){
    maxn[x]=max(maxn[x],mx);
    maxn[x]=min(maxn[x],mn);
    minn[x]=max(minn[x],mx);
    minn[x]=min(minn[x],mn);
    return;
}
inline void Push_down(int x){
    Change(lc,maxn[x],minn[x]);
    Change(rc,maxn[x],minn[x]);
    maxn[x]=0,minn[x]=INF;
    return;
}
inline void Modify(int x,int l,int r,int L,int R,int op,int d){
    if(l>=L&&r<=R){
        maxn[x]= op==1 ? max(maxn[x],d)  : min(maxn[x],d);
        minn[x]=op==1 ? max(minn[x],d) :  min(minn[x],d);
        return;
    }
    Push_down(x);int mid=(l+r)>>1;
    if(mid>=L)  Modify(lc,l,mid,L,R,op,d);
    if(mid<R)   Modify(rc,mid+1,r,L,R,op,d);
    return;
}
inline void Query(int x,int l,int r){
    if(l==r){print(maxn[x]),putchar('\n');return;}
    Push_down(x);int mid=(l+r)>>1;
    Query(lc,l,mid),Query(rc,mid+1,r);
    return;
}

int main(){
    read(n),read(m);
    for(register int i=1;i<=n*4;++i)    minn[i]=INF;
    while(m--){
        int op,l,r,d;
        read(op),read(l),read(r),read(d);
        Modify(1,1,n,l+1,r+1,op,d);
    }
    Query(1,1,n);

    return 0;
}
