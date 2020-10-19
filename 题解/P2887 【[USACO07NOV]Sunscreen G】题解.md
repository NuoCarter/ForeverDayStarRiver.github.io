## P2887 【[USACO07NOV]Sunscreen G】题解

考虑转化题目条件：

给定的奶牛的$min,max$

相当于给定了一条线段的 左端点 l 和右端点 r

而给的防晒霜就相当于给了若干个点

答案就是线段能覆盖的点的数量

## 贪心证明：

每一个点有两个值：$spa_i,many_i$

每条线段有一个 $l,r$

如果将所有点按照$spa_i$降序排列

将所有线段按照 $l$ 降序排列

对于所有的线段匹配到的一定是当前最差的一个点，因为只有这样才能保证覆盖到更多的点。

那么什么样的点才是最差的呢。。

一定是在线段范围中值最大的点，因为更小的点珂以匹配更多的线段。

所以排完序后一波模拟匹配即可。

Code:
```cpp
#include<bits/stdc++.h>
using namespace std;
int C,L,ans;
const int N=2505;
struct node{int l,r;}a[N];
struct sipa{int sp,ma;}spa[N];
inline bool cmp1(node x,node y){return x.l>y.l;}
inline bool cmp2(sipa x,sipa y){return x.sp>y.sp;}
int main(){
  scanf("%d%d",&C,&L);
  for(int i=1;i<=C;++i){scanf("%d%d",&a[i].l,&a[i].r);}
  for(int i=1;i<=L;++i){scanf("%d%d",&spa[i].sp,&spa[i].ma);}
  sort(a+1,a+C+1,cmp1);
  sort(spa+1,spa+L+1,cmp2);
  for(int i=1;i<=C;++i)
		for(int j=1;j<=L;++j) {
			if(spa[j].sp>=a[i].l&&spa[j].sp<=a[i].r&&spa[j].ma>0) {
				ans++;
				spa[j].ma--;
				break;
			}
		}

	printf("%d\n", ans);
  return 0;
}

```