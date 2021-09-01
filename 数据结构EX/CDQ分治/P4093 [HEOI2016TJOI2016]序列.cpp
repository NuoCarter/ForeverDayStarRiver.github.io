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
const int N=1e5+3;
#define ll long long
#define debug(x)    cout<<x<<"???\n"
#define lowbit(x)   x&(-x)
int n,m,c[N],dp[N];
struct node{
    int val,minn,maxn,id;
}Q[N];
inline void Modify(int x,int d){for(register int i=x;i<=n;i+=lowbit(i)) c[i]=max(c[i],d);return;}
inline int Query(int x){int res=0;for(register int i=x;i>0;i-=lowbit(i)) res=max(res,c[i]);return res;}
inline void Clear(int x){for(register int i=x;i<=n;i+=lowbit(i)) c[i]=0;return;}
inline bool Cmp1(node x,node y){return x.maxn<y.maxn;}
inline bool Cmp2(node x,node y){return x.val<y.val;}
inline bool Cmp3(node x,node y){return x.id<y.id;}
inline void CDQ(int l,int r){
    if(l==r){dp[l]=max(dp[l],1);return;}
    int mid=(l+r)>>1;CDQ(l,mid);int now=l;
    sort(Q+l,Q+mid+1,Cmp1),sort(Q+mid+1,Q+r+1,Cmp2);
    for(register int i=mid+1;i<=r;++i){
        while(Q[i].val>=Q[now].maxn&&now<=mid){Modify(Q[now].val,dp[Q[now].id]);++now;}
        dp[Q[i].id]=max(dp[Q[i].id],Query(Q[i].minn)+1);
    }
    for(register int i=l;i<now;++i) Clear(Q[i].val);
    sort(Q+mid+1,Q+r+1,Cmp3);CDQ(mid+1,r);return;
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)  read(Q[i].val),Q[i].id=i,Q[i].minn=Q[i].maxn=Q[i].val;
    for(register int i=1;i<=m;++i){
        int x,v;read(x),read(v);
        Q[x].minn=min(Q[x].val,v),Q[x].maxn=max(Q[x].val,v);
    }

    CDQ(1,n);int ans=0;
    for(register int i=1;i<=n;++i) ans=max(ans,dp[i]);
    print(ans);
    return 0;
}
