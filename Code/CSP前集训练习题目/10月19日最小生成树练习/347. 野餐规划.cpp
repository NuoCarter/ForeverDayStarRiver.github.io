#include<bits/stdc++.h>
using namespace std;
const int M=1e3+5,N=25;
map<string,int> name;
int k,m,n;
struct edge{
  int u,v,w;
  friend bool operator < (const edge &x,const edge &y){return x.w<y.w;}
}e[M];
int con[M][M];bool hav[M][M];
int siz,cntname=1,ans;
inline void add_pa(int u,int v,int w){e[++siz].u=u;e[siz].v=v,e[siz].w=w;}
int fa[M];
inline int get(int x){return x==fa[x] ? x : fa[x]=get(fa[x]);}
inline void merge(int x,int y){fa[get(x)]=get(y);}
inline void kruskal(){
  sort(e+1,e+siz+1);
  for(int i=1;i<=cntname;++i){fa[i]=i;}
  for(int i=1;i<=siz;++i){
    int x=e[i].u,y=e[i].v,w=e[i].w;
    int fx=get(x),fy=get(y);
    if(fx==1||fy==1)  continue;
    if(fx==fy)  continue;
    fa[fx]=fy,ans+=w;hav[x][y]=hav[y][x]=true;
  }
}
struct node{
  int l,r,w;
}dp[M];
int minn[M],numminn[M],num;
inline void dfs(int dep, int pre) {
    for (int i = 2;i<=m;++i) {
      if (i == pre||!hav[dep][i]) continue;
      if (dp[i].w==-1){
        if (dp[dep].w>con[dep][i]) dp[i]=dp[dep];
        else dp[i].l=dep,dp[i].r=i,dp[i].w= con[dep][i];
      }
      dfs(i, dep);
    }
}

int main(){
  memset(con,0x3f3f3f3f,sizeof(con));
  memset(minn,0x3f3f3f3f,sizeof(minn));
  scanf("%d",&m);
  name["Park"]=1;
  for(int i=1,w;i<=m;++i){
    string s1,s2;
    cin>>s1>>s2>>w;
    if(!name[s1]){name[s1]=++cntname;}
    if(!name[s2]){name[s2]=++cntname;}
    int tep1=name[s1],tep2=name[s2];
    add_pa(tep1,tep2,w);
    con[tep1][tep2]=con[tep2][tep1]=min(w,con[tep1][tep2]);
  }
  scanf("%d",&k);
  kruskal();
  for(int i=2;i<=cntname;++i){
    if(con[1][i]!=0x3f3f3f3f){
      int tep=get(i);
      if(minn[tep]>con[1][i]){minn[tep]=con[1][i];numminn[tep]=i;}
    }
  }
  for(int i=2;i<=cntname;++i)
    if(minn[i]!=0x3f3f3f3f){
      ++num;
      hav[1][numminn[i]] = hav[numminn[i]][1] = 1;
      ans+=con[1][numminn[i]];
    }
  for (int i = num + 1; i <= k; ++ i) {
      memset(dp, -1, sizeof(dp));
      dp[1].w = -0x3f3f3f3f;
      for (int j = 2; j <= m; ++ j)
        if (hav[1][j]) dp[j].w = -0x3f3f3f3f;
      dfs(1, -1);
      int point,minpoint = 0x3f3f3f3f;
      for (int j = 2; j <= m; ++ j)
        if (minpoint > con[1][j] - dp[j].w) minpoint = con[1][j] - dp[j].w, point = j;
      if (minpoint >= 0) break;
      hav[1][point] = hav[point][1] = 1;
      hav[dp[point].l][dp[point].r] = hav[dp[point].r][dp[point].l] = false;
      ans += minpoint;
    }
  printf("Total miles driven: %d\n",ans);
  return 0;
}
