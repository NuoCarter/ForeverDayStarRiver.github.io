#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int f[10005];
int main(){
  f[0]=1;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(j<a[i]){
        f[j]=f[j-1];
      }
      else if(j==a[i]){
        f[j]+=f[j-a[i]];
      }
      else{
        f[j]=f[j-1];
      }
    }
  }
  printf("%d\n",f[m]);
  return 0;
}
