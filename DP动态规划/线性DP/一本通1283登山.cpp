#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1005],f[1005],f2[1005];
int b[1005];
int ans[1005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	f[1]=1;
	f2[n]=1;
	for(int i=2;i<=n;i++){
		f[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]>a[j]){
				if(f[i]<f[j]+1){
					f[i]=f[j]+1;
				}
			}
		}
	}
	for(int i=n-1;i>=1;i--){
		f2[i]=1;
		for(int j=n;j>i;j--){
			if(a[i]>a[j]){
				if(f2[i]<f2[j]+1){
					f2[i]=f2[j]+1;
				}
			}
		}
	}
	int maxn=-1;
	int tep;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,f[i]+f2[i]-1);
	}
	cout<<maxn;
	return 0;
}
