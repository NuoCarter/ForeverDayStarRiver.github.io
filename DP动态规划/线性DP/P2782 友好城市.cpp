#include<bits/stdc++.h>
using namespace std;
struct ship{
  int south,north;
}a[200005];
int n;
int f[200005];
int ans=1;
bool cmp(ship x,ship y){
  return x.north<y.north;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&a[i].north,&a[i].south);
  }
  sort(a+1,a+n+1,cmp);
  f[ans]=a[1].south;
  for(int i=2;i<=n;i++){
    if(a[i].south>f[ans]){
      ans++;
      f[ans]=a[i].south;
    }
    else{
      f[upper_bound(f+1,f+ans+1,a[i].south)-f]=a[i].south;
    }
  }
  printf("%d\n",ans);
  return 0;
}
