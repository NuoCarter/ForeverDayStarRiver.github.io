#include<bits/stdc++.h>
using namespace std;
template  <typename T>
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
int x[5],y[5],ans=10000,tot,rx[5],ry[5];
bool vis[5],c[1005];
inline void Update(int x,int y){
	if(x*y<ans){ans=x*y;memset(c,0,sizeof(c));}
	if(x*y==ans) c[x]=c[y]=1;
    return;
}
inline void check(){
	int x,y;
	x=rx[1]+rx[2]+rx[3]+rx[4];
	y=max(max(ry[1],ry[2]),max(ry[3],ry[4]));
	Update(x,y);
	x=max(rx[1]+rx[2]+rx[3],rx[4]);
	y=max(ry[1],max(ry[2],ry[3]))+ry[4];
	Update(x,y);
	x=max(rx[1]+rx[2],rx[3])+rx[4];
	y=max(max(ry[1],ry[2])+ry[3],ry[4]);
	Update(x,y);
	x=rx[1]+max(rx[2],rx[3])+rx[4];
	y=max(ry[1],max(ry[2]+ry[3],ry[4]));
	Update(x,y);
	y=max(ry[1]+ry[3],ry[2]+ry[4]);
	if(ry[1]+ry[3]<=ry[4])	x=max(rx[2],max(rx[1],rx[3])+rx[4]);
	else if(ry[3]<=ry[4]&&ry[1]+ry[3]>=ry[4]) x=max(rx[1]+rx[2],max(rx[1],rx[3])+rx[4]);
		 else if(ry[3]>=ry[4]&&ry[3]<=ry[2]+ry[4]) x=max(rx[1]+rx[2],max(rx[2],rx[4])+rx[3]);
			  else if(ry[3]>=ry[2]+ry[4]) x=max(rx[1],max(rx[2],rx[4])+rx[3]);
	Update(x,y);
}
inline void dfs(int cnt){
	if(cnt==4){check();return ;}
	for(int i=1;i<5;i++)
		if(!vis[i]){
			rx[cnt+1]=x[i],ry[cnt+1]=y[i],vis[i]=1;
			dfs(cnt+1);
			rx[cnt+1]=y[i],ry[cnt+1]=x[i];
			dfs(cnt+1);
			vis[i]=rx[cnt+1]=ry[cnt+1]=0;
		}
}

int main(){
	for(int i=1;i<5;i++) read(x[i]),read(y[i]);
	dfs(0);
    print(ans),putchar('\n');
    for(int i=1;i<=sqrt(ans);i++)
        if(c[i]) print(i),putchar(' '),print(ans/i),putchar('\n');
	return 0;
}
