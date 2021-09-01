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
int n,m,l[SN],r[SN],len,pos[N];
ll a[N],b[N],tag[SN];
inline void Build(){
    read(n),m=n;
    for(register int i=1;i<=n;++i)  read(a[i]);
    len=sqrt(n);for(register int i=1;i<=len;++i)    l[i]=(i-1)*len+1,r[i]=i*len;
    if(r[len]<n){l[len+1]=r[len]+1;r[++len]=n;}
    for(register int i=1;i<=len;++i)
        for(register int j=l[i];j<=r[i];++j)
            b[j]=a[j],pos[j]=i;
    for(register int i=1;i<=len;++i)    sort(b+l[i],b+r[i]+1);
    return;
}

inline void Copy(int L,int R){for(register int i=L;i<=R;++i)  b[i]=a[i];return;}

inline void Modify(int L,int R,ll d){
    int p=pos[L],q=pos[R];
    if(p==q){
        for(register int i=L;i<=R;++i)  a[i]+=d;
        Copy(l[p],r[p]);
        sort(b+l[p],b+r[p]+1);
    }
    else{
        for(register int i=p+1;i<q;++i)   tag[i]+=d;
        for(register int i=L;i<=r[p];++i) a[i]+=d;
        for(register int i=l[q];i<=R;++i)  a[i]+=d;
        Copy(l[q],r[q]);Copy(l[p],r[p]);
        sort(b+l[p],b+r[p]+1);
        sort(b+l[q],b+r[q]+1);
    }
    return;
}
inline int Query(int L,int R,ll lim){
    int p=pos[L],q=pos[R],res=0;
    if(p==q){
        for(register int i=L;i<=R;++i)
            if(a[i]+tag[p]<lim) ++res;
    }
    else{
        for(register int i=p+1;i<q;++i){
            int tmp=lower_bound(b+l[i],b+r[i]+1,lim-tag[i])-b;
            res+=tmp-l[i];
        }
        for(register int i=L;i<=r[p];++i) if(a[i]+tag[p]<lim)   ++res;
        for(register int i=l[q];i<=R;++i)   if(a[i]+tag[q]<lim)  ++res;
    }
    return res;
}
int main(){
    // system("fc my.out a4.out");
    // freopen("a4.in","r",stdin);
    // freopen("my.out","w",stdout);
    Build();
    int op,L,R;ll d;
    while(m--){
        // puts("????");
        read(op),read(L),read(R),read(d);
        if(op==0)   Modify(L,R,d);
        else    print(Query(L,R,d*d)),putchar('\n');
    }
    return 0;
}
