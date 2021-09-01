#include<bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
int f[3000005];
int a[3000005];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=n;i>=1;--i){
    while(!s.empty()&&a[i]>=a[s.top()]) s.pop();
    if(s.empty()) f[i]=0;
    else f[i]=s.top();
    s.push(i);
  }
  for(int i=1;i<=n;i++) printf("%d ",f[i]);
  return 0;
}
