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
const int N=203,K=103,MOD=9901;
int f[K][N];
int n,k;
int main(){
    read(n),read(k);
    f[1][1]=1;
    for(register int i=2;i<=k;++i){
        int lim2=(1<<(i+1))-1;
        for(register int j=i;j<=lim2;++j){
            for(register int k=i+1;k<=n;++k){

            }
        }
    }

    return 0;
}
