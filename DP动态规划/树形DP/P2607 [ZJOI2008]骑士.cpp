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
#define ll long long
const int N=1e6+3;
int head[N],to[N],Next[N],tot,n;

inline void Addedge(int u,int v){to[++tot]=v,Next[tot]=head[u],head[u]=tot;return;}

ll f[N][3],a[N];
inline void Dfs(int x,int fa){

}
int main(){
    read(n);
    for(register int i=1;i<=n;++i){
        int y;read(a[i]);read(y);
        Addedge()
    }
    return 0;
}
