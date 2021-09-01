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
const int N=2e4+3,M=1e5+3;
struct E{
    int u,v,op;
    E(){}
    E(int _u,int _v,int _op){u=_u,v=_v,op=_op;}
}e[M];
inline bool Cmp2(E x,E y){return x.op<y.op;}
int fa[N],tot,head[N],n,m;
vector<E> e1,e2;
//bcj
inline int Get(int x){return x==fa[x] ? x : fa[x]=Get(fa[x]);}
inline void Merge(int x,int y){fa[Get(x)]=Get(y);return;}
inline void Init(){for(register int i=1;i<=n;++i)   fa[i]=i; return;}
int k;
vector<E> ans;
bool hav[N];
int main(){
    read(n),read(m),read(k);Init();
    for(register int i=1;i<=m;++i){
        read(e[i].u),read(e[i].v),read(e[i].op);
        if(e[i].op){
            if(Get(e[i].u)!=Get(e[i].v))    Merge(e[i].u,e[i].v);
        }
    }
    sort(e+1,e+m+1,Cmp2);int cnt=0;
    for(register int i=1;i<=m;++i){
        if(e[i].op==1)  break;
        if(Get(e[i].u)!=Get(e[i].v)){
            Merge(e[i].u,e[i].v);
            cnt++;
            ans.push_back(E{e[i].u,e[i].v,e[i].op});
        }
        if(cnt>k){
            puts("no solution");
            return 0;
        }
    }
    for(register int i=1;i<=n;++i){
        if(Get(i)!=Get(1)){
            puts("no solution");
            return 0;
        }
    }
    Init();
    for(register int i=1;i<=m;++i){
        if(!e[i].op){
            if(Get(e[i].u)!=Get(e[i].v)) Merge(e[i].u,e[i].v);
        }
        else break;
    }
    cnt=0;
    for(register int i=m;i>=1;--i){
        if(e[i].op==0)  break;
        if(Get(e[i].u)!=Get(e[i].v)){
            ans.push_back(E{e[i].u,e[i].v,e[i].op});
            Merge(e[i].u,e[i].v);
            cnt++;
        }
        if(cnt>n-1-k){
            puts("no solution");
            return 0;
        }
    }
    int siz=ans.size();
    int tot0=0,tot1=0;
    Init();
    for(register int i=0;i<siz;++i){
        Merge(ans[i].u,ans[i].v);
        if(ans[i].op)   tot1++;
        else tot0++;
    }
    for(register int i=1;i<=m;++i){
        int x=e[i].u,y=e[i].v;
        if(Get(x)!=Get(y)){
            if(e[i].op){
                if(tot1+1<=n-1-k){
                    Merge(x,e[i].v);
                    tot1++;
                    ans.push_back(E(e[i].u,e[i].v,e[i].op));
                }
            }
            else{
                if(tot0+1<=k){
                    Merge(e[i].u,e[i].v);
                    tot0++;
                    ans.push_back(E(e[i].u,e[i].v,e[i].op));
                }
            }
        }
    }
    for(register int i=1;i<=n;++i){
        if(Get(i)!=Get(1)){
            puts("no solution");
            return 0;
        }
    }
    for(register int i=0;i<n-1;++i){
        print(ans[i].u),putchar(' ');
        print(ans[i].v),putchar(' ');
        print(ans[i].op),putchar('\n');
    }
    return 0;
}
