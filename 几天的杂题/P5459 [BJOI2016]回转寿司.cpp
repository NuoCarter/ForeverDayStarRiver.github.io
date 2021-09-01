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
#define int long long
const int N=1e5+3;
int a[N],sum[N],n,minn,maxn;
int tmp[N],q[N],ans;
inline void CDQ(int l,int r){
    if(l==r)    return;
    int mid=(l+r)>>1;
    CDQ(l,mid),CDQ(mid+1,r);
    int now1=l,now2=mid+1,t=l-1,fr=l-1,ql=l,qr=l;
    while(now1<=mid&&now2<=r){
        if(sum[now1]<=sum[now2]){
            q[++fr]=sum[now1];
            tmp[++t]=sum[now1++];
        }
        else{
            while(ql<=fr&&sum[now2]-sum[ql]>=minn) ql++;
            while(qr<=fr&&sum[now2]-sum[qr]>maxn)  qr++;
            ans+=ql-qr;tmp[++t]=sum[now2++];
        }
    }
    while(now1<=mid)    tmp[++t]=sum[now1++];
    while(now2<=r){
        while(ql<=fr&&sum[now2]-q[ql]>=minn)    ql++;
        while(qr<=fr&&sum[now2]-q[qr]>maxn) qr++;
        ans+=ql-qr;
        tmp[++t]=sum[now2++];
    }
    for(register int i=l;i<=r;++i)  sum[i]=tmp[i];
    return;
}
signed main(){
    read(n),read(minn),read(maxn);
    for(register int i=1;i<=n;++i)  read(a[i]),sum[i]=sum[i-1]+a[i];
    CDQ(0,n);
    print(ans);
    return 0;
}
