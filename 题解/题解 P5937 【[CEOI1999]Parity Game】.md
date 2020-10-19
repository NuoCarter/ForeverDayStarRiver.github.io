## 题解 P5937 【[CEOI1999]Parity Game】



## 解法：扩展域+离散化

首先观察到：这个01序列的长度 n 为$10^9$

一个并查集的 fa 数组加上扩展域应该要开2倍空间，$10^9$肯定是开不下的

而 m 的范围仅仅为$5*10^3$

所以优先考虑对询问的 开始位置与结束位置 进行离散化

### 可以对题目条件进行一定的转化：

区间$[i,j]$中有多少个1

因为这是一个01序列

所以上面的问题等价于：

求出$sum_i-sum_{j-1}$（sum表示前缀和）

那么题目中给出的奇偶性也就等价于：

如果 区间$[i,j]$为 $odd$

可以转化为

$sum_i$与$sum_{j-1}$奇偶性不同

如果 区间$[i,j]$为 $even$ 

则

$sum_i$与$sum_{j-1}$奇偶性相同

### 上述转化就很明显得暗示了这是一个关于扩展域的并查集算法

代码1也很容易

#### code:


```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int,int> ha;
int fa[40005];
int tot;
int op[10005];
inline int get(int x){return fa[x]==x ? x : fa[x]=get(fa[x]);}
inline void merge(int x,int y){fa[get(x)]=get(y);return;}
int query1[10005];
int query2[10005];
int a[10005];
int b[10005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		
		scanf("%d%d",&query1[i],&query2[i]);
		char t[10];
		scanf("%s",t);
		query1[i]-=1;
		if(t[0]=='e'){op[i]=2;}
		else{op[i]=1;}
		if(ha.count(query1[i])==0)	ha[query1[i]]=++tot;
		if(ha.count(query2[i])==0)	ha[query2[i]]=++tot;
		a[i]=ha[query1[i]];
		b[i]=ha[query2[i]];
	}		
	for(int i=1;i<=2*tot;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		int x=a[i];
		int y=b[i];
		if(op[i]==2){
			if(get(x+tot)==get(y)||get(x)==get(y+tot)){
				printf("%d\n",i-1);
				return 0;
			}
			else{merge(x,y);merge(x+tot,y+tot);}
		}
		else{
			if(get(x)==get(y)||get(x+tot)==get(y+tot)){
				printf("%d\n",i-1);
				return 0;
			}
			merge(x+tot,y);
			merge(y+tot,x);
		}
	}
	printf("%d\n",m);
	return 0;
}
```