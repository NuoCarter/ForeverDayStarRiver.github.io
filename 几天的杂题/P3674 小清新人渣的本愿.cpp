#include<bits/stdc++.h>
using namespace std;
template<typename T>
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
const int N=2e5+3;
int a[N],n,m,pos[N],c,cnt[N];
struct node{
    int op,l,r,id,x;
    bool operator < (const node &B) const{return (pos[l]^pos[B.l]) ? pos[l] < pos[B.l] : (pos[l]&1) ? r<B.r : r>B.r;}
}Q[N];
bool ans[N];
bitset<N> Dec,Inc;
inline void Add(int x){
    // cout<<x<<"???"<<a[x]<<"????\n";
    cnt[a[x]]++;if(cnt[a[x]]==1)    Dec[a[x]]=1,Inc[N-a[x]]=1;
    return;
}
inline void Del(int x){
    cnt[a[x]]--;if(cnt[a[x]]==0)    Dec.reset(a[x]),Inc.reset(N-a[x]);
    return;
}
int main(){
    read(n),read(m);int len=sqrt(n);
    for(register int i=1;i<=n;++i) read(a[i]),pos[i]=(i-1)/len+1,c=max(c,a[i]);
    for(register int i=1;i<=m;++i){
        read(Q[i].op),read(Q[i].l),read(Q[i].r),read(Q[i].x);
        Q[i].id=i;
    }
    sort(Q+1,Q+m+1);
    int nowl=1,nowr=0;
    for(register int i=1;i<=m;++i){
        while(nowl>Q[i].l)  Add(--nowl);
        while(nowr<Q[i].r)  Add(++nowr);
        while(nowl<Q[i].l)  Del(nowl++);
        while(nowr>Q[i].r)  Del(nowr--);
        if(Q[i].op==1){if(((Dec<<Q[i].x)&Dec).any()) ans[Q[i].id]=true;}
        else if(Q[i].op==2){
            // for(register int j=0;j<=9;++j) cout<<Inc[j];
            if(((Inc>>(N-Q[i].x))&Dec).any())
            ans[Q[i].id]=true;
        }
        else{
            int now=Q[i].x;
            for(register int j=1;j*j<=now;++j)
                if(now%j==0) if(Dec.test(now/j)&&Dec.test(j)){ans[Q[i].id]=true;break;}
        }
    }
    for(register int i=1;i<=m;++i){
        if(ans[i])  puts("hana");
        else puts("bi");
    }
    return 0;
}
/*
2 1
2 4
2 1 2 8
*/
