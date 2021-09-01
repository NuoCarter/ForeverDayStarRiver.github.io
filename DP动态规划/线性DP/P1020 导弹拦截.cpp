#include<bits/stdc++.h>
using namespace std;
int bigge[100005];
int a[100005];
int upp[100005];
int n=1;
int ans1=1,ans2=1;
int main(){
  while(~scanf("%d",&a[n])){
    n++;
  }
  bigge[1]=a[1];
  n--;
  upp[1]=a[1];
  for(int i=2;i<=n;i++){
    if(a[i]<=bigge[ans1]){
      ans1++;
      bigge[ans1]=a[i];
    }
    else  {
      bigge[upper_bound(bigge+1,bigge+ans1+1,a[i],greater<int>()) - bigge]=a[i];
    }
    if(a[i]>upp[ans2]){
      ans2++;
      upp[ans2]=a[i];
    }
    else{
      upp[lower_bound(upp+1,upp+ans2+1,a[i]) - upp]=a[i];
    }
  }
  printf("%d\n%d\n",ans1,ans2);
  return 0;
}
