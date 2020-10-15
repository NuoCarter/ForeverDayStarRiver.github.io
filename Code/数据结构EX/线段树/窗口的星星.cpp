#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch='0');ch=getchar();}
	return x*f;
}
inline ll read_LL(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch='0');ch=getchar();}
	return x*f;
}
int n,T;

struct seg_tree{
	int l,r;
	ll lazy,maxn;
	#define l(x) 	c[x].l
	#define r(x)	c[x].r
	#define lazy(x)	c[x].lazy
	#define maxn(x)	c[x].maxn
}c[N<<3];
struct node{int h,w,v;}a[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){

		}
	}

	return 0;
}
