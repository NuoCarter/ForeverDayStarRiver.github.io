#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
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
}fhq[N];
int cnt,root;
inline int newnode(int val){
	fhq[++cnt].val=val;
	fhq[cnt].size=1;
	fhq[cnt].key=rand();
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
	while(fhq[now].l){now=fhq[now].l;}
	root=merge(x,y);
	return fhq[now].val;
}
int main(){
	n=read();
	int op,val;
	for(int i=1;i<=n;++i){
		op=read();
		val=read();
		if(op==1){insert(val);}
		else if(op==3){printf("%d\n",getrank(val));}
		else if(op==4){printf("%d\n",getval(val));}
		else if(op==5){printf("%d\n",getpre(val));}
		else if(op==6){printf("%d\n",getnext(val));}
		else{del(val);}
	}

	return 0;
}
