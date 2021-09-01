#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=103,T=103,M=1003;
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
int t,n,m;
int dp[M*10],tep;
int p[T][N];

int main(){
    read(t),read(n),read(m);
    for(register int i=1;i<=t;++i)
        for(register int j=1;j<=n;++j){
            read(p[i][j]);
        }
    for(register int i=1;i<t;++i){
        memset(dp,0,sizeof(dp));
        for(register int j=1;j<=n;++j){
            for(register int k=p[i][j];k<=m;++k){
                dp[k]=max(dp[k],dp[k-p[i][j]]+p[i+1][j]-p[i][j]);
                // cout<<dp[k]<<" "<<k<<endl;
            }
        }
        m+=dp[m];

    }
    print(m);
    return 0;
}
