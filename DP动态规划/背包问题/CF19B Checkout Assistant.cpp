#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2005;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch))  f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
ll c[N],w[N];
ll dp[N*2];
int v,n;
int main(){
    read(n),v=2*n;
    for(register int i=1;i<=n;++i){
        read(w[i]),read(c[i]);
        w[i]=w[i]+1;
    }
    for(register int i=1;i<=v;++i)  dp[i]=1e15;
    dp[0]=0;
    for(register int i=1;i<=n;++i){
        for(register int j=v;j>=w[i];--j){
            dp[j]=min(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    ll ans=1e15;
    for(register int i=n;i<=v;++i)    ans=min(ans,dp[i]);

    print(ans);
    return 0;
}
