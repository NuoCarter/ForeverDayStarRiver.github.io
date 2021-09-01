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
const int N=1e5+3;
int tot=1,m,root=1;
string st;
int ch[N][27],fail[N],rev[N],head[N],Next[N],to[N],cnt,fa[N];
int Ch[N][27];
int c[N];
inline void Addedge(int u,int v){
    Next[++cnt]=head[u],to[cnt]=v,head[u]=cnt;
}
inline void Getfail(){
    queue<int> q;
    for(register int i=0;i<26;++i)
        if(ch[root][i]) fail[ch[root][i]]=root,q.push(ch[root][i]);
    for(register int i=0;i<26;++i){
        if(!ch[root][i]) ch[root][i]=1;
    }
    while(!q.empty()){
       int x=q.front();q.pop();
       for(register int i=0;i<26;++i){
           if(ch[x][i])    fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
           else ch[x][i]=ch[fail[x]][i];
       }
    }
    for(register int i=2;i<=tot;++i){
        // cout<<fail[i]<<" "<<i<<endl;
        Addedge(fail[i],i);
    }
    return;
}
#define lowbit(x)   x&(-x)
int ldfn[N],rdfn[N],dnt;
inline void Dfs(int x){
    ldfn[x]=++dnt;
    for(register int i=head[x];i;i=Next[i]) Dfs(to[i]);
    rdfn[x]=dnt;
}
inline void Add(int x,int d){
    if(!x)  return;
    for(register int i=x;i<=tot;i+=lowbit(i))   c[i]+=d;
    return;
}
inline int Query(int x){
    int res=0;for(register int i=x;i>0;i-=lowbit(i))    res+=c[i];
    return res;
}
struct Que{
    int x,y;
}que[N];
int ans[N];
vector<int> myq[N];
inline void Solve(int x){
    Add(ldfn[x],1);
    // cout<<x<<endl;
    for(register unsigned int i=0;i<myq[x].size();++i){
        int tx=que[myq[x][i]].x;
        ans[myq[x][i]]=Query(rdfn[rev[tx]])-Query(ldfn[rev[tx]]-1);
    }
    for(register int i=0;i<26;++i){
        // if(ch[x][i])    cout<<x<<" "<<i<<" "<<ch[x][i]<<"!!!!\n";
        if(Ch[x][i])    Solve(Ch[x][i]);
    }
    Add(ldfn[x],-1);return;
}
int main(){
    cin>>st;int siz=st.size();int r=0,cur=root;
    fa[root]=root;
    for(register int i=0;i<siz;++i){
        if(st[i]>='a'&&st[i]<='z'){
            int c=st[i]-'a';
            if(!ch[cur][c]) ch[cur][c]=++tot,fa[tot]=cur;
            cur=ch[cur][c];
        }
        else if(st[i]=='B') cur=fa[cur];
        else if(st[i]=='P') rev[++r]=cur;
    }
    memcpy(Ch,ch,sizeof(ch));
    // puts("???");
    // cout<<tot<<endl;
    // for(register int i=1;i<=tot;++i){
    //     for(register int j=0;j<26;++j){
    //         if(ch[i][j])    printf("%d %d\n",i,j);
    //         // puts("????");
    //     }
    // }
    // puts("????");
    Getfail();Dfs(root);
    // puts("??!!!!!");
    // for(register int i=1;i<=tot;++i){
    //     for(register int j=head[i];j;j=Next[j]){
    //         cout<<i<<" "<<j<<endl;
    //     }
    // }
    // puts("??!!!!!");
    // cout<<tot<<endl;
    // for(register int i=1;i<=r;++i){
    //     cout<<rev[i]<<"rear\n";
    // }
    // for(register int i=1;i<=tot;++i)    cout<<ldfn[i]<<" "<<rdfn[i]<<endl;
    read(m);
    for(register int i=1;i<=m;++i){
        read(que[i].x),read(que[i].y);
        myq[rev[que[i].y]].push_back(i);
    }
    Solve(root);
    // puts("???");
    for(register int i=1;i<=m;++i)  print(ans[i]),putchar('\n');
    return 0;
}
