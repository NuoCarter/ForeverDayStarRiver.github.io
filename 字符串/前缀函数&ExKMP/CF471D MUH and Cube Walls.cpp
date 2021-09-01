#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void prregister (T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) prregister(x/10);
    putchar(x%10^48);
}
const int  N=2e5+5;
int  n,m,a[N],b[N],kmp[N<<1],ans;
int  main(){
    read(n),read(m);
	if(m==1){prregister(n);return 0;}
    for(register int  i=1;i<=n;i++) read(a[i]);
	for(register int  i=1;i<n;i++) a[i]-=a[i+1];
	for(register int  i=1;i<=m;i++) read(b[i]);
	for(register int  i=1;i<m;i++) b[i]-=b[i+1];
	b[m]=-100009,n--;
	for(register int  i=m+1;i<=m+n;i++) b[i]=a[i-m];
    for(register int  i=2,j=0;i<=n+m;i++){
		while(j&&b[j+1]!=b[i]) j=kmp[j];
		if(b[j+1]==b[i]) j++;
		kmp[i]=j;
		if(j==m-1) ans++;
	}
	prregister(ans);
    return 0;
}
