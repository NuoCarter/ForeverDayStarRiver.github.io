#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll c1[1000005];
ll c2[1000005];
ll ans1[1000005];
ll ans2[1000005];
ll a[1000005];
ll tmp[1000005];
int la[1000005];
inline bool cmp(int x,int y){return x>y;}
inline int lowbit(int x){return x&(-x);}
inline void add1(int x,ll d){while(x<=n){c1[x]+=d;x+=lowbit(x);}return;}
inline ll query1(int x){ll res=0;while(x){res+=c1[x];x-=lowbit(x);}return res;}
inline void add2(int x,ll d){while(x<=n){c2[x]+=d;x+=lowbit(x);}return;}
inline ll query2(int x){ll res=0;while(x){res+=c2[x];x-=lowbit(x);}return res;}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i){
    scanf("%lld",&a[i]);
    tmp[i]=a[i];
  }
  sort(tmp+1,tmp+n+1);
  int len=unique(tmp+1,tmp+n+1)-(tmp+1);
  for(int i=1;i<=n;++i){la[i]=lower_bound(tmp+1,tmp+len+1,a[i])-tmp;}
  for(int i=n;i>=1;--i){
    ans1[i]=query1(la[i]-1);
    add1(la[i],1);
  }
  for(int i=1;i<=n;++i){
    ans2[i]=query2(n)-query2(la[i]);
    add2(la[i],1);
  }
  ll resu=0;
  for(int i=1;i<=n;++i){
    resu+=ans1[i]*ans2[i];
  }
  printf("%lld\n",resu);
  return 0;
}
