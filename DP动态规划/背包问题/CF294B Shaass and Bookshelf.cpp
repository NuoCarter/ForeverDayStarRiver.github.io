#include<bits/stdc++.h>
using namespace std;
const int N=103;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int n,t[N],w[N];
int tot,dp[N*N];
int main(){
    read(n);
    for(register int i=1;i<=n;++i)    read(t[i]),read(w[i]),tot+=t[i];
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0]=0;
    for(register int i=1;i<=n;++i)
        for(register int j=tot;j>=t[i];--j)
            dp[j]=min(dp[j],dp[j-t[i]]+w[i]);


    for(register int i=tot;i>=0;--i){
        if(dp[i]<=tot-i){
            print(tot-i);return 0;
        }
    }
    print(tot);
    return 0;
}
