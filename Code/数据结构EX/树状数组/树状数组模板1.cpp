#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,c[N],a[N],nn;
int read(){
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*t;
}
int ask(int x){
	int ans=0;
	for(;x;x-=(x&(-x))) ans+=c[x];
	return ans;
}
void add(int x,int y){
	for(;x<=n;x+=(x&(-x))) c[x]+=y;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		add(i,a[i]);
	}
	while(m--){
		int op,xx,yy;
		op=read(),xx=read(),yy=read();
		if(op==1) add(xx,yy);
		else cout<<ask(yy)-ask(xx-1)<<endl;
	}
    return 0;
} 
