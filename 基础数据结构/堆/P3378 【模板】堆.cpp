#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int tep;
    scanf("%d",&tep);
    if(tep==1){
      int x;
      scanf("%d",&x);
      q.push(x);
    }
    else if(tep==2) printf("%d\n",q.top());
    else q.pop();
  }
  return 0;
}
