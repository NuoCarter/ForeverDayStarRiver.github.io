#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000005;
const int INF = 1e55;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int m,n,ans=INF,cnt,tot,head[N],siz[N],c[N],f[N],d[N];

struct Edge{
    int nxt,to,w;
}a[N];

inline void Add(int x,int y,int w){
    a[++tot].to=y;
    a[tot].nxt=head[x];
    a[tot].w=w;
    head[x]=tot;
}

inline void dfs (int u, int fa) {
	siz[u] = c[u];
	for(int i = head[u]; i; i = a[i].nxt) {
		int v = a[i].to;
		if(v == fa) continue;
		dfs(v,u);
		siz[u] += siz[v];
		f[u] = f[u] + f[v] + siz[v] * a[i].w;
	}
}

inline void dp (int u, int fa) {
	for(int i = head[u]; i; i = a[i].nxt) {
		int v = a[i].to;
		if(v == fa) continue;
		d[v] =d[u] - siz[v]*a[i].w + (cnt - siz[v])*a[i].w;
		ans = min(ans, d[v]);
		dp(v,u);
	}
}

signed main() {
    read(n);
	for(int i=1;i<=n;++i){
        read(c[i]);
		cnt += c[i];
	}
	for(int i=1,u,v,w;i<n;++i){
        read(u),read(v),read(w);
		Add(u,v,w);Add(v,u,w);
	}
	dfs(1,0);d[1]=f[1];
	ans = min(ans, d[1]);
	dp(1,0);
	print(ans);
	return 0;
}
