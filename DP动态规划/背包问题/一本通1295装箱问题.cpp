#include<bits/stdc++.h>
using namespace std;
int size[35],f[35][20005];
int v,n;
int main(){
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&size[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(j-size[i]>=0){
				f[i][j]=max(f[i-1][j],f[i-1][j-size[i]]+size[i]);
			}
			f[i][j]=max(f[i][j],f[i-1][j]);
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(v-f[i][j]>=0){
			maxn=max(maxn,f[i][j]);
			}
		}
	}
	cout<<v-maxn;
	return 0;
}
