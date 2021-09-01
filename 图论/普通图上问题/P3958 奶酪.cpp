#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline ll read_LL(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
struct node{ll x,y,z;}che[2005];
int n;
ll h,r;
const int N=1005;
int head[N],Next[N*N*2],to[N*N*2],tot;
int T;
inline bool redist(int io,int jo){ull res=sqrt((che[io].x-che[jo].x)*((che[io].x-che[jo].x))+(che[io].y-che[jo].y)*((che[io].y-che[jo].y))+(che[io].z-che[jo].z)*((che[io].z-che[jo].z)));return res<=2*r;}
inline void add(int u,int v){
	to[++tot]=v;
	Next[tot]=head[u];
	head[u]=tot;
}
bool vis[1005];
bool flag=false;
inline void dfs(int x){
	vis[x]=true;
	if(x==n+2){flag=true;}
	for(int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(!vis[y]){dfs(y);}
	}
	return;
}
int main(){
	T=read();
	while(T--){
		n=read(),h=read_LL(),r=read_LL();
		flag=false;
		memset(Next,0,sizeof(Next));
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(to));
		memset(che,0,sizeof(che));
		memset(vis,false,sizeof(vis));
		for(int i=2;i<=n+1;++i){che[i].x=read_LL(),che[i].y=read_LL(),che[i].z=read_LL();}
		for(int i=2;i<=n+1;++i){
			for(int j=i+1;j<=n+1;++j){
				if(redist(i,j)){add(i,j);add(j,i);}
			}
			if(che[i].z-r<=0){
				add(1,i);
				add(i,1);
			}
			if(che[i].z+r>=h){
				add(n+2,i);
				add(i,n+2);
			}
		}
		dfs(1);
		if(flag)	puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
3
2 4 1
0 0 1
0 0 3
2 5 1
0 0 1
0 0 4
2 5 2
0 0 2
2 0 4


*/
