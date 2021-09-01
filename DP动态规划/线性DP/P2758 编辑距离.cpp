#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int cmp1[2005];
int cmp2[2005];
string a,b;
int main(){
  cin>>a>>b;
  if(a.size()<b.size()) swap(a,b);
  for(int i=1;i<=a.size();i++)  cmp1[i]=a[i-1]-'a';
  for(int i=1;i<=b.size();i++)  cmp2[i]=b[i-1]-'a';
  int n1=a.size();
  int n2=b.size();
  for(int i=1;i<=n1;i++){
    dp[i][0]=i;
    dp[0][i]=i;
  }
  for(int i=1;i<=n1;i++){
    for(int j=1;j<=n2;j++){
      if(cmp1[i]==cmp2[j])   dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]));
      else dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
    }
  }
  printf("%d\n",dp[n1][n2]);
  return 0;
}
