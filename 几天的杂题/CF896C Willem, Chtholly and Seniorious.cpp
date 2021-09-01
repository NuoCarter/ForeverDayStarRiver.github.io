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
const int N=1e5+3,MOD7=1e9+7,MOD9=1e9+9;
int n,m,seed,vmax,a[N];
#define ll long long
#define IT set<node>::iterator
struct node{
    int l,r;
    mutable ll v;
    node(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
    bool operator < (const node &B) const{
        return l<B.l;
    }
};
set<node> s;
IT Split(int pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos) return it;
    --it;int L=it->l,R=it->r;ll V=it->v;s.erase(it);s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).first;
}
inline void Assign(int l,int r,int val){
    IT it2=Split(r+1);IT it1=Split(l);
    s.erase(it1,it2);s.insert(node(l,r,val));
    return;
}
inline void Add(int l,int r,ll d){
    IT itr=Split(r+1),itl=Split(l);
    for(;itl!=itr;++itl)    itl->v+=d;
    return;
}
inline ll Kth(int l,int r,ll k){
    vector<pair<ll,int> > vec;vec.clear();
    IT itr=Split(r+1),itl=Split(l);
    for(;itl!=itr;++itl)    vec.push_back(make_pair(itl->v,itl->r-itl->l+1));
    sort(vec.begin(),vec.end());
    for(vector<pair<ll,int> >::iterator it=vec.begin();it!=vec.end();++it){
        k-=it->second;
        if(k<=0) return it->first;
    }
    return -1ll;
}
inline ll Quick_pow(int x,int p,int mod){
    x%=mod;int res=1;for(;p;p>>=1,x=(x*x)%mod) res=(p&1) ? (res*x)%mod : res;
    return res;
}
inline ll Sum(int l,int r,int p,int mod){
    IT itr=Split(r+1),itl=Split(l);ll res=0;
    for(;itl!=itr;itl++)
        res=(res+((itl->r-itl->l+1)*Quick_pow(itl->v,p,mod))%mod)%mod;
    return res;
}
ll rnd(){
    ll ret=seed;
    seed=(seed*7+13)%MOD7;
    return ret;
}
signed main(){
    read(n),read(m),read(seed),read(vmax);
    for (int i=1; i<=n; ++i){
        a[i] = (rnd() % vmax) + 1;
        s.insert(node(i,i,a[i]));
    }
    s.insert(node(n+1, n+1, 0));
    for (register int i =1; i <= m; ++i){
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r)  swap(l,r);
        int x, y;
        if (op == 3)
            x = (rnd() % (r-l+1)) + 1;
        else
            x = (rnd() % vmax) +1;
        if (op == 4)
            y = (rnd() % vmax) + 1;
        if (op == 1)
            Add(l, r, x);
        else if (op == 2)
            Assign(l, r, x);
        else if (op == 3)
            print(Kth(l, r, x)),putchar('\n');
        else
            print(Sum(l,r,x,y)),putchar('\n');
    }
    return 0;
}
