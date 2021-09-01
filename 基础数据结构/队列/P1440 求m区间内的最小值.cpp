#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int q[2000005];
int l=1,r;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<=n;i++){
    printf("%d\n",a[q[l]]);
    while(q[l]<i-m+1&&l<=r) l++;
    while(l<=r&&a[q[r]]>a[i])  r--;
    r++;
    q[r]=i;
  }
  return 0;
}
