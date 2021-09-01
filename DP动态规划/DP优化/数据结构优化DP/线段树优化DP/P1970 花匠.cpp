#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define lc x<<1
#define rc x<<1|1
int n,h[N],h2[N],dp[N][2];
struct node{
  int l,r;
  int val0,val1;
  #define l(x)  c[x].l
  #define r(x)  c[x].r
  #define val0(x) c[x].val0//dp[..][0]max
  #define val1(x) c[x].val1//dp[...][1]max
}c[4*N];
inline void update(int x){
  val0(x)=max(val0(lc),val0(rc));
  val1(x)=max(val1(lc),val1(rc));
}
inline void build(int x,int l,int r){
  l(x)=l,r(x)=r;
  if(l==r){
    val0(x)=0,val1(x)=0;
    return;
  }
  int mid=(l+r)>>1;
  build(lc,l,mid);
  build(rc,mid+1,r);
  update(x);
}
inline void modify(int x,int go,int val,int op){
  if(l(x)==r(x)){
    if(op==0){val0(x)=max(val0(x),val);}
    else{val1(x)=max(val1(x),val);}
    return;
  }
  int mid=l(x)+r(x)>>1;
  if(mid>=go){modify(lc,go,val,op);}
  else{modify(rc,go,val,op);}
  update(x);
}
inline int query(int x,int L,int R,int op){
  if(l(x)>=L&&r(x)<=R){
    if(op==0){return val0(x);}
    else{return val1(x);}
  }
  int mid=l(x)+r(x)>>1;
  int res=0;
  if(mid>=L){res=max(res,query(lc,L,R,op));}
  if(mid<R){res=max(res,query(rc,L,R,op));}
  return res;
}
int ans;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i){scanf("%d",&h[i]);h2[i]=h[i];}
  sort(h2+1,h2+n+1);
  int len=unique(h2+1,h2+n+1)-h2-1;
  for(int i=1;i<=n;++i){h[i]=lower_bound(h2+1,h2+len+1,h[i])-h2;}
  len+=1;
  build(1,1,len);
  for(int i=1;i<=n;++i){
    dp[i][1]=query(1,1,h[i]-1,0)+1;
    modify(1,h[i],dp[i][1],1);
    dp[i][0]=query(1,h[i]+1,len,1)+1;
    modify(1,h[i],dp[i][0],0);
    ans=max(ans,max(dp[i][1],dp[i][0]));
  }
  // cout<<"????"<<endl;
  printf("%d\n",ans);
  return 0;
}
