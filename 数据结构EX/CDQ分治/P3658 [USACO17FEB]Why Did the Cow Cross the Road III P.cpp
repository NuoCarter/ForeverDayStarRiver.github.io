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
#define int long long
const int N=2e5+3;
struct node{
    int a,b,c;
    bool operator < (const node &B) const{return (a==B.a)?((b==B.b)?(c<B.c):(b>B.b)):(a<B.a);}
    node(){}
    node(int _a,int _b,int _c){a=_a,b=_b,c=_c;}
}S[N];
int n,b[N],c[N],ans,k;
inline bool Cmp(node x,node y){
    return x.b==y.b ? x.c < y.c : x.b > y.b;
}
#define lowbit(x)   x&(-x)
inline void Add(int x,int d){for(register int i=x;i<=n;i+=lowbit(i)) c[i]+=d;return;}
inline int Query(int x){int res=0;for(register int i=x;i>0;i-=lowbit(i))  res+=c[i];return res;}
inline void CDQ(int l,int r){
    if(l==r)    return;
    int mid=(l+r)>>1,cnt=l;
    CDQ(l,mid),CDQ(mid+1,r);
    sort(S+l,S+mid+1,Cmp),sort(S+mid+1,S+r+1,Cmp);
    for(register int i=mid+1;i<=r;++i){
        while(S[i].b<S[cnt].b&&cnt<=mid){Add(S[cnt].c,1);cnt++;}
        ans+=Query(max(0ll,S[i].c-k-1))+Query(n)-Query(min(S[i].c+k,n));
    }
    for(register int i=l;i<cnt;++i) Add(S[i].c,-1);
    return;
}
signed main(){
    read(n),read(k);
    for(register int i=1;i<=n;++i){int x;read(x);b[x]=i;}
    for(register int i=1;i<=n;++i){
        int x;read(x);
        S[i]=node(b[x],i,x);
    }
    sort(S+1,S+n+1);
    CDQ(1,n);print(ans);
    return 0;
}
