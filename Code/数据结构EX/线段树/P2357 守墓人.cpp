#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
#define ll long long
struct node{
  int l,r;
  ll sum;
  ll lazy;
}t[800005];
int n,f;
ll a[200005];
inline
inline void update(int x){t[x].sum=t[lc].sum+t[rc].sum;}
inline void build(int x,int l,int r){
  t[x].l=l,t[x].r=r;
  if(l==r){t[x].sum=a[l];return;}
  int mid=(l+r)>>1;
  build(lc,l,mid);
  build(rc,mid+1,r);
  update(x);
  return;
}
inline void add(int x,ll m){
  t[x].lazy+=m;
  t[x].sum+=(t[x].r-t[x].l+1)*m;
  return;
}
inline void push_down(int x){
  if(t[x].lazy){
    add(lc,t[x].lazy);
    add(rc,t[x].lazy);
    t[x].lazy=0;
    return;
  }
  return;
}
inline void modify(int x,int L,int R,ll d){
  if(t[x].l>=L&&t[x].r<=R){
    add(x,d);
    return;
  }
  push_down(x);
  int mid=(t[x].l+t[x].r)>>1;
  if(mid>=L){modify(lc,L,R,d);}
  if(mid<R){modify(rc,L,R,d);}
  update(x);
  return;
}
inline ll query(int x,int L,int R){
  if(t[x].l>=L&&t[x].r<=R){return t[x].sum;}
  push_down(x);
  int mid=(t[x].l+t[x].r)>>1;
  ll ans=0;
  if(mid>=L){ans+=query(lc,L,R);}
  if(mid<R){ans+=query(rc,L,R);}
  return ans;
}
int main(){
  scanf("%d%d",&n,&f);
  for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
  build(1,1,n);
  int op,L,R;
  ll k;
  for(int i=1;i<=f;++i){
    scanf("%d",&op);
    if(op==1){
      scanf("%d%d%lld",&L,&R,&k);
      modify(1,L,R,k);
    }
    else if(op==2){
      scanf("%lld",&k);
      modify(1,1,1,k);
    }
    else if(op==3){
      scanf("%lld",&k);
      modify(1,1,1,-k);
    }
    else if(op==4){
      scanf("%d%d",&L,&R);
      printf("%lld\n",query(1,L,R));
    }
    else{
      printf("%lld\n",query(1,1,1));
    }
  }
  return 0;
}
