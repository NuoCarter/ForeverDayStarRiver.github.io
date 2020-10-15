#include<bits/stdc++.h>
using namespace std;
int tree[2000005];
int n;
int m;
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int k){while(x<=n){tree[x]+=k;x+=lowbit(x);}return;}
inline int search(int x){int ans=0;while(x>0){ans+=tree[x];x-=lowbit(x);}return ans;}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    int tep;
    scanf("%d",&tep);
    add(i,tep);
  }
  for(int i=1;i<=m;i++){
    int op;
    scanf("%d",&op);
    if(op==1){int x,k;scanf("%d%d",&x,&k);add(x,k);}
    else{int x,y;scanf("%d%d",&x,&y);printf("%d\n",search(y)-search(x-1));}
  }
  return 0;
}
