#include<bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch))  f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int dp[4005];
int n,a[4];
bool hav[4005];
int main(){
    read(n),read(a[1]),read(a[2]),read(a[3]);
    hav[0]=true;
    for(register int i=1;i<=3;++i){
        for(register int j=a[i];j<=n;++j){
            if(hav[j-a[i]]) dp[j]=max(dp[j],dp[j-a[i]]+1),hav[j]=true;
        }
    }
    print(dp[n]);
    return 0;
}
