#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
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
char s1[N],s2[N];
int n,m,Next[N],f[N],g[N];
inline bool Check(int p){
    for(int j=1;j<=m;j++)    if(s1[p-j+1] != s2[m-j+1] && s1[p-j+1] != '?') return false;
    return true;
}
int main(){
    scanf("%s",s1+1),scanf("%s",s2+1);
    n = strlen(s1+1), m = strlen(s2+1);
    for(int i = 2, j = 0; i <= m; i++){
        while(j && s2[j+1]!=s2[i]) j = Next[j];
        if(s2[j+1]==s2[i])j++;
        Next[i]=j;
    }
    for(int i=1;i<=n;i++){
        f[i] = f[i-1];
        if(Check(i)){
            g[i]=f[i-m]+1;
            for(int j=Next[m];j;j=Next[j]){
                g[i]=max(g[i],g[i-(m-j)]+1);
            }
            f[i]=max(f[i],g[i]);
        }
    }
    print(f[n]);
    return 0;
}
/*
ddddd
d
*/
