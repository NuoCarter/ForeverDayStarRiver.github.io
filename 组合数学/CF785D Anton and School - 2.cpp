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
inline void print (T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
#define ll long long
const int N=2e5+3;
const ll MOD=1e9+7;
inline ll Quick_pow(ll a,ll p){
    ll res=1;
    for(;p;p>>=1,a=(a*a)%MOD) res=p&1 ? (res*a)%MOD : res;
    return res;
}
ll jc[N],n,inv[N],r[N],l[N];
char s[N];
inline void Getinv(int n){
    jc[0]=1;for(register int i=1;i<=n;++i)  jc[i]=jc[i-1]*i%MOD;
    inv[n]=Quick_pow(jc[n],MOD-2);for(register int i=n-1;i>=0;--i)  inv[i]=inv[i+1]*(i+1)%MOD;
    return;
}
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);Getinv(len);
    for(register int i=1;i<=len;++i)    l[i]=s[i]=='(' ? l[i-1]+1 : l[i-1];
    for(register int i=len;i>=1;--i)    r[i]=s[i]==')' ? r[i+1]+1 : r[i+1];
    ll ans=0;
    for(register int i=1;i<=len;++i){
        if(s[i]=='('){
            if(!r[i])   continue;
            ans=(ans+jc[l[i]+r[i]-1]*inv[l[i]]%MOD*inv[r[i]-1]%MOD)%MOD;
        }
    }
    print(ans);
    return 0;
}
