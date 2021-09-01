#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return;
}
template<typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
const int N=2e6+3,M=2e5+3;
#define lowbit(x) x&(-x)
int c[N],n,t,m;
struct node{
    int d1,d2,d3;
}
inline void Add(int x,int d){for(register int i=x;i<=n;i+=lowbit(i))    c[i]+=d;return;}
inline int Query(int x){int res=0;for(register int i=x;i>0;i-=lowbit(i))    res+=c[i];return res;}

int main(){
    read(t),read(n);

    while(true){
        m++;
    }

    return 0;
}
