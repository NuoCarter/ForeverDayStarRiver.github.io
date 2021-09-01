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
const int N=2e6+3;
#define int long long
int prime[N],tot,n,m,MOD;
int gg[N],cnt[N],g[N],sum1[N],sum2[N];
bool isprime[N];
inline int Inc(int a,int b){a+=b;return a>=MOD ? a-MOD :a;}
inline void Init(int lim){
    g[1]=gg[1]=1;
    for(register int i=2;i<=lim;++i){
        if(!isprime[i]) prime[++tot]=i,g[i]=1,gg[i]=2;
        for(register int j=1;j<=tot&&prime[j]*i<=lim;++j){
            isprime[prime[j]*i]=true;
            gg[i*prime[j]]= i%prime[j]==0 ? gg[i]+1 : 2 ;
            g[i*prime[j]]= i%prime[j]==0 ? g[i] : g[i]*gg[i];
            if(i%prime[j]==0) break;
        }
        cnt[i]=g[i]*gg[i]%MOD;
    }cnt[1]=1;
    return;
}
inline void Get(){
    for(register int t=1;t<=min(n,m);++t)
        for(register int i=1;i<=(n/t);++i)
            sum1[t]=Inc(sum1[t],cnt[i*t]);
    for(register int t=1;t<=(min(n,m));++t)
        for(register int i=1;i<=(m/t);++i)
            sum2[t]=Inc(sum2[t],cnt[i*t]);
    return;
}
signed main(){
    read(n),read(m),read(MOD);Init(2e6);
    Get();int ans=0;
    for(register int i=1;i<=min(n,m);++i)   ans=Inc(ans,sum1[i]*sum2[i]%MOD);
    print(ans);
    return 0;
}
