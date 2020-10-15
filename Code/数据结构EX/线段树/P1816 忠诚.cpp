#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
int n,m;
struct tree{
  int l,r;
  int value;
}a[400005];
int orig[100005];
void update(int x){
  a[x].value=min(a[x*2].value,a[x*2+1].value);
  return;
}
void build(int x,int l,int r){
  a[x].l=l;
  a[x].r=r;
  if(l==r)  {a[x].value=orig[l];return;}
  int mid=(l+r)>>1;
  build(x<<1,l,mid);
  build(x<<1|1,mid+1,r);
  update(x);
  return;
}
inline int query(int x,int L,int R){
  if(a[x].l>R||a[x].r<L)  {return 0x3f3f3f3f;}
  if(a[x].l>=L&&a[x].r<=R){return a[x].value;}
  return min(query(lc,L,R),query(rc,L,R));
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){scanf("%d",&orig[i]);}
  build(1,1,n);
  for(int i=1;i<=m;i++){
    int sl,sr;
    scanf("%d%d",&sl,&sr);
    printf("%d ",query(1,sl,sr));
  }
  return 0;
}
