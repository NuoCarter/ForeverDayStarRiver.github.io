#include<bits/stdc++.h>
using namespace std;
#define ls (id<<1)
#define rs (id<<1|1)
#define mid ((l+r)>>1)
const int maxn = 100010;
int n,q,cnt[27];char a[maxn];
struct node{
	int v[27],lazy;
	inline void cover(int x,int l,int r){
		lazy = x;
		memset(v,0,sizeof(v));
		v[x] = r - l + 1;
	}
}c[maxn<<2];
inline void pushup(int id){
	for(int i = 1;i <= 26;i++){
		c[id].v[i] = c[ls].v[i] + c[rs].v[i];
	}
}
inline void pushdown(int id,int l,int r){
	if(~c[id].lazy){
		c[ls].cover(c[id].lazy,l,mid);
		c[rs].cover(c[id].lazy,mid+1,r);
		c[id].lazy = -1;
	}
}
void build(int id,int l,int r){
	c[id].lazy = -1;
	if(l==r){
		c[id].v[a[l]-'a'+1] = 1;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
}
void update(int id,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		c[id].cover(v,l,r);
		return ;
	}
	pushdown(id,l,r);
	if(x<=mid){update(ls,l,mid,x,y,v);}
	if(y>mid){update(rs,mid+1,r,x,y,v);}
	pushup(id);
}
int query(int id,int l,int r,int x,int y,int col){
	if(x<=l&&r<=y){return c[id].v[col];}
	pushdown(id,l,r);
	if(y<=mid){return query(ls,l,mid,x,y,col);}
  else if(x>mid){return query(rs,mid+1,r,x,y,col);}
  else{return query(ls,l,mid,x,y,col) + query(rs,mid+1,r,x,y,col);}
}
char ans[maxn];
void solve(int id,int l,int r){
	if(l==r){
		for(int i = 1;i <= 26;i++){
			if(c[id].v[i]){ans[l] = i + 'a' - 1;break;}
		}
		return ;
	}
	pushdown(id,l,r);
	solve(ls,l,mid);
	solve(rs,mid+1,r);
}
int main(){
	cin>>n>>q;
  for(int i=1;i<=n;++i){cin>>a[i];}
	build(1,1,n);
	while(q--){
		int l,r,op;
    scanf("%d %d %d",&l,&r,&op);
		for(int i = 1;i <= 26;i++){
			cnt[i] = query(1,1,n,l,r,i);
		}
		if(op){
			for(int i = 1;i <= 26;i++){
				if(cnt[i]){update(1,1,n,l,l+cnt[i]-1,i);l+=cnt[i];}
			}
		}
    else{
			for(int i = 26;i >= 1;i--){
				if(cnt[i]){update(1,1,n,l,l+cnt[i]-1,i);l += cnt[i];}
			}
		}
	}
	solve(1,1,n);
	for(int i = 1;i <= n;i++){
		putchar(ans[i]);
	}
	return 0;
}
