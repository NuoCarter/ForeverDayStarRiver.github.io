#include<bits/stdc++.h>
using namespace std;
#define lc x<<1
#define rc x<<1|1
#define ll long long
int n,m;
struct node{
	int l,r;
	long long sum;
	ll lazy;
};
node c[400005];
int a[100005];
inline void update(int x){
	c[x].sum=c[x<<1].sum+c[x<<1|1].sum;
	return;
}
inline void build(int l,int r,int x){
	c[x].l=l;
	c[x].r=r;
	if(l==r){
		c[x].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
	return;
}
inline void add(int x,int t){
	c[x].lazy+=t;
	c[x].sum+=(c[x].r-c[x].l+1)*t;
	return;
}
inline void push_down(int x){
	if(c[x].lazy){
		add(lc,c[x].lazy);
		add(rc,c[x].lazy);
		c[x].lazy=0;
	}
	return;
}
inline void modify(int x,int L,int R,int t){
	if(c[x].r<L||c[x].l>R) return;
	if(c[x].l>=L&&c[x].r<=R){add(x,t);return;}
	push_down(x);
	int mid=(c[x].l+c[x].r)>>1;
	if(mid>=L){modify(lc,L,R,t);}
	if(mid<R){modify(rc,L,R,t);}
	update(x);
	return;
}
inline ll query(int x,int L,int R){
	if(c[x].l>=L&&c[x].r<=R){return c[x].sum;}
	if(c[x].l>R||c[x].r<L){return 0;}
	push_down(x);
	int mid=(c[x].l+c[x].r)>>1;
	ll ans=0;
	if(mid>=L){ans+=query(lc,L,R);}
	if(mid<R){ans+=query(rc,L,R);}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){scanf("%d",&a[i]);}
	build(1,n,1);
	for(int i=1;i<=m;++i){
		char op[2];
		int l,r;
		scanf("%s",op);
		scanf("%d%d",&l,&r);
		if(op[0]=='Q'){
			printf("%lld\n",query(1,l,r));
		}
		else{
			int t;
			scanf("%d",&t);
			modify(1,l,r,t);
		}
	}
	return 0;
}
