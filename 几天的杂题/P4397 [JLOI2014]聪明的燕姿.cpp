#include<bits/stdc++.h>
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
#define ll long long
const int N=1e7+5,M=6e4,INF=0x3f3f3f3f;
int S,prime[M],tot,ans[N];
bool vis[M+5];
inline void Init(){
	vis[0]=vis[1]=true;
	for(int i=2;i<=M;i++){
		if(!vis[i]) prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=M;j++){vis[i*prime[j]]=true;if(i%prime[j]==0) break;}
	}
	return ;
}
inline bool Check(int x){
	if(x==2) return true;
	if(x%2==0) return false;
	for(int i=3;i*i<=x;i+=2) if(x%i==0)return false;
	return true;
}
void Dfs(int st,int ed,int now){
	if(ed==1){ans[++tot]=now;return;}
	if(ed>prime[st]&&Check(ed-1)) ans[++tot]=now*(ed-1);
	for(int i=st;prime[i]*prime[i]<=ed;i++){
		ll t=prime[i],sum=prime[i]+1;
		for(;sum<=ed;t*=prime[i],sum+=t) if(ed%sum==0) Dfs(i+1,ed/sum,now*t);
	}
	return ;
}
int main(){
	Init();
	while(scanf("%d",&S)==1){
		tot=0;Dfs(1,S,1);
		print(tot);puts("");
		sort(ans+1,ans+1+tot);
		for(int i=1;i<=tot;i++) print(ans[i]),putchar(' ');
		if(tot) puts("");
	}
	return 0;
}
