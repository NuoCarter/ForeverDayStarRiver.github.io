#include<bits/stdc++.h>
using namespace std;
int w[35],c[35],f[205][205];
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&c[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(w[i]<=j){
				f[i][j]=f[i][j-w[i]]+c[i];
			}
			f[i][j]=max(f[i-1][j],f[i][j]);
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			maxn=max(maxn,f[i][j]);
		}
	}
	cout<<"max="<<maxn;
	return 0;
}
