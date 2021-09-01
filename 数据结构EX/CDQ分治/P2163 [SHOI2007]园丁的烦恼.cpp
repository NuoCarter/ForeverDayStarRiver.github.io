#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	x=0;char ch=getchar();bool f=false;
	while(!isdigit(ch)){if(ch=='-'){f=true;}ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return ;
}
template <typename T>
inline void print(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10^48);
	return ;
}
const int N=4e6+5;
int n,m,Cnt,Acnt;
#define ll long long
struct Query{
	int x,y,id,op;
	bool operator < (const Query &B) const{return (x==B.x)?(y==B.y?op:y<B.y):(x<B.x);}
}Q[N],tmp[N];
int Ans[N];
void CDQ_Divide(int l,int r){
	if(l==r) return ;
	int mid=(l+r)>>1;
	CDQ_Divide(l,mid),CDQ_Divide(mid+1,r);
	int posl=l,posr=mid+1,pos=l,tot=0;
	while(posl<=mid&&posr<=r){
		if(Q[posl].y<=Q[posr].y) tot+=Q[posl].op,tmp[pos++]=Q[posl++];
		else Ans[Q[posr].id]+=tot,tmp[pos++]=Q[posr++];
	}
	while(posl<=mid) tmp[pos++]=Q[posl++];
	while(posr<=r) Ans[Q[posr].id]+=tot,tmp[pos++]=Q[posr++];
	for(int i=l;i<=r;i++) Q[i]=tmp[i];
	return ;
}
int main(){
	read(n),read(m);
	for(int i=1,x,y;i<=n;i++) read(x),read(y),Q[++Cnt]=Query{x,y,0,1};
	for(int i=1,a,b,c,d;i<=m;i++){
		read(a),read(b),read(c),read(d);
		Q[++Cnt]=Query{a-1,b-1,++Acnt,0};
		Q[++Cnt]=Query{a-1,d,++Acnt,0};
		Q[++Cnt]=Query{c,b-1,++Acnt,0};
		Q[++Cnt]=Query{c,d,++Acnt,0};
	}
	sort(Q+1,Q+Cnt+1);
	CDQ_Divide(1,Cnt);
	for(int i=1;i+3<=Acnt;i+=4) print(Ans[i+3]+Ans[i]-Ans[i+1]-Ans[i+2]),putchar('\n');
	return 0;
}
