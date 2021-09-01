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
const int N=2e6+3,M=2e5+3;
int n,cnt[M];
struct ACAM{
    int ch[N][27],fail[N],tag[N],rev[N],tot,root;
    int head[N],to[N],Next[N],cnt;
    inline void Addedge(int u,int v){
        to[++cnt]=v,Next[cnt]=head[u],head[u]=cnt;
        return;
    }
    inline void Mem(){
        memset(ch,0,sizeof(ch));memset(fail,0,sizeof(fail)),memset(tag,0,sizeof(tag));
        tot=root=0;
        return;
    }
    inline void Insert(string str,int pos){
        int p=0,len=str.size();
        for(register int i=0;i<len;++i){
            int c=str[i]-'a';
            if(!ch[p][c])   ch[p][c]=++tot;
            p=ch[p][c];
        }
        rev[pos]=p;return;
    }
    inline void Getfail(){
        queue<int> q;
        for(register int i=0;i<27;++i)
            if(ch[root][i])
                fail[ch[root][i]]=root,
                q.push(ch[root][i]);

        while(!q.empty()){
            int x=q.front();q.pop();
            for(register int i=0;i<27;++i){
                if(ch[x][i])    fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
                else ch[x][i]=ch[fail[x]][i];
            }
        }
        for(register int i=1;i<=tot;++i)    Addedge(fail[i],i);
        return;
    }
    inline void Query(string str){
        int len=str.size(),p=0;
        for(register int i=0;i<len;++i){
            p=ch[p][str[i]-'a'];
            tag[p]++;
        }
        return;
    }
    inline void Dfs(int u){
        for(register int i=head[u];i;i=Next[i]){
            int y=to[i];
            Dfs(y);
            tag[u]+=tag[y];
        }
        return;
    }
}T;
string str,ptr;
int main(){
    read(n);
    for(register int i=1;i<=n;++i){
        cin>>str;
        T.Insert(str,i);
        ptr=ptr+'{'+str;
    }
    T.Getfail();
    T.Query(ptr);
    T.Dfs(T.root);
    for(register int i=1;i<=n;++i)  print(T.tag[T.rev[i]]),putchar('\n');
    return 0;
}
