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
const int N=2e4+3;
#define lowbit(x)   x&(-x)
int n,c[2][N];
struct node{
    int v,x;
}a[N];
inline bool Cmp(node a,node b){
    return a.v<b.v;
}
inline void Add(int op,int x,int d){
    for(register int i=x;i<=2e4;i+=lowbit(i))   c[op][i]+=d;
    return;
}
inline int Query(int op,int x){
    int res=0;for(register int i=x;i>0;i-=lowbit(i))    res+=c[op][i];
    return res;
}
signed main(){
    read(n);
    for(register int i=1;i<=n;++i)  read(a[i].v),read(a[i].x);
    sort(a+1,a+n+1,Cmp);int ans=0;
    for(register int i=1;i<=n;++i){
        int cnt1=Query(0,a[i].x-1),cnt2=Query(0,2e4)-Query(0,a[i].x);
        ans+=a[i].v*(cnt1*a[i].x-Query(1,a[i].x-1)+Query(1,2e4)-Query(1,a[i].x)-cnt2*a[i].x);
        Add(0,a[i].x,1),Add(1,a[i].x,a[i].x);
    }
    print(ans);
    return 0;
}
