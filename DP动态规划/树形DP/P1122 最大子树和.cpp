#include<bits/stdc++.h>
using namespace std;
int n;
int a[16005];
vector<int> v[16005];
bool vis[16005];
int f[16005];
int myroot;
void dfs(int i){
  int tep=v[i].size();
  for(int j=0;)
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<n;i++){
    int son,fa;
    scanf("%d%d",&son,&fa);
    v[fa].push_back(son);
    vis[son]=true;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      myroot=i;
    }
  }
  return 0;
}
