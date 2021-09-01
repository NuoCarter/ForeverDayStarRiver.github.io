#include<bits/stdc++.h>
using namespace std;
const int V=3003,P=303,INF=0x3f3f3f3f;
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
int v,p;
int loc[V];
int w[V][V],dp[V][V],goal[V][V];
int main(){
    read(v),read(p);
    for(register int i=1;i<=v;++i)  read(loc[i]);
    sort(loc+1,loc+v+1);
    for(register int i=1;i<=v;++i){
        w[i][i]=0;
        for(register int j=i+1;j<=v;++j)
            w[i][j]=w[i][j-1]+loc[j]-loc[(i+j)/2];

    }
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(register int i=1;i<=p;++i){
        goal[v+1][i]=v;
        for(register int j=v;j>=1;--j){
            int minn=INF,mink;
            for(register int k=goal[j][i-1];k<=goal[j+1][i];++k){
                if(dp[k][i-1]+w[k+1][j]<minn){
                    minn=dp[k][i-1]+w[k+1][j];
                    mink=k;
                }
            }
            dp[j][i]=minn;
            goal[j][i]=mink;
        }
    }
    print(dp[v][p]);
    return 0;
}
