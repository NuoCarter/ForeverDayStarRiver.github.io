#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+3,INF=1e18;
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
int a[N],b[N],n;
int minn[2][N];
signed main(){
    read(n);
	for(int i=1;i<=n;i++){read(a[i]);b[i]=a[i];}

    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++){
		minn[1][0]=INF;
		for(int j=1;j<=n;j++){
			int f=minn[0][j]+abs(a[i]-b[j]);
			minn[1][j]=min(minn[1][j-1],f);
		}
		for(int j=1;j<=n;j++) minn[0][j]=minn[1][j];
	}
    print(minn[1][n]);
	return 0;
}
