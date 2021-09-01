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
const int N=2e5+3;
int n,m,val[N],ans[N];
map<pair<int,int>,int> e;
#define IT map<pair<int,int>,int>::iterator
int main(){
    read(n),read(m);
    while(m--){
        char op[2];
        scanf("%s",op+1);
        if(op[1]=='+'){
            int x,y;read(x),read(y);
            if(x>y) swap(x,y);
            ans[x]-=val[y],ans[y]-=val[x];
            e[make_pair(x,y)]=1;
        }
        else if(op[1]=='!'){
            int x;read(x);
            val[x]++;
        }
        else{
            int x,y;read(x),read(y);
            if(x>y) swap(x,y);
            ans[x]+=val[y],ans[y]+=val[x];
            e.erase(make_pair(x,y));
        }
    }
    for(IT it=e.begin();it!=e.end();++it){
        pair<int,int> tmp=(*it).first;
        int x=tmp.first,y=tmp.second;
        ans[x]+=val[y],ans[y]+=val[x];
    }
    for(register int i=1;i<=n;++i)  print(ans[i]),putchar(' ');
    return 0;
}
