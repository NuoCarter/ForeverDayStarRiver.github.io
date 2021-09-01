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
#define int long long
const int N=15,M=1e5+3,INF=1e17;
int n,m,a[N][M],b[N][M],cost[N][M];
bool can[N][N];
int sta[N],f[N][1<<N],g[N][1<<N];

signed main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            read(a[i][j]);

    for(register int i=1;i<=n;++i){
        read(b[i][0]);
        for(register int j=1;j<=b[i][0];++j) read(b[i][j]);
        sort(b[i]+1,b[i]+b[i][0]+1);
        for(register int j=1;j<=n;++j)
            for(register int k=1;k<=b[i][0];++k)
                cost[i][j]+=a[j][b[i][k]];
    }
    for(register int i=1;i<=n;++i){
        for(register int j=i+1;j<=n;++j){
            can[i][j]=can[j][i]=true;
            int nowi=1,nowj=1;
            while(nowi<=b[i][0]&&nowj<=b[j][0]){
                if(b[i][nowi]==b[j][nowj]){can[i][j]=can[j][i]=false;break;}
                if(b[i][nowi]>b[j][nowj])   nowj++;
                else nowi++;
            }
        }
    }
    for(register int now=1;now<(1<<n);++now){
        int top=0;
        for(register int i=1;i<=n;++i){
            if(now&(1<<(i-1))){
                for(register int j=1;j<=top;++j){
                    if(!can[sta[j]][i]){
                        for(register int k=1;k<=n;++k) g[k][now]=INF;
                        break;
                    }
                }
                sta[++top]=i;
                for(register int j=1;j<=n;++j){
                    g[j][now]+=cost[i][j];
                }
            }
        }
    }
    for(register int i=1;i<(1<<n);++i)  f[1][i]=g[1][i];

    for(register int i=2;i<=n;++i){
        for(register int now=0;now<(1<<n);++now){
            f[i][now]=f[i-1][now];
            for(register int s=now;s;s=(s-1)&now) f[i][now]=min(f[i][now],f[i-1][now^s]+g[i][s]);
        }
    }
    print(f[n][(1<<n)-1]);
    return 0;
}
/*
2 3
4 1 1
4 1 5
2 1 2
2 1 3
*/
/* QaQ wyh & lyr Forever */
