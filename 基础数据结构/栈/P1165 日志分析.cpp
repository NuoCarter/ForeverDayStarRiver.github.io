#include<bits/stdc++.h>
using namespace std;
int n;
int tep;
int weight;
int f[200005];
int now=0;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&tep);
    if(tep==0){
      scanf("%d",&weight);
      now++;
      f[now]=max(f[now-1],weight);

    }
    else if(tep==1){
      if(now>0){
        now--;
      }
    }
    else  printf("%d\n",f[now]);
  }
  return 0;
}
