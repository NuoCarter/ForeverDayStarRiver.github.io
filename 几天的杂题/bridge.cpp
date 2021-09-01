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
const int N=2e5+3,INF=2e9;
struct node{
    int pos,d;
    int id;
    bool operator < (const node &B) const{
        return pos<B.pos;
    }
}a[N],s1[N],s2[N];
int n,q,rev[N];
int top1,top2;
inline int Check(int mid,int t){
    int l=0,r=top1,res=0,sum=0;
    while(l<=r){
        int md=(l+r)>>1;
        if(s1[md].pos-t<=mid)    res=md,l=md+1;
        else r=md-1;
    }
    sum+=res;
    l=0,r=top2,res=0;
    while(l<=r){
        int md=(l+r)>>1;
        if(s2[md].pos+t<=mid)   res=md,l=md+1;
        else r=md-1;
    }
    return sum+res;
}
signed main(){
    s1[0].pos=-1e10,s2[0].pos=-1e10;
    read(n);
    for(register int i=1;i<=n;++i)  read(a[i].pos),a[i].id=i;
    for(register int i=1;i<=n;++i)  read(a[i].d);
    sort(a+1,a+n+1);
    for(register int i=1;i<=n;++i){
        rev[a[i].id]=i;
        if(a[i].d==0)   s1[++top1]=a[i];
        else s2[++top2]=a[i];
    }
    read(q);
    while(q--){
        int k,t;read(k),read(t);k+=1;
        int rank=rev[k];
        // cout<<rank<<"?????"<<endl;
        int l=-INF,r=INF,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(Check(mid,t)>=rank)  ans=mid,r=mid-1;
            else l=mid+1;
        }
        print(ans),putchar('\n');
    }
    return 0;
}
/*
5
1 3 5 8 9
1 1 1 0 0
3
3 2
0 7
1 5
*/
