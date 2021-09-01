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
const int N=5e4+3;
int a,b,d,sum[N];
int prime[N],mu[N],tot;
bool isprime[N];
inline void Init(int lim){
    mu[1]=1;
    for(register int i=2;i<=lim;++i){
        if(!isprime[i]) prime[++tot]=i,mu[i]=-1;
        for(register int j=1;j<=tot&&prime[j]*i<=lim;++j){
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0) break;
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(register int i=1;i<=lim;++i)    sum[i]=sum[i-1]+mu[i];
    return;
}
#define ll long long
int main(){
    Init(5e4);
    int T;read(T);
    while(T--){
        read(a),read(b),read(d);
        ll ans=0;
        int tmp=min(a,b);
        for(register int l=1,r=1;l<=tmp;l=r+1){
            r=min(a/(a/l),b/(b/l));
            ans+=1ll*(sum[r]-sum[l-1])*(a/l/d)*(b/l/d);
        }
        print(ans),putchar('\n');
    }
    return 0;
}
