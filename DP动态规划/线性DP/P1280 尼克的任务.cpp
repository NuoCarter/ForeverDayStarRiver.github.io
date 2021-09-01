#include<bits/stdc++.h>
using namespace std;
int n,k;
struct activity{
  int st,t;
}a[10005];
int tep=1;
int ha[10005];
int sum[10005];
int f[10005];
inline bool cmp(activity x,activity y){
  return x.st>y.st;
}
int main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<=k;i++){
    int t;
    scanf("%d%d",&a[i].st,&a[i].t);
    ha[a[i].st]=t;
    sum[a[i].st]++;
  }
  sort(a+1,a+k+1,cmp);
  for(int i=n;i>=1;--i){
    if(!ha[i]){f[i]=f[i+1]+1;}
    else{
      for(int j=1;j<=sum[i];++j){
        if(f[i+a[tep].t]>f[i]){
          f[i]=f[i+a[tep].t];
        }
        tep++;
      }
    }
  }
  printf("%d\n",f[1]);
  return 0;
}
