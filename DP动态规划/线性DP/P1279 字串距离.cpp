#include<bits/stdc++.h>
using namespace std;
const int N=2e3+3;
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
int dp[N][N],k;
char s1[N],s2[N];
int main(){
    scanf("%s",s1+1),scanf("%s",s2+1);
    read(k);
    int len1=strlen(s1+1),len2=strlen(s2+1);

    for(register int i=1;i<=max(len1,len2);++i){dp[i][0]=dp[0][i]=i*k;}

    for(register int i=1;i<=len1;++i){
        for(register int j=1;j<=len2;++j){
            dp[i][j]=min(dp[i-1][j]+k,min(dp[i][j-1]+k,dp[i-1][j-1]+abs(s1[i]-s2[j])));
        }
    }
    print(dp[len1][len2]);
    return 0;
}
