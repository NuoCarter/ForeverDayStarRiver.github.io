## 题解 CF1393B 【Applejack and Storages】

### 大致题意

开始给你 $n$ 个木板，之后有 $q$ 次操作

每次操作为以下两种方式：

$+x$ 为长为$x$的木板的个数$+1$

$-x$ 为长为$x$的木板的个数$-1$

每次进行操作后同时查询

所有木板中是否可以构成一个正方形和一个矩形



#### 那么就有以下4种情况：

1.有$8$个长度相等的木板（不会现在都有人不知道正方形算矩形吧）

2.有$>=6$个长度相等的木板1 有$>=2$个长度相等的木板2

3.有$>=4$个长度相等的木板1 有$>=4$个长度相等的木板2

4.有$>=4$个长度相等的木板1 有$>=2$个长度相等的木板2 有$>=2$个长度相等的木板3

很容易想到

只需要获取前三大的长度相等的木板的数量就可以了

#### 我用了一个。。桶+平衡树维护

平衡树用的fhq_treap。。没别的理由就是短。。

### 代码：

```cpp
//CF1393B Applejack and Storages
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+5;
int n;
int maxn;
int fhq_size;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
struct node{
	int l,r;
	int size;
	int val,key;
}fhq[2*N];
int cnt,root;
int firstx,secondx,thirdx;
int many[N];
inline int newnode(int val){
	fhq[++cnt].val=val;
	fhq[cnt].size=1;
	fhq[cnt].key=rand();
  fhq_size++;
	return cnt;
}
inline void update(int x){
	fhq[x].size=fhq[fhq[x].l].size+fhq[fhq[x].r].size+1;
	return;
}
inline void split(int now,int val,int &x,int &y){
	if(!now) x=y=0;
	else{
		if(fhq[now].val<=val){
			x=now;
			split(fhq[now].r,val,fhq[now].r,y);
		}
		else{
			y=now;
			split(fhq[now].l,val,x,fhq[now].l);
		}
		update(now);
	}
	return;
}
inline int merge(int x,int y){
	if(!x||!y)	return x+y;
	else{
		if(fhq[x].key>fhq[y].key){
			fhq[x].r=merge(fhq[x].r,y);
			update(x);
			return x;
		}
		else{
			fhq[y].l=merge(x,fhq[y].l);
			update(y);
			return y;
		}
	}
}
int x,y,z;
inline void insert(int val){
	split(root,val,x,y);
	root=merge(merge(x,newnode(val)),y);
	return;
}
inline int getrank(int val){
	split(root,val-1,x,y);
	int t=fhq[x].size+1;
	root=merge(x,y);
	return t;
}
inline int getval(int rank){
	int now=root;
	while(now){
		if(fhq[fhq[now].l].size+1==rank){
			break;
		}
		else if(fhq[fhq[now].l].size>=rank){
			now=fhq[now].l;
		}
		else{
			rank-=fhq[fhq[now].l].size+1;
			now=fhq[now].r;
		}
	}
	return fhq[now].val;
}
inline void del(int val){
	split(root,val,x,z);
	split(x,val-1,x,y);
	y=merge(fhq[y].l,fhq[y].r);
	root=merge(merge(x,y),z);
  fhq_size--;
	return;
}
inline int getpre(int val){
	split(root,val-1,x,y);
	int now=x;
	while(fhq[now].r){
		now=fhq[now].r;
	}
	root=merge(x,y);
	return fhq[now].val;
}
inline int getnext(int val){
	split(root,val,x,y);
	int now=y;
	while(fhq[now].l){
		now=fhq[now].l;
	}
	root=merge(x,y);
	return fhq[now].val;
}
int q,query;
int t,siz;
char op[2];
int main(){
	n=read();
  for(int i=1;i<=n;++i){
    t=read();
    many[t]++;
    maxn=max(maxn,t);
  }
  for(int i=1;i<=maxn;++i){
    if(many[i]) insert(many[i]);
  }
  q=read();
  while(q--){
    scanf("%s",op);
    query=read();
    if(op[0]=='+'){
      del(many[query]);
      many[query]++;
      insert(many[query]);
      siz=fhq[root].size;

      firstx=getval(siz);
      secondx=getval(siz-1);
      thirdx=getval(siz-2);

      if(firstx>=8||(firstx>=6&&secondx>=2)||(firstx>=4&&secondx>=4)||(firstx>=4&&secondx>=2&&thirdx>=2)){puts("YES");}
      else{puts("NO");}
    }
    else{
      del(many[query]);
      many[query]--;
      insert(many[query]);
      siz=fhq[root].size;

      firstx=getval(siz);
      secondx=getval(siz-1);
      thirdx=getval(siz-2);

      if(firstx>=8||(firstx>=6&&secondx>=2)||(firstx>=4&&secondx>=4)||(firstx>=4&&secondx>=2&&thirdx>=2)){puts("YES");}
      else{puts("NO");}
    }
  }
  return NuoCarter;
}

```