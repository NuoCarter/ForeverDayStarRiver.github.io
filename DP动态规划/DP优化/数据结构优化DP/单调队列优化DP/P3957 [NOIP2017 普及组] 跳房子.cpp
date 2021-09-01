#include<bits/stdc++.h>
using namespace std;

const int INF=2147483647,N=500005;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}

int n,d,k,l,r,mid,edge;

int x[N],s[N],f[N],q[N],pos[N],dq[N];

inline bool check(int g) {
	int bot=max(d-g,1),len=d+g;
	for(int i=1;i<=n;i++) f[i]=-INF;
	int h=1,t=0,hh=1,tt=0;
	dq[++tt]=0;
	for(int i=1;i<=n;i++) {
		while(x[i]-x[dq[hh]]>len&&hh<=tt) hh++;
		while(x[i]-x[dq[hh]]>=bot&&x[i]-x[dq[hh]]<=len&&hh<=tt) {
			while(f[dq[hh]]>=q[t]&&h<=t) t--;
			q[++t]=f[dq[hh]];pos[t]=dq[hh];hh++;
		}
		while(x[i]-x[pos[h]]>len&&h<=t) h++;
		if(h<=t){
            dq[++tt]=i;
            f[i]=max(f[i],q[h]+s[i]);
            if(f[i]>=k) return true;
        }
	}
	return false;
}
int main(){
    read(n),read(d),read(k);
    for(register int i=1;i<=n;++i) read(x[i]),read(s[i]);
	r=x[n]+1;edge=r;
	while(l<r) {
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}

	if(l<edge) print(l);
	else printf("-1");

	return 0;
}
