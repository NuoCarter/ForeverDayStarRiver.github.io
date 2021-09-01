#include<bits/stdc++.h>
using namespace std;
int size[35],f[20005];
int v,n;
int main(){
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&size[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=v;j>=size[i];j--){
			f[j]=max(f[j],f[j-size[i]]+size[i]);
		}
	}
	cout<<v-f[v];
	return 0;
}
