# CF489E Hiking 题解

形如
从$n$个物体中选出$k$个，求出：
$$
\frac{\Sigma_{i=1}^{k} a_i}{\Sigma_{i=1}^{k} b_i}(Min | Max)
$$
这样的问题，一般采用二分答案解决。

如果你现在对于二分答案一无所知的话，请去做几道板子题练练手。

回到这个题：

## 题意

有$n$个点，每一个点有一个权值$b_i$和一个值$x_i$

求出$\frac{\Sigma_{j=1}^{k} \sqrt{a_j-a_{j-1}-l}}{\Sigma_{j=1}^{k} b_j}(Min)$

看一看数据范围：

二分答案的复杂度为($log$ $V$)

算下来的话答案判定的复杂度是可以支持$O(n^2)$的

所以我考虑了递推或者说$DP$?

## 解题过程：

设此时我们要判定的为$mid$

我们设代价为$\Sigma_{i=1}^{k}{\sqrt{a_j-a_{j-1}-l}}-mid*\Sigma_{i=1}^{k}b[i]$）

再设$f[i][j]$为第$i$个营地到第$j$个营地的代价

定义一个数组$dp[i]$表示到达第$i$个营地的最小代价

那么转移方程可以推出是这样的：

``` cpp
f[i][j]=sqrt(fabs(a[i].x-a[j].x-l))-x*a[i].b;
//dp[i]=min(dp[i],f[i][j]+dp[j]);
if(dp[i]>f[i][j]+dp[j]){mypath[i]=j;dp[i]=f[i][j]+dp[j];}

```

因为要求限制了必须在$n$结束，所以我们只需要判定$dp[n]$是否$\leq0$就可以了。

二分答案的答案判定就是这样。

路径的记录也在上面的代码中

整个复杂度$O(n^2logn)$

## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int n;
double l;
double eps=1e-10;

double f[1005][1005];

const int INF=0x3f3f3f3f;
double ud[1005];
struct node{
	double x,b;
}a[1005];
int mypath[1005];
inline bool check(double x){
	for(int i=1;i<=n;++i){ud[i]=INF;}
	ud[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
				f[i][j]=sqrt(fabs(a[i].x-a[j].x-l))-x*a[i].b;
				//ud[i]=min(ud[i],f[i][j]+ud[j]);
				if(ud[i]>f[i][j]+ud[j]){mypath[i]=j;ud[i]=f[i][j]+ud[j];}
		}
	}
	return ud[n]<=0;
}
int pre[1005];
inline void print(int x){
	if(!x){return;}
	print(mypath[x]);
	printf("%d ",x);
}
int main(){
	// freopen("hiking.in","r",stdin);
	// freopen("hiking.out","w",stdout);
	scanf("%d%lf",&n,&l);
	double L=0,R=0;
	double suma=0,sumb=0;
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&a[i].x,&a[i].b);
		suma+=a[i].x;
	}
	R=1e7;
	double mid,res;
	while(L+eps<R){
		mid=(L+R)/2.0;
		if(check(mid)){
			R=mid;
			res=mid;
		}
		else{L=mid;}
	}
	print(n);
	return 0;
}
```