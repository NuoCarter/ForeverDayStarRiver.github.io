#include<bits/stdc++.h>
using namespace std;
string goal;
stack<int> value;
int tep;
int main(){
  cin>>goal;
  int n=goal.size();
  for(int i=0;i<n;i++){
    if(goal[i]=='@'){
      printf("%d\n",value.top());
    }
    if(goal[i]>='0'&&goal[i]<='9'){
      int o=goal[i]-'0';
      tep=tep*10+o;
    }
    else{
      if(goal[i]=='-'){
        int v=value.top();
        value.pop();
        int v2=value.top();
        value.pop();
        v=v2-v;
        value.push(v);
      }
      else if(goal[i]=='+'){
        int v=value.top();
        value.pop();
        int v2=value.top();
        value.pop();
        v=v2+v;
        value.push(v);
      }
      else if(goal[i]=='*'){
        int v=value.top();
        value.pop();
        int v2=value.top();
        value.pop();
        v=v2*v;
        value.push(v);
      }
      else if(goal[i]=='/'){
        int v=value.top();
        value.pop();
        int v2=value.top();
        value.pop();
        v=v2/v;
        value.push(v);
      }
      else{
        value.push(tep);
        tep=0;
      }
    }
  }
  return 0;
}
