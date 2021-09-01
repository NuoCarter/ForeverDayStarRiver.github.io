#include<bits/stdc++.h>
using namespace std;
int a[105][105],f[105][105],n;
int dp[105];
int mx;

void judg(int x){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i]=max(f[x][i],dp[i-1]+f[x][i]);
        mx=max(mx,dp[i]);
    }
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			for(int o=1;o<=n;o++){
				  f[j][o]=a[j][o]+f[j-1][o];//j所在列的和
			}
			judg(j);//找出最大子序列
		}

	}
	cout<<mx<<endl;
	return 0;
} 
