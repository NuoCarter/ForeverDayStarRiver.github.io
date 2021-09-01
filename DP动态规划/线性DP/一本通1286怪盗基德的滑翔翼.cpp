#include<bits/stdc++.h>
using namespace std;
int a[1005];
int f[1005];
int f2[1005];
int maxn;
int main(){
	int many;
	int n;
	scanf("%d",&many);
	for(int o=1;o<=many;o++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			f[i]=1;
			for(int j=1;j<i;j++){
				if(a[i]<a[j]){
					if(f[i]<f[j]+1){
						f[i]=f[j]+1;;
					}
				}
			}
		}
		for(int i=n;i>=1;i--){
			f2[i]=1;
			for(int j=n;j>i;j--){
				if(a[i]<a[j]){
					if(f2[i]<f2[j]+1){
						f2[i]=f2[j]+1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			maxn=max(max(maxn,f[i]),f2[i]);
		}
		cout<<maxn<<endl;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(f2,0,sizeof(f2));
		maxn=0;
	}
	return 0;
}
