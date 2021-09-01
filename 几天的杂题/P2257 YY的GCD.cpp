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
#define ll long long
const int N=1e7+3;
int n,m,mu[N],prime[N],tot,sum[N],t[N];
bool isprime[N];
inline void Init(int lim){
    mu[1]=1;
    for(register int i=2;i<=lim;++i){
        if(!isprime[i]) prime[++tot]=i,mu[i]=-1;
        for(register int j=1;j<=tot&&prime[j]*i<=lim;++j){
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0)   break;
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(register int i=1;i<=tot;++i)
        for(register int j=1;j*prime[i]<=lim;++j) t[prime[i]*j]+=mu[j];
    for(register int i=1;i<=lim;++i)    sum[i]=sum[i-1]+t[i];
    return;
}
int main(){
    int T;read(T);
    Init(1e7);
    while(T--){
        read(n),read(m);ll ans=0;
        for(register int l=1,r=1;l<=min(n,m);l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=1ll*(n/l)*(m/l)*(sum[r]-sum[l-1]);
        }
        print(ans),putchar('\n');
    }
    return 0;
}
