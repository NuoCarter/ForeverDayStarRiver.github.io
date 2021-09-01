#include<bits/stdc++.h>
using namespace std;
#define lowbit(x)   x&(-x)
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
const int MOD=1e9+7,N=1e3+3,M=1e3+3;
int f[N][M],n,m,a[N],T,b[N];
int c[N];
inline int Inc(int a,int b){a+=b;return a>=MOD ? a-MOD : a;}

inline void Add(int x,int d){
    for(register int i=x;i<=n;i+=lowbit(i)) c[i]=Inc(c[i],d);
    return;
}
inline int Query(int x){
    int res=0;for(register int i=x;i>0;i-=lowbit(i)) res=Inc(res,c[i]);
    return res;
}
int main(){
    read(T);int now=1;
    while(T--){
        read(n),read(m);
        for(register int i=1;i<=n;++i)  read(a[i]),b[i]=a[i];
        sort(b+1,b+n+1);int len=unique(b+1,b+n+1)-(b+1);
        for(register int i=1;i<=n;++i){
            a[i]=lower_bound(b+1,b+len+1,a[i])-b;
            f[1][i]=1;
        }
        int ans=0;
        for(register int i=1;i<=n;++i)  ans=Inc(ans,f[m][i]);
        printf("Case #%d: ",now);print(ans),putchar('\n');
        now++;
    }
    return 0;
}
