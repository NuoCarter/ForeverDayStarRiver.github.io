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
const int N=20,INF=0x3f3f3f3f;
const double eps=1e-8;
int T,n,m;
double x[N],y[N];
int lst[1<<N],pass[N][N],dp[1<<N];
inline void Get(double &a,double &b,double X1,double Y1,double X2,double Y2){
    a=((X2/X1)*Y1-Y2)/(X2*(X1-X2));b=((X2*X2/(X1*X1))*Y1-Y2)/((X2*X2-X1*X2)/X1);
    return;
}
inline bool Check(double a,double b,double X,double Y){
    if(fabs(a*X*X+b*X-Y)<eps)   return true;
    return false;
}
int main(){
    read(T);
    for(register int i=0;i<=(1<<18);++i){
        int now=0;while(i&(1<<now))   now++;
        lst[i]=now+1;
    }
    while(T--){
        read(n),read(m);memset(dp,INF,sizeof(dp));memset(pass,0,sizeof(pass));
        for(register int i=1;i<=n;++i)  scanf("%lf%lf",&x[i],&y[i]);
        for(register int i=1;i<=n;++i){
            for(register int j=1;j<=n;++j){
                if(fabs(x[i]-x[j])<eps) continue;
                double a,b;
                Get(a,b,x[i],y[i],x[j],y[j]);
                if(a>-eps) continue;
                for(register int k=1;k<=n;++k){
                    if(Check(a,b,x[k],y[k])){
                        pass[i][j]|=(1<<(k-1));
                    }
                }
            }
        }
        dp[0]=0;
        for(register int i=0;i<(1<<n);++i){
            int now=lst[i];
            dp[i|(1<<(now-1))]=min(dp[i|(1<<(now-1))],dp[i]+1);
            for(register int k=1;k<=n;++k) dp[i|pass[now][k]]=min(dp[i|pass[now][k]],dp[i]+1);
        }
        print(dp[(1<<n)-1]),putchar('\n');


    }

    return 0;
}
