#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int N=85;
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
int a[N][N],dp[N][N],n,m,ans;
int po[N];
signed main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j) read(a[i][j]);

    po[0]=1;

    for(register int i=1;i<=m+10;++i){po[i]=po[i-1]<<1;}

    for(register int now=1;now<=n;++now){
        memset(dp,0,sizeof(dp));
        for(register int l=1;l<=m;++l){
            for(register int r=m;r>=l;--r){
                dp[l][r]=max(dp[l-1][r]+a[now][l-1]*po[m-r+l-1],dp[l][r+1]+a[now][r+1]*po[m-r+l-1]);
            }
        }
        int maxn=0;
        for(register int i=1;i<=m;++i)    maxn=max(maxn,dp[i][i]+po[m]*a[now][i]);

        ans+=maxn;
    }

    print(ans);
    return 0;
}
