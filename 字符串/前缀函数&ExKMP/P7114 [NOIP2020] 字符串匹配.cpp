#include<bits/stdc++.h>
using namespace std;
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
const int N=2e6+3;
int T,z[N];
inline void Z_function(char *s){
    int len=strlen(s);
    z[0]=0;
    for(register int i=1;i<len;++i){
    	if(i<=r&&z[i-l]<r-i+1)	z[i]=z[i-l];
    	else{
    		z[i]=max(0,r-i+1);
    		while(i+z[i]-1<len&&s[z[i]]==s[i+z[i]])	z[i]++;
    		if(r>i+z[i]-1)	l=r,r=i+z[i]-1;
    	}
    }
    return;
}
char s[N];
int main(){
    read(T);
    while(T--){
        scanf("%s",s);Z_function(s);
        int len=strlen(s);
        for(register int i=0;i<len;++i){

        }
    }
    return 0;
}
