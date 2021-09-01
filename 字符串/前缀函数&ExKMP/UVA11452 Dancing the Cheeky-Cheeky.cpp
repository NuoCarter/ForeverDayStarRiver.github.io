#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int T;
char s[N];
int pi[N];
int main(){
    read(T);
    while(T--){
        scanf("%s",s);
        int siz=strlen(s);pi[0]=0;
        for(register int i=1;i<siz;++i){
            int j=pi[i-1];
            while(j&&s[j]!=s[i])    j=pi[j-1];
            if(s[j]==s[i])  ++j;pi[i]=j;
        }
        int len=siz-pi[siz-1];
        int st=siz%len;
        for(register int i=0;i<8;++i)    cout<<s[(st+i+len)%len];
        puts("...");
    }
    return 0;
}
