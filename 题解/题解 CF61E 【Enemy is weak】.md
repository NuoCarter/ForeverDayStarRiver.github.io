# 题解 CF61E 【Enemy is weak】

这篇题的意思很简单？

就是三元逆序对的个数：

众所周知，利用一些简单的知识，珂以得出一个简单的结论：

每一个数的三元逆序对个数=左边比它大的数 * 右边比它小的个数

因为这道题的范围 $n \leq 10^6$,且$a_i \leq 10^9$

所以单纯的值域树状数组无法开下 $a_i$ 那么大的空间，

这个简单，简简单单离散化即可：

Code:
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll c1[1000005],c2[1000005],ans1[1000005],ans2[1000005],a[1000005];
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

```