#include<bits/stdc++.h>
#define N 300010
using namespace std;
int n,m,i,D;long long ans;
template < typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return ;
}
namespace task1{
    int a[N],i,j;
    inline void Solve(){
        for(i=1;i<=n;i++)read(a[i]);
        sort(a+1,a+n+1);
        for(i=j=1;i<=n;ans+=i-j,i++)while(a[i]-a[j]>D)j++;
        return;
    }
}
namespace task2{
    int m,k,i,x,y,z,c[N],q[N],X,Y,b[N];
    struct P{int x,y,z,t;P(){}P(int _x,int _y,int _z,int _t){x=_x,y=_y,z=_z,t=_t;}}a[N];
    inline bool Cmp(const P&a,const P&b){return a.x==b.x?a.t<b.t:a.x<b.x;}
    inline int Get(int x){
        int l=1,r=m,t,mid;
        while(l<=r){
            int mid=(l+r)>>1;
            if(b[mid]<=x)   l=(t=mid)+1;
            else r=mid-1;
        }
        return t;
    }
    #define lowbit(x)   x&(-x)
    inline void Add(int x,int y){for(;x<=m;x+=lowbit(x))c[x]+=y;return;}
    inline int Ask(int x){int t=0;for(;x;x-=lowbit(x))t+=c[x];return t;}
    inline void Solve(){
        for(m=0,z=D,i=1;i<=n;i++){
            read(x),read(y),X=x+y,Y=x-y;
            a[++m]=P(X,Y,0,i),b[m]=Y;
            a[++m]=P(X+z,Y-z,Y+z,n+1),b[m]=Y-z;
            a[++m]=P(X-z,Y-z,Y+z,0),b[m]=Y+z;
        }
        for(sort(a+1,a+m+1,Cmp),sort(b+1,b+m+1),i=1;i<=m;i++){
            if(a[i].t&&a[i].t<=n)ans+=Ask(Get(a[i].y));
            else{
                a[i].y=Get(a[i].y),a[i].z=Get(a[i].z)+1;
                if(a[i].t)Add(a[i].y,-1),Add(a[i].z,1);else Add(a[i].y,1),Add(a[i].z,-1);
            }
        }
        ans=(ans-n)/2;return;
    }
}
namespace task3{
    int i,j,k,x,y,z,X,Y,a[N][3],s[76][152][152];
    inline int Ask(int x,int y){return s[j][max(min(x,150),0)][max(min(y,150),0)];}
    void Solve(){
        for(i=1;i<=n;i++){
            read(x),read(y),read(z),X=y+z,Y=y-z+75;
            a[i][0]=x,a[i][1]=X,a[i][2]=Y;
            s[x][X][Y]++;
        }
        for(i=1;i<=75;i++)for(j=1;j<=150;j++)for(k=1;k<=150;k++)s[i][j][k]+=s[i][j-1][k]+s[i][j][k-1]-s[i][j-1][k-1];
        for(i=1;i<=n;i++)for(j=1;j<=75;j++)if(abs(a[i][0]-j)<=D){
            x=D-abs(a[i][0]-j);
            ans+=Ask(a[i][1]+x,a[i][2]+x)-Ask(a[i][1]-x-1,a[i][2]+x)-Ask(a[i][1]+x,a[i][2]-x-1)+Ask(a[i][1]-x-1,a[i][2]-x-1);
        }
        ans=(ans-n)/2;
    }
}
int main(){
  read(m),read(n),read(D),read(i);
  if(m==1)task1::Solve();
  if(m==2)task2::Solve();
  if(m==3)task3::Solve();
  return print(ans),0;
}
