#include<bits/stdc++.h>
using namespace std;
int q1[1000005];
int q2[1000005];
int n,m;
int a[1000005];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
  int l=1,r=0;
  for(int i=1;i<=n;i++){
    while(l<=r&&q1[l]+m<i) l++;
    while(l<=r&&a[i]<a[q1[r]])  r--;
    q1[++r]=i;
    if(i>=m)  printf("%d ",a[q1[l]]);
  }
  printf("\n");
  l=1;
  r=0;
  for(int i=1;i<=n;++i){
    while(l<=r&&q2[l]+m<i) l++;
    while(l<=r&&a[i]>a[q2[r]]) r--;
    q2[++r]=i;
    if(i>=m)  printf("%d ",a[q2[l]]);
  }
  return 0;
}
