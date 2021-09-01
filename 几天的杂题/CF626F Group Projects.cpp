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
const int N=205,K=1003,MOD=1e9+7;
int a[N],n,m;
int f[N][N][K];
inline int Inc(int x,int y){x+=y;return x>=MOD ? x-MOD : x;}
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)  read(a[i]);
    f[0][0][0]=1;sort(a+1,a+n+1);
    for(register int i=1;i<=n;++i){
        for(register int j=0;j<=i;++j){
            int del=a[i]-a[i-1];
            for(register int k=0;k<=m;++k){
                if(j!=0&&k-(j-1)*del>=0)    f[i][j][k]=Inc(f[i][j][k],f[i-1][j-1][k-(j-1)*del]);
                if(j!=n&&k-(j+1)*del>=0)    f[i][j][k]=Inc(f[i][j][k],1ll*f[i-1][j+1][k-(j+1)*del]*(j+1)%MOD);
                if(k-j*del>=0)  f[i][j][k]=Inc(f[i][j][k],1ll*f[i-1][j][k-j*del]*j%MOD),f[i][j][k]=Inc(f[i][j][k],f[i-1][j][k-j*del]);
            }
        }
    }
    int ans=0;for(register int i=0;i<=m;++i)  ans=Inc(ans,f[n][0][i]);
    print(ans);
    return 0;
}
