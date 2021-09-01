#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)){if(ch=='-'){f=true;}ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}
template <typename T>
inline void write(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10^48);
    return ;
}
#define ll long long
#define fl fflush(stdout)
const int N=5e4+5,MOD=1e9+7;
int n,m1,m2,m3;
int Q[N],t[N],val[N],Qr[N];
int Solve(int l,int r){
	if(l==r){
		val[Q[l]]=1;
		return Q[l];
	}
	int len=r-l+1,mid;
	if(len&1) mid=(l+r>>1);
	else mid=(l+r)>>1;
	printf("? %d ",len);
	for(int i=l;i<=r;i++) write(Q[i]),putchar(' ');
	write(mid+1);puts("");fl;//划分区间
	int num,cnt=0;
	read(num);
	for(int i=mid+1,x;i<=mid+num;i++) read(Qr[i]),t[Qr[i]]=true;
	for(int i=1;i<=n;i++) if(!t[i]) Q[++cnt]=i;//分到左边
	int Maxn=Solve(l,mid);//最大值对应编号
	int now=0;val[0]=-1;
	for(int i=mid+1,x;i<=mid+num;i++){
		printf("! %d %d\n",Qr[i],Maxn);fl;
		read(x);
		if(x!=0) val[Qr[i]]=x+val[Maxn];
		else if(len%2==0) val[Qr[i]]=val[Maxn]*2;
		if(val[Qr[i]]>val[now]) now=Qr[i];
	}
	return now;
}
signed main(){
	read(n),read(m1),read(m2),read(m3);
	for(int i=1;i<=n;i++) Q[i]=i;
	Solve(1,n);printf("A ");
	for(int i=1;i<=n;i++) write(val[i]),putchar(' ');puts("");fl;
    return 0;
}
// 4 2 3 1
/*
4 100 100 100

2 1 3

1 2


*/
