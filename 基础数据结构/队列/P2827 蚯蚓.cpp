#include<bits/stdc++.h>
using namespace std;
long long n,m,q,u,v,t,a[7500005],ans[7500005];
queue<long long> q1,q2,q3;
long long maxn1,maxn2,maxn3;
long long maxn;
long long delta;
long long tot;
bool cmp(long long x,long long y){
  return x>y;
}
int main(){
  scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t);
  for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;i++)  q1.push(a[i]);
  for(int i=1;i<=m;i++){
    if(!q1.empty()) maxn1=q1.front();
    if(!q2.empty()) maxn2=q2.front();
    if(!q3.empty()) maxn3=q3.front();
    if(maxn1>=maxn2&&maxn1>=maxn3){
      q1.pop();
      ans[i]=maxn1+delta;
    }
    else if(maxn2>=maxn3&&maxn2>=maxn1){
      q2.pop();
      ans[i]=maxn2+delta;
    }
    else{
      q3.pop();
      ans[i]=maxn3+delta;
    }
    int tep1=ans[i]*u/v,tep2=ans[i]-tep1;
    delta+=q;
    q2.push(tep1-delta);
    q3.push(tep2-delta);
    maxn1=-0x3f3f3f3f;
    maxn2=-0x3f3f3f3f;
    maxn3=-0x3f3f3f3f;
  }
  while(!q1.empty()||!q2.empty()||!q3.empty()){
    if(!q1.empty()) maxn1=q1.front();
    if(!q2.empty()) maxn2=q2.front();
    if(!q3.empty()) maxn3=q3.front();
    if(maxn1>=maxn2&&maxn1>=maxn3){
      maxn=q1.front();
      q1.pop();
    }
    else if(maxn2>=maxn3&&maxn2>=maxn1){
      maxn=q2.front();
      q2.pop();
    }
    else{
      maxn=q3.front();
      q3.pop();
    }
    a[++tot]=maxn+delta;
    maxn1=-0x3f3f3f3f;
    maxn2=-0x3f3f3f3f;
    maxn3=-0x3f3f3f3f;
  }
  for(int i=t;i<=m;i+=t)  printf("%lld ",ans[i]);
  printf("\n");
  for(int i=t;i<=tot;i+=t)  printf("%lld ",a[i]);
  return 0;
}
