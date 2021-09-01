#include<bits/stdc++.h>
  using namespace std;
  int a[105];
  int f[105][105];
  int n;
  int s[105];
  int main(){
    scanf("%d",&n);
    memset(f,0x3f3f3f3f,sizeof(f));
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      f[i][i]=0;
      s[i]=s[i-1]+a[i];
    }
    for(int i=n-1;i>=1;i--){
      for(int j=i+1;j<=n;j++){
        for(int k=i;k<j;k++){
          f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
      }
    }
    printf("%d\n",f[1][n]);
    return 0;
}
