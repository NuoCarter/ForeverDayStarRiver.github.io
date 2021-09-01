#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i){
    scanf("%d",&a[i]);
  }
  int tep;
  while(m--){
    scanf("%d",&tep);
    printf("%d\n",a[tep]);
  }
  return 0;
}
