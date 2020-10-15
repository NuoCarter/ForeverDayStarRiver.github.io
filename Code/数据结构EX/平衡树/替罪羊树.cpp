#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const double alpha=0.78;
struct node{
	int l,r,val;
	int size,fact;
	bool del;
}tzy[N];
int cnt,root;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void newnode(int &now,int val){
	now=++cnt;
	tzy[now].val=val;
	tzy[now].size=tzy[now].fact=1;
	tzy[now].del=true;
	return ;
}
void update(int now,int end){
	if(!now) return ;
	if(tzy[end].val<tzy[now].val) update(tzy[now].l,end);
	else update(tzy[now].r,end);
	tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
	return ;
}
bool imbalence(int now){
	if(max(tzy[tzy[now].l].size,tzy[tzy[now].r].size)>tzy[now].size*alpha
	||tzy[now].size-tzy[now].fact>tzy[now].size*0.3) return true;
	return false;
}
vector<int> vec;
void ldr(int now){
	if(!now) return ;
	ldr(tzy[now].l);
	if(tzy[now].del) vec.push_back(now);
	ldr(tzy[now].r);
	return ;
}
void lift(int l,int r,int &now){
	if(l==r){
		now=vec[l];
		tzy[now].l=tzy[now].r=0;
		tzy[now].size=tzy[now].fact=1;
		return ;
	}
	int mid=(l+r)>>1;
	while(l<mid&&tzy[vec[mid]].val==tzy[vec[mid-1]].val)mid--;
	now=vec[mid];
	if(l<mid)lift(l,mid-1,tzy[now].l);
	else tzy[now].l=0;
	lift(mid+1,r,tzy[now].r);
	tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
	tzy[now].fact=tzy[tzy[now].l].fact+tzy[tzy[now].r].fact+1;
	return ;
}
void rebuild(int &now){
	vec.clear();
	ldr(now);
	if(vec.empty()){
		now=0;
		return ;
	}
	lift(0,vec.size()-1,now);
	return ;
}
void check(int &now,int end){
	if(now==end)return ;
	if(imbalence(now)){
		rebuild(now);
		update(root,now);
		return ;
	}
	if(tzy[end].val<tzy[now].val) check(tzy[now].l,end);
	else check(tzy[now].r,end);
	return ;
}
void insert(int &now,int val){
	if(!now){
		newnode(now,val);
		check(root,now);
		return ;
	}
	tzy[now].size++,tzy[now].fact++;
	if(val<tzy[now].val) insert(tzy[now].l,val);
	else insert(tzy[now].r,val);
	return ;
}
void del(int now,int val){
	if(tzy[now].del&&tzy[now].val==val){
		tzy[now].del=false;
		tzy[now].fact--;
		check(root,now);
		return ;
	}
	tzy[now].size--,tzy[now].fact--;
	if(val<tzy[now].val) del(tzy[now].l,val);
	else del(tzy[now].r,val);
	return ;
}
int getrank(int val){
	int now=root,rank=1;
	while(now){
		if(val<=tzy[now].val) now=tzy[now].l;
		else{
			rank+=tzy[now].del+tzy[tzy[now].l].fact;
			now=tzy[now].r;
	    }
	}
	return rank;
}
int getnum(int rank){
	int now=root;
	while(now){
		if(tzy[now].del&&rank==tzy[tzy[now].l].fact+tzy[now].del) break;
		else if(rank<=tzy[tzy[now].l].fact) now=tzy[now].l;
		else{
			rank-=tzy[tzy[now].l].fact+tzy[now].del;
			now=tzy[now].r;
		}
	}
	return tzy[now].val;
}
int main(){
	int t;
	t=read();
	while(t--){
		int opt,x;
		opt=read(),x=read();
		switch(opt){
			case 1:insert(root,x);break;
			case 2:del(root,x);break;
			case 3:printf("%d\n",getrank(x));break;
			case 4:printf("%d\n",getnum(x));break;
			case 5:printf("%d\n",getnum(getrank(x)-1));break;
			case 6:printf("%d\n",getnum(getrank(x+1)));break;
		}
	}
	return 0;
}
