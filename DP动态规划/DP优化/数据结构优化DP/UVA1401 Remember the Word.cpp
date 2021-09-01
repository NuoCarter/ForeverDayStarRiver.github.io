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
const int MOD=20071027,N=3e5+3,M=4003,LEN=103;
char s[N],st[LEN];
int ch[N][30],cnt,n,f[N];
bool ed[N];
inline int Inc(int a,int b){a+=b;return a>=MOD ? a-MOD : a;}

inline void Insert(char *str){
    int len=strlen(str),now=0;
    for(register int i=0;i<len;++i){
        int y=str[i]-'a';
        if(!ch[now][y]) ch[now][y]=++cnt;
        now=ch[now][y];
    }
    ed[now]=true;
}

inline void Search(int x,char *str){
    int now=0,len=strlen(str);
    for(register int i=0;i<len;++i){
        int y=str[i]-'a';
        if(i!=0&&!now)  return;
        if(ed[now])    f[x]=Inc(f[x],f[x+i]);
        now=ch[now][y];
    }
    if(ed[now]) f[x]=Inc(f[x],f[x+len]);
    return;
}

int main(){
    int cas=0;
    while(scanf("%s",s)!=EOF){
        cnt=0;memset(ed,false,sizeof(ed));memset(ch,0,sizeof(ch));memset(f,0,sizeof(f));
        read(n);
        for(register int i=1;i<=n;++i){
            scanf("%s",st);
            Insert(st);
        }
        // cout<<cnt<<endl;
        int len=strlen(s);f[len+1]=1;
        for(register int i=len;i>=1;--i)   Search(i,s+i-1);
        cout<<"Case "<<++cas<<": ";print(f[1]);putchar('\n');
    }
    return 0;
}
