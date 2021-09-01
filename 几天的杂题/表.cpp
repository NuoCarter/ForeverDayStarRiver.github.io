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
const int N=1e4+3;
int prime[N],gg[N],g[N],tot,d[N];
bool isprime[N];
ll k;
inline void init(int n){
  for(int i=2;i<=n;++i){
    if(!isprime[i]){
      prime[++tot]=i;
      g[i]=1;
      gg[i]=2;
    }
    for(int j=1;j<=tot&&prime[j]*i<=n;++j){
      isprime[prime[j]*i]=true;
      gg[i*prime[j]]= i%prime[j]==0 ? gg[i]+1 : 2 ;
      g[i*prime[j]]= i%prime[j]==0 ? g[i] : g[i]*gg[i];
      if(i%prime[j]==0) break;
    }
    d[i]=g[i]*gg[i];
  }
  d[1]=1;return;
}

int main(){
    freopen("my.out","w",stdout);
    // init(1e4);
    putchar('{');
    for(register int i=1;i<=1e6;++i){
        int cnt=0;
        for(register int j=1;j<i;++j){
            if(d[j]>d[i])   cnt++;
            if(cnt>=2)  break;
        }
        if(cnt>=2)  continue;
        else print(i),putchar(',');
    }
    putchar('}');
    return 0;
}
