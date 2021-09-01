#include<bits/stdc++.h>
using namespace std;
int n;
int dp[6005][5];
int a[6005];
vector<int> v[6005];
bool vis[6006];
int rorder;
int maxn;
void dfs(int i){
  dp[i][0]=0;
  dp[i][1]=a[i];
  int tep=v[i].size();
  for(int j=0;j<tep;j++){
    int tem=v[i][j];
    dfs(tem);
    dp[i][0]+=max(dp[tem][0],dp[tem][1]);
    dp[i][1]+=dp[tem][0];
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++){
    int tep1,tep2;
    scanf("%d%d",&tep1,&tep2);
    if(tep1==0&&tep2==0)  break;
    else  v[tep2].push_back(tep1);
    vis[tep1]=true;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      rorder=i;
      break;
    }
  }
  dfs(rorder);
  maxn=max(dp[rorder][0],dp[rorder][1]);
  printf("%d\n",maxn);
  return 0;
}
