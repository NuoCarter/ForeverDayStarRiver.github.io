#include<bits/stdc++.h>
using namespace std;
const int N=6e3+5;
int t,n,fa[N],siz[N];
struct edge{
  int from,to,val;
  friend bool operator < (const edge &x,const edge &y){return x.val<y.val;}
}e[N];
inline int get(int x){return x==fa[x] ? x : fa[x]=get(fa[x]);}
inline void merge(int x,int y){fa[x]=y;siz[y]+=siz[x];}
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(register int i=1;i<n;++i){scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].val);}
    sort(e+1,e+n);
    for(int i=1;i<=n;++i){fa[i]=i;siz[i]=1;}
    int ans=0;
    for(int i=1;i<n;++i){
      int x=get(e[i].from),y=get(e[i].to),w=e[i].val;
      ans+=(siz[x]*siz[y]-1)*(w+1);
      merge(x,y);
    }
    printf("%d\n",ans);
  }
  return 0;
}
