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
struct node{
    int l,r;
    mutable int v;
    node(int L,int R=-1,int V=0):l(L),r(R),v(V){}
    bool operator < (const node &B) const{
        return l<B.l;
    }
};
int n,q;
#define IT set<node>::iterator
set<node> s;
inline IT Split(int pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos)  return it;
    --it;int L=it->l,R=it->r,V=it->v;s.erase(it);s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).first;
}
int ans;
inline void Assign(int l,int r,int val){
    IT itr=Split(r+1),itl=Split(l),it=itl;
    for(;itl!=itr;++itl) ans-=itl->v*(itl->r-itl->l+1);
    s.erase(it,itr);
    s.insert(node(l,r,val));
    ans+=val*(r-l+1);
    return;
}
int main(){
    read(n),read(q);
    s.insert(node(1,n,1));ans=n;
    for(register int i=1;i<=q;++i){
        int l,r,k;read(l),read(r),read(k);
        Assign(l,r,k-1);
        print(ans),putchar('\n');
    }
    return 0;
}
