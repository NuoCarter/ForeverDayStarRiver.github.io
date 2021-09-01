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
const int N=2e5+3,M=2050,O=2001,MOD=1e9+7;
int a[N],b[N],jc[N],inv[N],dp[M<<1][M<<1],n;
inline int Inc(int x,int y){x+=y;return x>=MOD ? x-MOD :x;}
inline int Dec(int x,int y){x-=y;return x<0 ? x+MOD :x;}
inline int Quick_pow(int x,int p){int res=1;for(;p;p>>=1,x=(x*x)%MOD) res=p&1 ? (res*x)%MOD :res;return res;}
inline void Pre(){
    jc[0]=1;for(register int i=1;i<=(O<<2);++i) jc[i]=(jc[i-1]*i)%MOD;
    inv[O<<2]=Quick_pow(jc[O<<2],MOD-2);for(register int i=O*4-1;i>=0;--i)  inv[i]=(inv[i+1]*(i+1))%MOD;
    return;
}
inline int C(int nn,int mm){return jc[nn]*inv[mm]%MOD*inv[nn-mm]%MOD;}
signed main(){
    read(n);for(register int i=1;i<=n;++i)  read(a[i]),read(b[i]),dp[-a[i]+O][-b[i]+O]+=1;
    Pre();
    for(register int i=1;i<=O*2;++i)
        for(register int j=1;j<=O*2;++j)
            dp[i][j]=Inc(dp[i][j],Inc(dp[i-1][j],dp[i][j-1]));

    int ans=0;
    for(register int i=1;i<=n;++i){
        ans=Inc(ans,dp[a[i]+O][b[i]+O]);
        ans=Dec(ans,C(2*(a[i]+b[i]),2*a[i]));
    }
    ans=(ans*Quick_pow(2,MOD-2))%MOD;print(ans);
    return 0;
}
