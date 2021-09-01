//f[x][t]表示以x为根得子树选t个最高学分
#include<bits/stdc++.h>
using namespace std;
vector<int> son[305];
int f[305][305];
int a[305];
int n,m;
bool vis[305];
void dp(int x){
  f[x][0]=0;
  int tep=son[x].size();
  for(int i=0;i<tep;i++){
    int y=son[x][i];
    dp(y);
    for(int t=m;t>=0;t--){
      for(int j=t;j>=0;j--){
        if(t-j>=0)  f[x][t]=max(f[x][t],f[x][t-j]+f[y][j]);
      }
    }
  }
  if(x!=0){
    for(int t=m;t>0;t--){
      f[x][t]=f[x][t-1]+a[x];
    }
  }
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    int fa;
    scanf("%d%d",&fa,&a[i]);
    son[fa].push_back(i);
  }
  dp(0);
  printf("%d\n",f[0][m]);
  return 0;
}
