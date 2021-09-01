#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return;
}
template<typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
#define int long long
const int N=1e5+3;
int n,m;
int ans[N],a[N],rev[N],cnt;
struct node{
    int d1,d2,d3,op,id;
    node(){}
    node(int _d1,int _d2,int _d3,int _op,int _id){d1=_d1,d2=_d2,d3=_d3,op=_op,id=_id;}
}Q[N<<1];
#define lowbit(x)   x&(-x)
int c[N<<1];
inline void Add(int x,int d){
    x++;for(register int i=x;i<=cnt;i+=lowbit(i))   c[i]+=d;
    return;
}
inline int Query(int x){
    x++;int res=0;for(register int i=x;i>0;i-=lowbit(i))    res+=c[i];
    return res;
}
inline bool Cmp1(node x,node y){
    return x.d2<y.d2;
}
inline void CDQ(int l,int r){
    if(l==r)    return;
    int mid=(l+r)>>1;
    CDQ(l,mid),CDQ(mid+1,r);int now=l;
    sort(Q+l,Q+mid+1,Cmp1),sort(Q+mid+1,Q+r+1,Cmp1);
    for(register int i=mid+1;i<=r;++i){
        while(Q[i].d2>=Q[now].d2&&now<=mid){Add(Q[now].d3,Q[now].op);now++;}
        ans[Q[i].id]+=Q[i].op*(Query(cnt)-Query(Q[i].d3));
    }
    for(register int i=l;i<now;++i) Add(Q[i].d3,-Q[i].op);
    now=mid;
    for(register int i=r;i>=mid+1;--i){
        while(Q[i].d2<=Q[now].d2&&now>=l)    Add(Q[now].d3,Q[now].op),now--;
        ans[Q[i].id]+=Q[i].op*(Query(Q[i].d3-1));
    }
    for(register int i=mid;i>now;--i)   Add(Q[i].d3,-Q[i].op);
    return;
}
signed main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i){
        read(a[i]),rev[a[i]]=i;
        Q[++cnt]=node(1,i,a[i],1,0);
    }
    for(register int i=1;i<=m;++i){
        int x;read(x);
        Q[++cnt]=node(1,rev[x],x,-1,i);
    }
    CDQ(1,cnt);print(ans[0]),putchar('\n');
    for(register int i=1;i<m;++i) ans[i]+=ans[i-1],print(ans[i]),putchar('\n');
    return 0;
}
