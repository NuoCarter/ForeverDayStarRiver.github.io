#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int f[N],c,d,n,m,k;
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
int main(){
    read(c),read(d),read(n),read(m),read(k);
    memset(f,0x3f3f3f3f,sizeof(f));
    f[0]=0;
    for(register int i=1;i<=n*m;++i){
        if(i>=1){
            f[i]=min(f[i],f[i-1]+d);
        }
        if(i>=n)    f[i]=min(f[i],f[i-n]+c);
    }
    int ans=0x3f3f3f3f;
    for(register int i=n*m-k;i<=n*m;++i)    ans=min(ans,f[i]);
    print(ans);
    return 0;
}
