#include<bits/stdc++.h>
using namespace std;
#define lc fhq[x].l
#define rc fhq[x].r
const int N=1e5+5;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
    return x*f;
}
struct node{
  int l,r,val,key,size;
  #define l(x)  fhq[x].l
  #define r(x)  fhq[x].r
  #define val(x)  fhq[x].val
  #define key(x)  fhq[x].key
  #define size(x) fhq[x].size
}fhq[N];
int tot,root,n;
inline void update(int x){size(x)=size(lc)+size(rc)+1;}
//更新子树大小
inline int new_node(int val){
  val(++tot)=val;key(tot)=rand();size(tot)=1;
  return tot;
}
//新建结点顺便返回结点编号
inline void split(int now,int val,int &x,int &y){
  if(!now){x=y=0;}
  else{
    if(val(now)<=val){x=now;split(fhq[x].r,val,fhq[x].r,y);}
    else{y=now;split(fhq[y].l,val,x,fhq[y].l);}
    update(now);
  }
}
//按值 val 分裂
inline int merge(int x,int y){//返回root
  if(!x||!y){return x+y;}//返回其中一个不为空的结点
  if(key(x)>key(y)){fhq[x].r=merge(fhq[x].r,y);update(x);return x;}
  else{fhq[y].l=merge(x,fhq[y].l);update(y);return y;}
}
//合并两棵树，满足大根堆（父节点的 key>子节点的 key) 和 二叉搜索树的性质
inline void insert(int val){
  int x,y;split(root,val,x,y);
  root=merge(merge(x,new_node(val)),y);
}
//插入一个值操作，先按照 val 分裂为两棵树，x中所有值 <=val y中所有值 > val 将新结点与 x 树合并再与 y 合并
inline int get_rank(int val){
  int x,y;split(root,val-1,x,y);
  int ans=size(x)+1;root=merge(x,y);
  return ans;
}
//查找排名，将整棵树按照val-1分成 x,y两棵树，x的size就是排名
inline int get_val(int rank){
  int x=root;
  while(x){
    if(size(lc)+1==rank){break;}
    else if(size(lc)>=rank){x=lc;}
    else{rank-=size(lc)+1;x=rc;}
  }return val(x);
}
//和Treap差不多的用 rank 查找 val
inline void del(int val){int x,y,z;
  split(root,val,x,z);split(x,val-1,x,y); //x中的值<=val,在经历一次分裂后 y 中的值=val
  y=merge(fhq[y].l,fhq[y].r);//删除y的根(相当于删除一个值为 val 的结点)
  root=merge(merge(x,y),z);
  return;
}
//删除结点
inline int get_next(int val){
  int x,y;split(root,val,x,y);int now=y;
  while(fhq[now].l){now=fhq[now].l;}root=merge(x,y);
  return val(now);
}
//查找后继
inline int get_pre(int val){
  int x,y;split(root,val-1,x,y);int now=x;
  while(fhq[now].r){now=fhq[now].r;}root=merge(x,y);
  return val(now);
}
//查找先驱
int main(){
  n=read();
	for(int i=1,op,val;i<=n;++i){
		op=read(),val=read();
		if(op==1){insert(val);}
		else if(op==3){printf("%d\n",get_rank(val));}
		else if(op==4){printf("%d\n",get_val(val));}
		else if(op==5){printf("%d\n",get_pre(val));}
		else if(op==6){printf("%d\n",get_next(val));}
		else{del(val);}
	}


  return 0;
}
