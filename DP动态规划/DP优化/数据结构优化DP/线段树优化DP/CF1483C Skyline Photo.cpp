#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lc x<<1
#define rc x<<1|1
const int N=3e5+3,INF=1e15;
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
int a[N],b[N],n;
struct node{
    int l,r,maxn,lazy;
    #define lazy(x) c[x].lazy
    #define l(x)    c[x].l
    #define r(x)    c[x].r
    #define maxn(x) c[x].maxn
}c[N<<2];
int lim[N],dp[N];
inline void Push_up(int x){maxn(x)=max(maxn(lc),maxn(rc));return;}
inline void Change(int x,int d){maxn(x)+=d,lazy(x)+=d;return;}
inline void Push_down(int x){if(lazy(x)){Change(lc,lazy(x)),Change(rc,lazy(x));lazy(x)=0;}return;}
inline void Build(int x,int l,int r){
    l(x)=l,r(x)=r;
    if(l==r){maxn(x)=0;return;}
    int mid=(l+r)>>1;
    Build(lc,l,mid);
    Build(rc,mid+1,r);
}
inline void Modify(int x,int L,int d){
    if(l(x)==r(x)){maxn(x)=d;return;}
    Push_down(x);
    int mid=(l(x)+r(x))>>1;
    if(mid>=L)  Modify(lc,L,d);
    else Modify(rc,L,d);
    Push_up(x);return;
}
inline int Query(int x,int L,int R){
    if(l(x)>=L&&r(x)<=R){return maxn(x);}
    Push_down(x);
    int mid=(l(x)+r(x))>>1,res=-INF;
    if(mid>=L) res=max(res,Query(lc,L,R));
    if(mid<R)  res=max(res,Query(rc,L,R));
    return res;
}
inline void Add(int x,int L,int R,int d){
    if(l(x)>=L&&r(x)<=R){Change(x,d);return;}
    Push_down(x);
    int mid=(l(x)+r(x))>>1;
    if(mid>=L)  Add(lc,L,R,d);
    if(mid<R)   Add(rc,L,R,d);
    Push_up(x);
    return;
}
int sta[N];
signed main(){
    read(n);
    for(register int i=1;i<=n;++i)    read(a[i]);
    for(register int i=1;i<=n;++i)    read(b[i]);
    Build(1,0,n);
    // for(register int i=1;i<=n;++i){
    //     cout<<lim[i]<<" ";
    // }
    int top=1;
    // puts("???");
    for(register int i=1;i<=n;++i){
        while(top&&a[sta[top]]>=a[i]){
            // cout<<sta[top-1]<<" "<<sta[top]-1<<"\n";
            Add(1,sta[top-1],sta[top]-1,-b[sta[top]]);
            top--;
        }
        Add(1,sta[top],i-1,b[i]);
        dp[i]=Query(1,0,i-1);
        Modify(1,i,dp[i]);
        sta[++top]=i;
    }
    // for(register int i=1;i<=n;++i) printf("%3d ",a[i]);
    // puts("");
    // for(register int i=1;i<=n;++i)  printf("%3d ",b[i]);
    // puts("");
    // for(register int i=1;i<=n;++)  printf("%3d ",dp[i]);
    // puts("");
    print(dp[n]);
    return 0;
}
