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
#define lowbit(x)   x&(-x)
const int N=1e6+3;
int ch[N][26],fail[N],tot,rev[N],root;
int head[N],to[N],Next[N],cnt;
int ldfn[N],rdfn[N],now;
int c[N],siz[N],fa[N],son[N];
inline void Insert(char *str,int pos){
    int p=0,len=strlen(str);
    for(register int i=0;i<len;++i){
        int c=str[i]-'a';
        if(!ch[p][c])   ch[p][c]=++tot;
        p=ch[p][c];
    }
    rev[pos]=p;return;
}
inline void Addedge(int u,int v){
    to[++cnt]=v,Next[cnt]=head[u],head[u]=cnt;
    return;
}
inline void Getfail(){
    queue<int> q;
    for(register int i=0;i<26;++i)
        if(ch[root][i]){
            fail[ch[root][i]]=root;
            q.push(ch[root][i]);
        }

    while(!q.empty()){
        int u=q.front();q.pop();
        for(register int i=0;i<26;++i){
            if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
            else ch[u][i]=ch[fail[u]][i];
        }
    }
    for(register int i=1;i<=tot;++i)    Addedge(fail[i],i);
    return;
}

inline void Dfs1(int x,int f){
	siz[x]=1,fa[x]=f;
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		Dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]||!son[x]) son[x]=y;
	}
	return ;
}
inline void Dfs2(int x){
	ldfn[x]=++now;
	if(son[x]) Dfs2(son[x]);
	for(register int i=head[x];i;i=Next[i]){
		int y=to[i];
		if(y==son[x]) continue;
		Dfs2(y);
	}
    rdfn[x]=ldfn[x]+siz[x];
	return ;
}
inline void Add(int x,int d){
    if(!x)  return;
    for(;x<=now;x+=lowbit(x))   c[x]+=d;
    return;
}
inline int Ask(int x){
    int res=0;
    for(;x>0;x-=lowbit(x))  res+=c[x];
    return res;
}
int n,k;
char str[N],ptr[N];
bool vis[N];
int main(){
    read(n),read(k);
    for(register int i=1;i<=k;++i) scanf("%s",str),Insert(str,i);
    Getfail();
    Dfs1(0,0),Dfs2(0);
    for(register int i=1;i<=k;++i){vis[i]=true;Add(ldfn[rev[i]],1),Add(rdfn[rev[i]],-1);}
    while(n--){
        char op;int x;
        cin>>op;
        if(op=='+'){
            read(x);
            if(vis[x])  continue;
            vis[x]=true;
            Add(ldfn[rev[x]],1),Add(rdfn[rev[x]],-1);
        }
        else if(op=='-'){
            read(x);
            if(!vis[x]) continue;
            vis[x]=false;
            Add(ldfn[rev[x]],-1),Add(rdfn[rev[x]],1);
        }
        else{
            scanf("%s",ptr);
            int len=strlen(ptr),p=0,ans=0;
            for(register int i=0;i<len;++i){
                p=ch[p][ptr[i]-'a'];
                ans+=Ask(ldfn[p]);
            }
            print(ans),putchar('\n');
        }
    }
    return 0;
}
