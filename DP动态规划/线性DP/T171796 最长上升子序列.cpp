#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
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
int a[N],n,f[N];
int main(){
    read(n);
    for(int i=1;i<=n;i++)    read(a[i]);
    int ans=0;
    f[++ans]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>f[ans])    f[++ans]=a[i];
        else    f[lower_bound(f+1,f+ans+1,a[i])-f]=a[i];

    }
    printf("%d\n",ans);
    return 0;
}
