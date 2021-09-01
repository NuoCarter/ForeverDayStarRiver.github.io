#include<bits/stdc++.h>
using namespace std;
template < typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return ;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
const int N=2e5+3,M=1e5+3;
int a[N],n,m,rt[N],cnt;
struct node{
    int ls,rs,sum;
    #define ls(x) c[x].ls
    #define rs(x) c[x].rs
    #define sum(x)  c[x].sum
}c[N<<5];
inline void Push_up(int x){
    sum(x)=sum(ls(x))+sum(rs(x));
    return;
}
inline void Modify(int &x,int pre,int l,int r,int d){
    x=++cnt;c[x]=c[pre];
    if(l==r){sum(x)=sum(pre)+1;return;}
    int mid=(l+r)>>1;
    if(mid>=d)  Modify(ls(x),ls(pre),l,mid,d);
    else Modify(rs(x),rs(pre),mid+1,r,d);
    Push_up(x);return;
}
inline int Query(int x,int pre,int l,int r,int L,int R){
    if(!x)  return 0;
    if(l>=L&&r<=R){return sum(x)-sum(pre);}
    int mid=(l+r)>>1,res=0;
    if(mid>=L)  res+=Query(ls(x),ls(pre),l,mid,L,R);
    if(mid<R)   res+=Query(rs(x),rs(pre),mid+1,r,L,R);
    return res;
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i){read(a[i]);Modify(rt[i],rt[i-1],0,M,a[i]);}
    // cout<<Query(rt[4],rt[0],0,M,4,5)<<"???";
    while(m--){
        int b,x,l,r;read(b),read(x),read(l),read(r);
        int now=0;
        for(register int i=17;i>=0;--i){
            int L,R,op;
            if(b&(1<<i))    op=0,L=now,R=now+(1<<i)-1;
            else op=1,L=now+(1<<i),R=now+(1<<(i+1))-1;
            if(Query(rt[r],rt[l-1],0,M,max(0,L-x),min(M,R-x))<1)  op^=1;
            now+=(op*(1<<i));
        }
        print(now^b),putchar('\n');
    }
    return 0;
}
