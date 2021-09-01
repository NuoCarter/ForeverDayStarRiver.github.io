#include<bits/stdc++.h>
using namespace std;
template < typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return ;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
#define int long long
const int N=1e5+3;
int n,k,a[N],sum[N];
int b[N],c[N];
#define lowbit(x) x&(-x)
inline void Add(int x,int d){
    for(register int i=x;i<=n;i+=lowbit(i)) c[i]+=d;
    return;
}
inline int Query(int x){
    int res=0;for(register int i=x;i>0;i-=lowbit(i))    res+=c[i];
    return res;
}
signed main(){
    read(n),read(k);
    for(register int i=1;i<=n;++i){
        read(a[i]);a[i]-=k;
        sum[i]=sum[i-1]+a[i];
        b[i]=sum[i];
    }
    b[n+1]=0;
    sort(b+1,b+n+2);int len=unique(b+1,b+n+2)-(b+1);
    int ans=0;
    for(register int i=0;i<=n;++i){
        sum[i]=lower_bound(b+1,b+n+1,sum[i])-b;
        ans+=Query(sum[i]);Add(sum[i],1);
    }
    print(ans);
    return 0;
}
