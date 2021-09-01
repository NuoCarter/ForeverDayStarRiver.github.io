#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T&x){
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
const int N=4e4+3;
int prime[N],phi[N],tot;
bool isprime[N];
inline void Init(int n){
    for(register int i=2;i<=n;++i){
        if(!isprime[i]) prime[++tot]=i,phi[i]=i-1;
        for(register int j=1;j<=tot;++j){
            if(prime[j]*i>n)    break;
            isprime[i*prime[j]]=true;
            phi[i*prime[j]] = i%prime[j]==0 ? phi[i]*prime[j]  : phi[i]*(prime[j]-1);
        }
    }
    return;
}
int main(){
    int n;read(n);Init(n);if(n==1){puts("0");return 0;}
    int ans=0;for(register int i=1;i<=n-1;++i)    ans+=phi[i];
    print((ans<<1)+3);
    return 0;
}
