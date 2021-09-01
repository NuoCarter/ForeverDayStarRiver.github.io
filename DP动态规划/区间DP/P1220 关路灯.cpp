#include<bits/stdc++.h>
using namespace std;
int n,loc1;
int a[55];
int loc[55];
int f[55][55][2];
int s[55];
int main(){
  scanf("%d%d",&n,&loc1);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&loc[i],&a[i]);
    s[i]=a[i]+s[i-1];
  }
  memset(f,0x3f3f3f3f,sizeof(f));
  f[loc1][loc1][0]=0;
  f[loc1][loc1][1]=0;
  for(int len=2;len<=n;len++){
    for(int i=1;i<=n-len+1;i++){
      int j=i+len-1;
      f[i][j][0]=min(f[i+1][j][0]+(loc[i+1]-loc[i])*(s[i]+s[n]-s[j]),f[i+1][j][1]+(loc[j]-loc[i])*(s[i]+s[n]-s[j]));
      f[i][j][1]=min(f[i][j-1][0]+(loc[j]-loc[i])*(s[i-1]+s[n]-s[j-1]),f[i][j-1][1]+(loc[j]-loc[j-1])*(s[i-1]+s[n]-s[j-1]));
    }
  }
  printf("%d\n",min(f[1][n][0],f[1][n][1]));
  return 0;
}
