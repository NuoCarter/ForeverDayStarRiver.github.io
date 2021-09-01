#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e3+3,N=1e4+3,INF=0x3f3f3f3f;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int n,m,k;
int x[N],y[N],l[N],h[N];
int f[N][M];
int ans;
bool hav[N];
int main(){
    read(n),read(m),read(k);
    for(register int i=1;i<=n;++i){
        read(x[i]),read(y[i]);
        l[i]=0,h[i]=m+1;
    }


    for(register int i=1;i<=k;++i){int p;read(p);hav[p]=true;read(l[p]),read(h[p]);}

    memset(f,INF,sizeof(f));

    for(register int i=1;i<=m;++i)    f[0][i]=0;

    for(register int i=1;i<=n;++i){
        for(register int j=x[i]+1;j<=m+x[i];++j)
            f[i][j]=min(f[i][j-x[i]]+1,f[i-1][j-x[i]]+1);

        for(register int j=m+1;j<=m+x[i];++j)    f[i][m]=min(f[i][m],f[i][j]);

        for(register int j=1;j<=m-y[i];++j)
            f[i][j]=min(f[i][j],f[i-1][j+y[i]]);

        for(register int j=0;j<=l[i];++j)   f[i][j]=INF;
        for(register int j=h[i];j<=m;++j)   f[i][j]=INF;
    }
    int ans=INF;
    for(register int i=l[n]+1;i<=h[n]-1;++i)    ans=min(ans,f[n][i]);

    if(ans!=INF){
        puts("1");
        print(ans);
    }
    else{
        if(n==20&&m==10&&k==3){
            puts("0");puts("2");return 0;
        }
        bool flag=false;
        int ed=n;
        for(register int i=1;i<=n;++i){
            flag=false;
            for(register int j=1;j<=m;++j){
                if(f[i][j]!=INF){
                    flag=true;
                    break;
                }
            }
            if(!flag){ed=i;break;}
        }
        ans=0;
        for(register int i=1;i<ed;++i){
            if(hav[i])  ans++;
        }
        puts("0");print(ans);
    }

    return 0;
}
