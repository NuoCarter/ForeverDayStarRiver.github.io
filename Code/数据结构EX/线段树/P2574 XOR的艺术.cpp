#include<bits/stdc++.h>
using namespace std;
struct node{
  int l,r,sum;
  int tag;
}a[800005];
int b[200005];
int n,m;
inline void update(int x){
  a[x].sum=a[x<<1].sum+a[x<<1|1].sum;
  return;
}
inline void change(int x){
  a[x].sum=a[x].r-a[x].l+1-a[x].sum;
  a[x].tag^=1;
  return;
}
inline void push_down(int x){
  if(a[x].tag){
    change(x<<1);
    change(x<<1|1);
    a[x].tag=false;
  }
  return;
}
inline void  big_change(int x,int L,int R){
  if(a[x].l>=L&&a[x].r<=R){
    change(x);
    return;
  }
  push_down(x);
  int mid=(a[x].l+a[x].r)>>1;
  if(L<=mid) big_change(x<<1,L,R);
  if(R>mid) big_change(x<<1|1,L,R);
  update(x);
}
inline void build(int x,int l,int r){
  a[x].l=l;
  a[x].r=r;
  if(l==r){
    a[x].sum=b[l];
    return;
  }
  int mid=(l+r)>>1;
  build(x<<1,l,mid);
  build(x<<1|1,mid+1,r);
  update(x);
  return;
}
inline int query(int x,int L,int R){
  if(a[x].l>=L&&a[x].r<=R) { return a[x].sum;}
  push_down(x);
  int ans=0;
  int mid=(a[x].l+a[x].r)>>1;
  if(L<=mid)  ans+=query(x<<1,L,R);
  if(R>mid)  ans+=query(x<<1|1,L,R);
  return ans;
}
int main(){
  scanf("%d%d",&n,&m);
  string t;
  cin>>t;
  for(int i=1;i<=n;++i){
    b[i]=t[i-1]-'0';
  }
  build(1,1,n);
  for(int i=1;i<=m;++i){
    int tepl,tepr;
    int wh;
    scanf("%d%d%d",&wh,&tepl,&tepr);
    if(wh==0){
        big_change(1,tepl,tepr);
    }
    else{printf("%d\n",query(1,tepl,tepr));}
  }
  return 0;
}
