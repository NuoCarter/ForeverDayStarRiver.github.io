#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
long long n,a[100005],f[100005],m;
int main(){
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
  f[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=m;j>=1;j--){
      f[j]=(f[j]+f[j-1]*a[i])%MOD;
    }
  }
  printf("%lld\n",f[m]);
  return 0;
}
