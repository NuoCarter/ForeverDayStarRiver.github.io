#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,M=1e5+5,loglen=20;
const ll mod=1e9+7;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
  while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}
int n,m,fa[N][loglen];
int l1,r1,l2,r2;
inline int get(int x,int k){return fa[x][k]==x ? x : fa[x][k]=get(fa[x][k],k);}
inline void merge(int x,int y,int k){fa[get(x,k)][k]=get(y,k);}
inline ll quick_pow(ll x,int p){
  ll res=1;
  while(p){
    if(p&1) res=(res*x)%mod;
    x=(x*x)%mod;
    p>>=1;
  }
  return res;
}
int main(){
  n=read(),m=read();
  for(int i=1;i<=n;++i){for(int j=0;j<=loglen;++j){fa[i][j]=i;}}
  while(m--){
    l1=read(),r1=read(),l2=read(),r2=read();
    int st=loglen;
    while(st>=0){
      if(l1+(1<<st)-1<=r1){
        merge(l1,l2,st);
        l1+=(1<<st),l2+=(1<<st);
      }
      st--;
    }
  }
  //cout<<"?"<<endl;
  for(int i=loglen;i>=1;--i){
    for(int j=1;j<=n;++j){
      if(j+(1<<i)-1>n){break;}
      int tep=get(j,i);
      merge(j,tep,i-1),merge(j+(1<<(i-1)),tep+(1<<(i-1)),i-1);
    }
  }
  int ans=0;
  //cout<<"?"<<endl;
  for(int i=1;i<=n;++i){if(fa[i][0]==i){ans++;}}
  printf("%lld\n",(9*quick_pow(10,ans-1))%mod);
  return 0;
}
