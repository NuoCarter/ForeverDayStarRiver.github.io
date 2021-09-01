#include<bits/stdc++.h>
using namespace std;
string o,p;
char a[1005],b[1005];
int f[1005][1005];
int main(){
	cin>>o>>p;
	if(o.size()<p.size()){
		swap(o,p);
	}
	for(int i=1;i<=o.size();i++){
		a[i]=o[i-1];
	}
	for(int i=1;i<=p.size();i++){
		b[i]=p[i-1];
	}
	for(int i=1;i<=o.size();i++){
		for(int j=1;j<=p.size();j++){
			if(a[i]==b[j]){
				if(f[i][j]<f[i-1][j-1]+1){
					f[i][j]=f[i-1][j-1]+1;
				}
			}
			else{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=o.size();i++){
		for(int j=1;j<=p.size();j++){
			maxn=max(f[i][j],maxn);
		}

	}
	cout<<maxn;
	return 0;
}
