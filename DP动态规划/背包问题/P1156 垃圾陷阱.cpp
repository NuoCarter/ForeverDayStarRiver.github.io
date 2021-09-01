#include<bits/stdc++.h>
using namespace std;
const int T=1005,N=103,D=103;
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
int n,d;
struct node{
    int t,f,h;
}a[N];

inline bool cmp(node x,node y){return x.t<y.t;}

int maxlife[D];
int main(){
    read(d),read(n);
    for(register int i=1;i<=n;++i)    read(a[i].t),read(a[i].f),read(a[i].h);

    sort(a+1,a+n+1,cmp);
    
    maxlife[0]=10;
    for(register int i=1;i<=n;++i){
        for(register int j=d;j>=0;--j){
            if(maxlife[j]>=a[i].t&&j+a[i].h>=d){print(a[i].t);return 0;}
            if(maxlife[j]>=a[i].t){maxlife[j]+=a[i].f;}
            if(j>=a[i].h) maxlife[j]=max(maxlife[j],maxlife[j-a[i].h]);
        }
    }
    print(maxlife[0]);

    return 0;
}
