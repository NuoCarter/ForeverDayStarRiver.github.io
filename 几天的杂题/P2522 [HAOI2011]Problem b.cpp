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
const int N=5e4+3;
int mu[N],prime[N],tot,sum[N];
bool isprime[N];
inline void Init(int lim){
    mu[1]=1;
    for(register int i=2;i<=lim;++i){
        if(!isprime[i]) prime[++tot]=i,mu[i]=-1;
        for(register int j=1;j<=tot&&i*prime[j]<=lim;++j){
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0)   break;
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(register int i=1;i<=lim;++i)  sum[i]=sum[i-1]+mu[i];
    return;
}
inline ll Getans(int x,int y,int k){
    int tmp=min(x/k,y/k);
    ll ans=0;
    for(register int l=1,r=1;l<=tmp;l=r+1){
        r=min(x/(x/l),y/(y/l));
        ans+=1ll*(sum[r]-sum[l-1])*(x/l/k)*(y/l/k);
    }
    return ans;
}
int main(){
    Init(5e4);
    int T;read(T);
    while(T--){
        int a,b,c,d,k;
        read(a),read(b),read(c),read(d),read(k);
        ll ans1=Getans(b,d,k),ans2=Getans(b,c-1,k),ans3=Getans(a-1,d,k),ans4=Getans(a-1,c-1,k);
        print(ans1-ans2-ans3+ans4),putchar('\n');
    }
    return 0;
}
