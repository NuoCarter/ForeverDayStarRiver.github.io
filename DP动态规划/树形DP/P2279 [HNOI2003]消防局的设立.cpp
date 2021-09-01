#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=0x3f3f3f3f;
int f[N][5],head[N],Next[N<<1],to[N<<1],tot,in[N],n;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
  return x*f;
}
inline void add(int u,int v){to[++tot]=v;Next[tot]=head[u];head[u]=tot;in[v]++;}
inline void dfs(int x,int fa){
  for(int i=head[x];i;i=Next[i]){
    int y=to[i];
    if(y==fa) continue;
    dfs(y,x);
    f[x][1]=1+min(f[y][2],min(f[y][3],min(f[y][4],f[y][5])))
    f[x][2]=min(f[y][0]+1)
  }
  else{
    f[x][1]=f[x][2]=INF;
		for(int i=head[x];i;i=Next[i]){
			int y=to[i];
			int f1 = f[y][0];
			int f2 = f[y][1];
			for(int j=head[y];j;j=Next[i]){
				if(i==j) continue;
				int tep=to[j];
				f2+=f[tep][3];
				f2+=f[tep][2];
			}
			f[x][1] = min(f[x][1],f1);
			f[x][2] = min(f[x][2],f2);
		}
  }
  for(int i=1;i<=4;i++){f[x][i]=min(f[x][i],f[x][i-1]);}
  return ;
}
int main(){
  n=read();
  for(int i=1,v;i<n;++i){v=read();add(i,v),add(v,i);}
  dfs(1,0);
  printf("%d\n",f[1][2]);
  return 0;
}
