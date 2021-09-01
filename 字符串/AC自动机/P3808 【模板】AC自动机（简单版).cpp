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
const int N=1e6+3;
struct ACAM{
    int ch[N][26],fail[N],end[N],tot,root;
    // #define ch(x)(i)    ch[x][i]
    // #define fail(x) fail[x]
    // #define end(x)  end[x]
    inline void Mem(){
        memset(ch,0,sizeof(ch));memset(fail,0,sizeof(fail)),memset(end,0,sizeof(end));
        tot=root=0;
        return;
    }
    inline void Insert(char *str){
        int p=0,len=strlen(str);
        for(register int i=0;i<len;++i){
            int c=str[i]-'a';
            if(!ch[p][c])   ch[p][c]=++tot;
            p=ch[p][c];
        }
        end[p]++;return;
    }
    inline void Getfail(){
        queue<int> q;
        for(register int i=0;i<26;++i)
            if(ch[root][i])
                fail[ch[root][i]]=root,
                q.push(ch[root][i]);

        while(!q.empty()){
            int x=q.front();q.pop();
            for(register int i=0;i<26;++i){
                if(ch[x][i])    fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
                else ch[x][i]=ch[fail[x]][i];
            }
        }
        return;
    }
    inline int Query(char *str){
        int len=strlen(str),p=0,res=0;
        for(register int i=0;i<len;++i){
            p=ch[p][str[i]-'a'];
            for(register int k=p;k&&end[k]!=-1;k=fail[k])    res+=end[k],end[k]=-1;
        }
        return res;
    }
}T;
int n;
char str[N],ptr[N];
int main(){
    read(n);
    for(register int i=1;i<=n;++i){
        scanf("%s",str);
        T.Insert(str);
    }
    scanf("%s",ptr);
    T.Getfail();
    print(T.Query(ptr));

    return 0;
}
