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
const int N=1e5+3,M=1e6+3;
int n,m,a[N],pre[N],lst[N],cnt;
struct node{
    int d1,d2,d3,id,op;
    node(){}
    node(int _d1,int _d2,int _d3,int _id,int _op){d1=_d1,d2=_d2,d3=_d3,id=_id,op=_op;}
}Q[M+N];
inline bool Cmp1(node x,node y){
    return x.d1==y.d1 ? x.id  < y.id : x.d1 < y.d1;
}
inline bool Cmp2(node x,node y){
    return x.d2==y.d2 ? x.id < y.id : x.d2 < y.d2;
}
int c[M];
#define lowbit(x) x&(-x)
inline void Add(int x,int d){
    x++;for(register int i=x;i<=cnt;i+=lowbit(i))   c[i]+=d;
    return;
}
inline int Query(int x){
    x++;int res=0;for(register int i=x;i>0;i-=lowbit(i))    res+=c[i];
    return res;
}
int ans1[M],ans2[M];
inline void CDQ(int l,int r){
    if(l==r)    return;
    int mid=(l+r)>>1;
    CDQ(l,mid),CDQ(mid+1,r);int now=l,tot=0;
    sort(Q+l,Q+mid+1,Cmp2),sort(Q+mid+1,Q+r+1,Cmp2);
    for(register int i=mid+1;i<=r;++i){
        while(Q[i].d2>=Q[now].d2&&now<=mid){
            if(Q[now].op==0)    Add(Q[now].d3,1),tot++;
            now++;
        }
        if(Q[i].op!=0){
            ans1[Q[i].id]+=Q[i].op*tot;
            ans2[Q[i].id]+=Q[i].op*Query(Q[i].d3);
        }
    }
    for(register int i=l;i<now;++i) if(Q[i].op==0)    Add(Q[i].d3,-1);
    return;
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i){
        read(a[i]),pre[i]=lst[a[i]],lst[a[i]]=i;
        Q[++cnt]=node(i,a[i],pre[i],0,0);
    }
    for(register int i=1;i<=m;++i){
        int l,r,a2,b2;read(l),read(r),read(a2),read(b2);
        Q[++cnt]=node(l-1,a2-1,l-1,i,1);
        Q[++cnt]=node(r,b2,l-1,i,1);
        Q[++cnt]=node(l-1,b2,l-1,i,-1);
        Q[++cnt]=node(r,a2-1,l-1,i,-1);
    }
    sort(Q+1,Q+cnt+1,Cmp1);
    CDQ(1,cnt);
    for(register int i=1;i<=m;++i)  print(ans2[i]),putchar('\n');
    return 0;
}
