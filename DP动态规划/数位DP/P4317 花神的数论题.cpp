#include<bits/stdc++.h>
using namespace std;
#define mod 1e7+7
int f[60][2][60];
long long n;
int len=1;
int a[55];
long long dp(int i,int less,long long sum){
  long long ans=0;
  if(i<=0) return max(1,sum);
  if(!less&&f[i][less][sum]!=-1)  return f[i][less][sum];
  int limit=limit ? a[i]:1;
  for(int j=0;j<=limit;j++){
    if(less){f[i][less][sum]*=dp(i-1,less,sum+j);}
    el
  }
}
int main(){
  scanf("%lld",&n);
  while(n>0){
    a[len]=n&1;
    n>>=1;
    len++;
  }
  memset(f,-1,sizeof(f));
  len--;
  return 0;
}
