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
const int N=5e4+3,SN=1e3+3;
int n,m,pos[N];
ll a[N],l[SN],r[SN],sum[SN],tag[SN];
inline void Modify(int L,int R,ll d){
    if(pos[L]==pos[R])  for(register int i=L;i<=R;++i)  a[i]+=d,sum[pos[i]]+=d;
    else{
        for(register int i=pos[L]+1;i<pos[R];++i)    tag[i]+=d;
        for(register int i=L;i<=r[pos[L]];++i)  a[i]+=d,sum[pos[i]]+=d;
        for(register int i=l[pos[R]];i<=R;++i)  a[i]+=d,sum[pos[i]]+=d;
    }
    return;
}
int main(){
    read(n),m=n;
    for(register int i=1;i<=n;++i)    read(a[i]);
    int len=sqrt(n);
    for(register int i=1;i<=len;++i)    l[i]=(i-1)*len+1,r[i]=i*len;
    if(r[len]<n){l[len+1]=r[len]+1;r[++len]=n;}
    for(register int i=1;i<=len;++i)
        for(register int j=l[i];j<=r[i];++j)
            pos[j]=i,sum[i]+=a[j];
    int op,L,R;ll c;
    while(m--){
        read(op),read(L),read(R),read(c);
        if(op==0) Modify(L,R,c);
        else print(a[R]+tag[pos[R]]),putchar('\n');
    }
    return 0;
}
