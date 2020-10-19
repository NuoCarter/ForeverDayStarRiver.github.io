## 题解 P4169 【[Violet]天使玩偶/SJY摆棋子】

[更好的阅读体验](https://www.luogu.com.cn/blog/NaCarter/solution-p4169)

# CDQ分治

作为一道离线分治的模板题，（貌似可以KD-Tree在线，但我不会）。

既然要离线做，那么肯定要获取整个操作序列。

## 前置芝士

**CDQ分治** 又叫 **基于时间的分治算法**（？书上这么说的（算法竞赛进阶指南））

对于每一个查询，计算 这个查询 的结果 其实就 等价于 **计算初始数据及在这次查询 之前的 所有修改**所带来的影响

计算方法：（以下来源算法竞赛进阶指南）

1.设 $mid=(l+r)>>1$ ,递归计算 $solve(l,mid)$

2 递归计算 $solve(mid+1,r)$

3 计算第$l~mid$项操作中的所有“修改”对第$mid+1$ ~ $r$ 项操作中所有“查询”造成的影响

**上述方法正确性的证明**

设第$k$项操作是“查询”。根据定义，若$k<=mid$，则$solve(l,mid)$已经计算了第$l$ ~ $k-1$ 项操作中的“修改”对它的影响。若$k>mid$，则$solve(mid+1,r)$计算到了第$mid+1$ ~ $k-1$项操作中的“修改”对它的影响，再加上第3部分的计算，即得到了第$l$ ~ $k-1$项操作中的修改对他的影响，故上述计算方法是正确的

## 题意

大致就是给你 $n$ 个初始点，有 $m$ 个操作，每次操作可以加入一个点或者进行一次查询，每次查询与给定的 $(x,y)$ 最近的点有多远

## 解决方法

曼哈顿距离公式：$\lvert x-x_i \lvert$ + $\lvert y-y_i \lvert$

根据第一我们要求的就是 $\lvert x-x_i \lvert$ + $\lvert y-y_i \lvert$ 的最小值，当然因为这个式子有一个绝对值，我能想到的带绝对值求解的话就一个暴力枚举。

所以为了去掉这个绝对值，我们可以将每一个询问都看作4个问题：

1.在$(x,y)$左上方的点最近的距离为？

2 在$(x,y)$右上方的点最近的距离为？ 

3 在$(x,y)$左下方的点最近的距离为？

4 在$(x,y)$右下方的点最近的距离为？

将上述问题的结果取一个最小值就行了

（将上面4个问题的距离公式化个简）

你就可以发现只用维护$(x+y)_{max}$和$(x-y)_{max}$就可以了


后面就是CDQ板子

唯一的难点就是树状数组维护了吧。。

### 树状数组维护

以下以左下方向计算为例

当然，你要先将整个点集按照 $x$ 坐标升序排序

（在哪里排序可以想想或者直接看代码）

1.扫到一个点$(x_i,y_i)$在树状数组中的第$y_i$个位置上更新值为$(x_i,y_i)$（取max操作）

2.扫到一个询问(x,y)	则在树状数组中查询$[0,y]$上的最大值 $val$
答案就为$x+y-val$

当你想到这剩下的应该就只有写代码的问题了。。

因为树状数组保存的是值域

**所以要开 $10^6$ 的空间，因为我懒，所以我全都开了**

### Code

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[1000005];
int maxn;
const int INF=0x3f3f3f3f;
struct node{int x,y,op;};
struct rec{int x,y,order;};
node a[1000005];
rec b[1000005];
int ans[1000005];
inline int lowbit(int x){return x&(-x);}
inline bool cmp(rec x,rec y){
	if(x.x!=y.x){
		return x.x<y.x;
	}
	return x.y<y.y;
}
inline void update(int x,int y){
	for(int i=x;i<maxn;i+=lowbit(i)){c[i]=max(c[i],y);}
	return;
}
inline int ask_max(int x){
	int ans=-INF;
	while(x>0){ans=max(ans,c[x]);x-=lowbit(x);}
	return ans;
}
inline void der(){
	for(int i=0;i<=maxn;++i){c[i]=-INF;}
	return;
}
inline void calculate(int fs,int fe,int tep,int bx,int by){
	int query;
	for(int i=fs;i!=fe;i+=tep){
		if(by==1){query=b[i].y;}
		else{query=maxn-b[i].y;}
		int goal=bx*b[i].x+by*b[i].y;
		if(a[b[i].order].op==1){update(query,goal);}
		else{ans[b[i].order]=min(ans[b[i].order],abs(goal-ask_max(query)));}
	}
	for(int i=fs;i!=fe;i+=tep){
		int y= by==1 ? b[i].y : maxn - b[i].y;
		if(a[b[i].order].op==1){
			for(int j=y;j<maxn;j+=lowbit(j))	c[j]=-INF;
		}
	}
	return;
}
inline void cdq(int l,int r){
	int mid=(l+r)>>1;
	if(l<mid){cdq(l,mid);}
	if(r>mid+1){cdq(mid+1,r);}
	int tot=0;
	for(int i=l;i<=r;++i){
		if(a[i].op==1&&i<=mid){
			b[++tot].x=a[i].x;
			b[tot].y=a[i].y;
			b[tot].order=i;
		}
		else if(a[i].op==2&&i>mid){
			b[++tot].x=a[i].x;
			b[tot].y=a[i].y;
			b[tot].order=i;
		}
	}
	sort(b+1,b+tot+1,cmp);
	calculate(1,tot+1,1,1,1);
	
	calculate(tot,0,-1,-1,-1);
	
	calculate(1,tot+1,1,1,-1);
	
	calculate(tot,0,-1,-1,1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].op=1;
		a[i].y++;
		maxn=max(maxn,a[i].y);
	}

	for(int i=n+1;i<=n+m;++i){
		scanf("%d%d%d",&a[i].op,&a[i].x,&a[i].y);
		a[i].y++;
		maxn=max(maxn,a[i].y);
	}	
	maxn++;	
	memset(ans,0x3f3f3f3f,sizeof(ans));
	memset(c,0xcf,sizeof(c));
	cdq(1,n+m);
	for(int i=n;i<=n+m;++i){
		if(a[i].op==2){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
```