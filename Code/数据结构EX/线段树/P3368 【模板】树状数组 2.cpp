#include<bits/stdc++.h>
using namespace std;
#define mid (a[x].l+a[x].r)>>1
#define lc x<<1
#define rc x<<1|1
int n,m;
struct tree{
  int sum;
  int l,r;
  int tag_add;
  }a[2000005];
  int orig[2000005];
  inline void update(int x){a[x].sum=a[lc].sum+a[rc].sum;return;}
  inline void build(int x,int l,int r){
    a[x].l=r;
    a[x].r=r;
    if(l==r){a[x].sum=orig[l];return;}
    build(lc,l,mid);
    build(rc,mid+1,r);
    update(x);
    return;
  }
  inline void push_down(int x){

  }
  inline void add(int x,int L,int R,int k){
    if(a[x].l>=L&&a[x].r<=R){a[x].sum+=(a[x].r-a[x].l+1)*k;a[x].tag_add+=k;}

  }
  int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){scanf("%d",&orig[i]);}
    build(1,1,n);
    for(int i=1;i<=m;i++){

    }
    return 0;
  }
