#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	x=0;char ch=getchar();bool f=false;
	while(!isdigit(ch)){if(ch=='-'){f=true;}ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;return ;
}
template <typename T>
inline void print(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10^48);return;
}
const int N=1e5+3,M=2e5+3;
#define lowbit(x)   x&(-x)
struct node{int a,b,c,num,ans;}S[N],Q[N];
int n,k;
inline bool Cmp1(node x,node y){
    return x.a==y.a ?  x.b==y.b  ?  x.c < y.c : x.b<y.b: x.a<y.a;
}
inline bool Cmp2(node x,node y){
    return x.b==y.b ? x.c < y.c : x.b<y.b;
}
inline bool Equal(node x,node y){
    return x.a==y.a&&x.b==y.b&&x.c==y.c;
}
int c[M];
inline void Add(int x,int v){
    for(register int i=x;i<=k;i+=lowbit(i)) c[i]+=v;
    return ;
}
inline int Query(int x){
    int res=0;for(register int i=x;i>0;i-=lowbit(i))  res+=c[i];
    return res;
}
#define debug(x)    cout<<x<<"???\n"
inline void CDQ(int l,int r){
    if(l==r)    return;
    int mid=(l+r)>>1,cnt=l;
    CDQ(l,mid),CDQ(mid+1,r);
    sort(Q+l,Q+mid+1,Cmp2),sort(Q+mid+1,Q+r+1,Cmp2);
    for(register int i=mid+1;i<=r;++i){
        while(Q[i].b>=Q[cnt].b&&cnt<=mid) Add(Q[cnt].c,Q[cnt].num),++cnt;
        Q[i].ans+=Query(Q[i].c);
    }
    for(register int i=l;i<cnt;++i) Add(Q[i].c,-Q[i].num);
    return;
}
int ans[N];
int main(){
	read(n),read(k);
    for(register int i=1;i<=n;++i)  read(S[i].a),read(S[i].b),read(S[i].c);
    sort(S+1,S+n+1,Cmp1);
    int top=0,m=0;
    for(int i=1;i<=n;i++){
		top++;
		if(!Equal(S[i],S[i+1])) m++,Q[m]=S[i],Q[m].num=top,top=0;
	}
    CDQ(1,m);
    for(register int i=1;i<=m;++i) ans[Q[i].ans+Q[i].num-1]+=Q[i].num;
    for(register int i=0;i<n;++i)   print(ans[i]),putchar('\n');
	return 0;
}
/*
10 3
3 3 3
2 3 3
2 3 1
3 1 1
3 1 2
1 3 1
1 1 2
1 2 2
1 3 2
1 2 1
*/
