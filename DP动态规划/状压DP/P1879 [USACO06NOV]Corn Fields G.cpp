#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
const int p=100000000;
ll f[13][1<<12],n,m,g[1<<12],h[1<<12],a[13][13];
ll dp[13];

int main(){
	read(n),read(m);
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
			read(a[i][j]);
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
			dp[i]=(dp[i]<<1)+a[i][j];
	for(register int i=0;i<(1<<m);i++){
		if(!(i&(i>>1))&&!(i&(i<<1))){
			g[i]=1;
			if((i&dp[1])==i) f[1][i]=1;
		}
	}
	for(register int x=2;x<=n;x++)
		for(register int j=0;j<(1<<m);j++)
			if(((j&dp[x-1])==j)&&g[j])
				for(register int k=0;k<(1<<m);k++)
					if(((k&dp[x])==k)&&!(j&k)&&g[k]){
						f[x][k]=(f[x][k]+f[x-1][j])%p;
					}
	int ans=0;
	for(register int i=0;i<(1<<m);i++)
		ans=(ans+f[n][i])%p;
	print(ans);
    return 0;
}
