#include<bits/stdc++.h>
using namespace std;
int p[105],t[105],f[1005][1005];//p为价值，t为时间
int main(){
	int time,m;
	scanf("%d%d",&time,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&t[i],&p[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=time;j++){
			if(t[i]<=j){
				f[i][j]=f[i-1][j-t[i]]+p[i];
			}
			f[i][j]=max(f[i][j],f[i-1][j]);
		}
	}
	cout<<f[m][time];
	return 0;
}
