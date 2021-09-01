#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
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
int b,d;
char s[N],p[N];
int n,m,Next[N];
ll cnt[N];
int main(){
    read(b),read(d);
    scanf("%s",s);scanf("%s",p);
    n=strlen(s),m=strlen(p);
    for(register int i=0;i<m;++i){
        int now=i;
        for(register int j=0;j<n;++j)
            if(s[j]==p[now]){now++;if(now==m)  now=0,cnt[i]++;}

        Next[i]=now;
    }
    ll ans=0;int now=0;
    for(register int i=1;i<=b;++i)    ans+=cnt[now],now=Next[now];

    print(ans/d);
    return 0;
}
