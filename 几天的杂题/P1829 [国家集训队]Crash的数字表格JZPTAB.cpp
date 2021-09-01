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
const int MOD=20101009,N=1e7+3;
int prime[N],tot,mu[N],n,m,sum[N];
bool isprime[N];
inline int Inc(int a,int b){a+=b;return a>=MOD ? a-MOD  : a;}
inline int Dec(int a,int b){a-=b;return a<0  ? a+MOD : a;}
inline void Init(int lim){
    mu[1]=1;
    for(register int i=2;i<=lim;++i){
        if(!isprime[i]) prime[++tot]=i,mu[i]=-1;
        for(register int j=1;j<=tot&&i*prime[j]<=lim;++j){
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0)    break;
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(register int i=1;i<=lim;++i) sum[i]=(sum[i-1]+1ll*i*i*mu[i]%MOD)%MOD;
    return;
}
inline int Get(int a){return 1ll*(a+1)*a/2%MOD;}
inline int g(int a,int b){
    int res=0,lim=min(a,b);
    for(register int l=1,r=1;l<=lim;l=r+1){
        r=min(a/(a/l),b/(b/l));
        res=(res+1ll*Dec(sum[r],sum[l-1])*Get(a/l)%MOD*Get(b/l)%MOD)%MOD;
    }
    return res;
}
signed main(){
    Init(1e7);
    read(n),read(m);int tmp=min(n,m),ans=0;
    for(register int l=1,r=1;l<=tmp;l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=Inc(ans,1ll*(r-l+1)*(l+r)/2%MOD*g(n/l,m/l)%MOD);
    }
    print(ans);
    return 0;
}
