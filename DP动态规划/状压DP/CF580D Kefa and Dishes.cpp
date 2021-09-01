#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll N = 20;
ll n,m,k;
ll ww[N];
ll G[N][N];
ll ans = 0;
ll dp[1 << N][N];
int main(){
    read(n),read(m),read(k);
    for(register int i=1;i<=n;i++) read(ww[i]);
    memset(G,0,sizeof G);
    for(register int i=1;i<=k;i++){
        ll x,y,val;
        read(x),read(y),read(val);
        G[y][x] = val;
    }
    memset(dp,0,sizeof dp);
    for(register int i=1;i<=n;i++){
        dp[1<<(i-1)][i] = ww[i];
    }
    for(register int i=1;i<(1<<n);i++){
        //枚举状态
        ll cnt = 0;
        for(register int j=0;j<30;j++){
            if(i & (1ll << j)) cnt++;
        }
        for(register int j=0;j<n;j++){
            if(i & (1ll << j)){
                for(register int k=0;k<n;k++){
                    if((i & (1ll << k)) == 0){
                        dp[i | (1ll << k)][k+1] = max(dp[i | (1ll << k)][k+1],dp[i][j+1]+ww[k+1]+G[k+1][j+1]);
                    }
                }
            }
        }
        for(register int j=0;j<n;j++){
            if(i & (1ll << j)){
                if(cnt == m) ans = max(ans,dp[i][j+1]);
            }
        }
    }
    print(ans);
    return 0;
}
