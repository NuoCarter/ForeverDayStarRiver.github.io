#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
  x=0;char ch=getchar();bool f=false;
  while(!isdigit(ch)) f|=ch=='-',ch=getchar();
  while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
  x=f?-x:x;
}
template <typename T>
inline void print(T x){
  if(x<0 )  putchar('-'),x=-x;
  if(x>9) print(x/10);
  putchar(x%10^48);
}
int main(){


  return 0;
}
