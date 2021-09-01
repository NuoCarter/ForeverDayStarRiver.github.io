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
    putchar(x%10^48);return ;
}
#define int long long
const int MOD=1e9+7,M=1e5+3;
inline int Quick_pow(int p){
    int x=2,res=1;for(;p;p>>=1,x=(1ll*x*x)%MOD) res=(p&1)  ? (1ll*res*x)%MOD : res;
    return res;
}
inline int Inc(int a,int b){a+=b;return a>=MOD ? a-MOD : a;}
int prime[M],tot;
bool isprime[M];
inline void Init(int lim){
    for(register int i=2;i<=lim;++i){
        if(!isprime[i]) prime[++tot]=i;
        for(register int j=1;j<=tot&&prime[j]*i<=lim;++j){
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0)   break;
        }
    }
    return;
}
inline int Getmu(int x){
    int cnt=0;
    for(register int i=1;i<=tot&&1ll*prime[i]*prime[i]<=1ll*x;++i){
        int sum=0;
        if(x%prime[i]==0){
            cnt++;while(x%prime[i]==0)  x/=prime[i],sum++;
            if(sum>=2)  return 0;
        }
    }
    if(x!=1)    cnt++;
    if(cnt&1)   return MOD-1;
    else return 1;
}
int x,y;
signed main(){
    read(x),read(y);Init(1e5);
    if(y%x!=0){puts("0");return 0;}
    int tmp=y/x,ans=0;
    for(register int i=1;1ll*i*i<=1ll*tmp;++i){
        if(tmp%i==0){
            int t=tmp/i;
            // cout<<i<<" "<<Getmu(i)<<endl;
            // cout<<t<<" "<<Getmu(t)<<endl;
            ans=Inc(ans,Getmu(i)*Quick_pow(t-1)%MOD);
            if(t!=i)    ans=Inc(ans,Getmu(t)*Quick_pow(i-1)%MOD);
        }
    }
    print(ans);
    return 0;
}
