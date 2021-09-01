#include<vector>
#include<cstdio>
using namespace std;
vector<vector<int> > f(100005);
int n,m,q;
int s,e;
bool flag;
bool ju;
int leng;
bool ha[100005];
void bfs(int x,int l,int step){
  if(l<0){
    return 0;
  }
  if(x==1){
    leng=step;
    return step;
  }
  for(int i=0;i<f.size();i++){
    bfs(f[x][i],l-1,step)
  }
}
int main(){
  scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&s,&e);
    f[s].push_back(e);
    if(s==1||e==1){
      flag=true;
    }
  }
  int len=0;
  for(int i=1;i<=q;i++){
    scanf("%d",&len);
    if(!flag){
      printf("No\n");
    }
    else{

    }
  }
  return 0;
}
