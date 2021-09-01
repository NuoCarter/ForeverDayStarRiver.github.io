#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
string s1,s2;
int pi[N];
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;return;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);return;
}
int main(){
    // getline(cin,s1);getline(cin,s2);
    cin>>s1>>s2;
    string s=s2+'#'+s1;
    // puts("????");
    int len1=s1.size(),len2=s2.size();

    for(register int i=1;i<=len1+len2;++i){
        int j=pi[i-1];
        while(j&&s[i]!=s[j])   j=pi[j-1];
        if(s[j]==s[i])  ++j;
        pi[i]=j;
    }
    for(register int i=len2;i<=len1+len2;++i){
        if(pi[i]==len2) print(i-2*len2+1),putchar('\n');

    }
    memset(pi,0,sizeof(pi));
    // puts("");
    putchar('0'),putchar(' ');
    for(register int i=1;i<len2;++i){
        int j=pi[i-1];
        while(j&&s2[i]!=s2[j])   j=pi[j-1];
        if(s2[j]==s2[i])  ++j;
        pi[i]=j;
        print(pi[i]),putchar(' ');
    }
    return 0;
}
