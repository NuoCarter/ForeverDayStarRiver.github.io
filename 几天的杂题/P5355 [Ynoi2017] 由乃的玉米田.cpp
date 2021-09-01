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
const int N=2e5+3,M=1e3;
int a[N],n,m,pos[N],c,cnt[N];
struct node{
    int op,l,r,id,x;
    node(){}
    node(int _op,int _l,int _r,int _id,int _x){op=_op,l=_l,r=_r,id=_id,x=_x;}
    bool operator < (const node &B) const{return (pos[l]^pos[B.l]) ? pos[l] < pos[B.l] : (pos[l]&1) ? r<B.r : r>B.r;}
};
vector<node> Q,D[M];
bool ans[N];
bitset<N> Dec,Inc;
int oo[N];
inline void Add(int x){
    cnt[a[x]]++;if(cnt[a[x]]==1)    Dec[a[x]]=1,Inc[N-a[x]]=1;
    return;
}
inline void Del(int x){
    cnt[a[x]]--;if(cnt[a[x]]==0)    Dec.reset(a[x]),Inc.reset(N-a[x]);
    return;
}
int lst[N],mxr[N];
int main(){
    read(n),read(m);int len=sqrt(n);
    for(register int i=1;i<=n;++i) read(a[i]),pos[i]=(i-1)/len+1,c=max(c,a[i]);
    for(register int i=1;i<=m;++i){
        int op,l,r,x;read(op),read(l),read(r),read(x);
        if(op==4&&x<=len) D[x].push_back(node(op,l,r,i,x));
        else Q.push_back(node(op,l,r,i,x));
        oo[i]=op;
    }
    sort(Q.begin(),Q.end());
    int nowl=1,nowr=0;
    int siz1=Q.size();
    for(register int i=0;i<siz1;++i){
        while(nowl>Q[i].l)  Add(--nowl);
        while(nowr<Q[i].r)  Add(++nowr);
        while(nowl<Q[i].l)  Del(nowl++);
        while(nowr>Q[i].r)  Del(nowr--);
        if(Q[i].op==1){if(((Dec<<Q[i].x)&Dec).any()) ans[Q[i].id]=true;}
        else if(Q[i].op==2){
            if(((Inc>>(N-Q[i].x))&Dec).any())
            ans[Q[i].id]=true;
        }
        else if(Q[i].op==3){
            int now=Q[i].x;
            for(register int j=1;j*j<=now;++j)
                if(now%j==0) if(Dec.test(now/j)&&Dec.test(j)){ans[Q[i].id]=true;break;}
        }
        else{
            for(register int j=1;j*Q[i].x<=c;++j)
                if(Dec[j]&&Dec[j*Q[i].x]){ans[Q[i].id]=true;break;}
        }
    }
    for(register int x=1;x<=len;++x){
        int now=0;memset(lst,0,sizeof(lst)),memset(mxr,0,sizeof(mxr));
        for(register int i=1;i<=n;++i){
            lst[a[i]]=i;
            if(a[i]*x<N) now=max(now,lst[a[i]*x]);
            if(a[i]%x==0)   now=max(now,lst[a[i]/x]);
            mxr[i]=now;
        }
        int siz=D[x].size();
        for(register int i=0;i<siz;++i) if(mxr[D[x][i].r]>=D[x][i].l) ans[D[x][i].id]=true;
    }
    for(register int i=1;i<=m;++i){
        if(ans[i])  puts("yuno");
        else puts("yumi");
    }
    return 0;
}
/*
2 1
2 4
2 1 2 8
*/
