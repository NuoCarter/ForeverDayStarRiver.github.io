#include<bits/stdc++.h>
using namespace std;
int v[5005],w[5005],f[6000][6000];
int n,m;int o=1;
int v2,w2;
void mybreak(int s,int v2,int w2){
	int temp=1;
	while(s>temp){
		v[o]=temp*v2;
		w[o]=temp*w2;
		s-=temp;
		temp*=2;
		o++;
	}
	v[o]=s*v2;
	w[o]=s*w2;
	o++;
}
int main(){
	cin>>n>>m;
	int many;
	for(int i=1;i<=n;i++){
		cin>>v2>>w2>>many;
		mybreak(many,v2,w2);

	}
	o--;
	for(int i=1;i<=o;i++){
		for(int j=1;j<=m;j++){
			if(v[i]<=j){
				f[i][j]=f[i-1][j-v[i]]+w[i];
			}
			f[i][j]=max(f[i][j],f[i-1][j]);
		}
	}
	int maxn=0;
	for(int i=1;i<=o;i++){
		for(int j=1;j<=m;j++){
			maxn=max(maxn,f[i][j]);
		}
	}
	cout<<maxn;
	return 0;
} 
