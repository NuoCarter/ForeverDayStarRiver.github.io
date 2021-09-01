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
const int N=35003,K=53;
int dp[N][K],a[N],n,k,lst[N];
struct node{
    #define lc x<<1
    #define rc x<<1|1
    int maxn[N<<2],lazy[N<<2];
    inline void Push_up(int x){
        maxn[x]=max(maxn[lc],maxn[rc]);
        return;
    }
    inline void Change(int x,int l,int r,int d){
        maxn[x]+=d,lazy[x]+=d;
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
        if(L>R) return;
        if(l>=L&&r<=R){Change(x,l,r,d);return;}
        Push_down(x,l,r);int mid=(l+r)>>1;
        if(mid>=L)  Modify(lc,l,mid,L,R,d);
        if(mid<R)   Modify(rc,mid+1,r,L,R,d);
        Push_up(x);return;
    }
    inline void OneM(int x,int l,int r,int go,int d){
        if(l==r){maxn[x]=d;return;}
        Push_down(x,l,r);int mid=(l+r)>>1;
        if(mid>=go) OneM(lc,l,mid,go,d);
        else OneM(rc,mid+1,r,go,d);
        Push_up(x);return;
    }
    inline int Query(int x,int l,int r,int L,int R){
        if(L>R) return 0;
        if(l>=L&&r<=R){return maxn[x];}
        Push_down(x,l,r);int mid=(l+r)>>1,res=0;
        if(mid>=L)  res=max(res,Query(lc,l,mid,L,R));
        if(mid<R)   res=max(res,Query(rc,mid+1,r,L,R));
        return res;
    }
}T[K];
int main(){
    read(n),read(k);
    for(register int i=1;i<=n;++i)  read(a[i]);
    for(register int i=1;i<=k;++i){
        memset(lst,0,sizeof(lst));
        for(register int j=1;j<=n;++j)  T[i].OneM(1,1,n,j,dp[j-1][i-1]);
        for(register int j=1;j<=n;++j){
            T[i].Modify(1,1,n,lst[a[j]]+1,j,1);
            dp[j][i]=T[i].Query(1,1,n,1,j);
            lst[a[j]]=j;
        }
    }
    print(dp[n][k]);
    return 0;
}
