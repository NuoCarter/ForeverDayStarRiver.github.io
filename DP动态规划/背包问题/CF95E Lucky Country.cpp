#include<bits/stdc++.h>
#define register register
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=1e5+5,INF=0x3f3f3f3f;
template<typename T>
inline void read(T &x){
    x=0; bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=ch=='-';ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    x=f?-x:x;
}
template<typename T>
inline void print(T x){
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,tot;
int fa[N],siz[N],cnt[N],w[N],v[N],dp[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool check(int x){
	while(x){
		if(x%10!=4&&x%10!=7) return false;
		x/=10;
	}
	return true;
}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;read(x),read(y);
		fa[find(x)]=find(y);
	}
	for(int i=1;i<=n;i++) siz[find(i)]++;
	for(int i=1;i<=n;i++) if(siz[i]) cnt[siz[i]]++;
	for(int i=1;i<=n;i++){
		if(cnt[i]){
			int sum=1,now=1;
			w[++tot]=i,v[tot]=1;
			while(sum<cnt[i]){
				now<<=1;
				sum+=now;
				if(sum>cnt[i]){
					sum-=now;
					w[++tot]=i*(cnt[i]-sum);
					v[tot]=cnt[i]-sum;
					break;
				}
				w[++tot]=i*now;
				v[tot]=now;
			}
		}
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=tot;i++)
		for(int j=n;j>=w[i];j--)
			dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
	int ans=INF;
	for(int i=1;i<=n;i++) if(check(i)&&i) ans=min(ans,dp[i]);
	if(ans==INF) puts("-1");
	else print(ans-1);
    return 0;
}
