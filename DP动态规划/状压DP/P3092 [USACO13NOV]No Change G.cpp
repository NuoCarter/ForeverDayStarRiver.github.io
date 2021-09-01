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
const int K=17,N=1e5+3,INF=1e15;
int n,k,a[K],c[N],sum,pre[N],dp[1<<K];
inline int Getans(int x){
    int tmp=0;
    for(register int i=1;i<=k;++i) if(x&(1<<(i-1)))  tmp+=a[i];
    return tmp;
}
signed main(){
    read(k),read(n);
    for(register int i=1;i<=k;++i)  read(a[i]),sum+=a[i];
    for(register int i=1;i<=n;++i)  read(c[i]),pre[i]=pre[i-1]+c[i];
    pre[n+1]=INF,dp[0]=0;int maxn=-1;
    for(register int now=1;now<(1<<(k));++now){
        for(register int i=1;i<=k;++i){
            if(now&(1<<(i-1))){
                int tmp=now^(1<<(i-1)),lst=dp[tmp];
                dp[now]=max(dp[now],1ll*(upper_bound(pre+1,pre+n+2,pre[lst]+a[i])-pre-1));
            }
        }
        if(dp[now]==n)  maxn=max(maxn,sum-Getans(now));
    }
    print(maxn);
    return 0;
}
/*
in:
5 5
250
277
796
271
60
69
42
22
73
79
out:
1133
in:
3 6
12
15
10
6
3
3
2
3
7
out:
12
*/
