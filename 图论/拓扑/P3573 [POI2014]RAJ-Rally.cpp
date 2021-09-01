#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=1e6+5,INF=0x3f3f3f3f;
template <typename T>
inline void read(T &x){
	x=0;char ch=getchar();bool f=false;
	while(!isdigit(ch)){f^=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
	x=f?-x:x;
}
template <typename T>
inline void print(T x){
	if(x<0){putchar('-');x=-x;}
	if(x>9){print(x/10);}
	putchar(x%10+48);
}
int n,m,h1[N],h2[N],tot1,tot2,in[N];
int order[N],cnt;
struct edge{
	int to,Next;
}e1[M],e2[M];
int f[N],g[N];
int ans=INF;
priority_queue<int> q1,q2;
inline void Addedge(int u,int v){
	e1[++tot1].to=v,e1[tot1].Next=h1[u],h1[u]=tot1;
	e2[++tot2].to=u,e2[tot2].Next=h2[v],h2[v]=tot2;
}
inline void topo(){
	queue<int> q;
	for(int i=1;i<=n;++i){g[i]=f[i]=1;if(in[i]==0){q.push(i),order[++cnt]=i;}}
	while(!q.empty()){int x=q.front();q.pop();
		for(int i=h1[x];i;i=e1[i].Next){
			int y=e1[i].to;in[y]--;
			if(!in[y]){q.push(y);order[++cnt]=y;}
		}
	}
}
int main(){
	read(n),read(m);
	for(int i=1,u,v;i<=m;++i){
		read(u),read(v);
		Addedge(u,v);
		in[v]++;
	}
	topo();
	for(int i=1;i<=n;++i){
		for(int j=h1[order[i]];j;j=e1[j].Next){
			int y=e1[j].to;f[y]=max(f[y],f[order[i]]+1);
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=h2[order[i]];j;j=e2[j].Next){
			int y=e2[j].to;g[y]=max(g[y],g[order[i]]+1);
		}
	}
	for(int i=1;i<=n;++i){q1.push(g[i]);}
	q1.push(0);
	for(int i=1;i<=n;++i){
		for(int j=h2[order[i]];j;j=e2[j].Next){
			int y=e2[j].to;
			q2.push(f[y]+g[order[i]]);
		}
		q2.push(g[order[i]]);
		while(q1.top()==q2.top()&&!q2.empty()){q1.pop(),q2.pop();}
		ans=min(ans,q1.top());
		for(int j=h1[order[i]];j;j=e1[j].Next){
			int y=e1[j].to;
			q1.push(f[order[i]]+g[y]);
		}
		q1.push(f[order[i]]);
	}
	print(ans-1);
	return 0;
}
