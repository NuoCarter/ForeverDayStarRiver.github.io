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
const int N=1e6+3,M=153;
struct node{
    int cnt,pos;
    string st;
    inline void Clear(){
        st="",cnt=pos=0;
    }
}sc[M];
struct ACAM{
    int ch[N][26],fail[N],end[N],tot,root;
    inline void Mem(){
        memset(ch,0,sizeof(ch));memset(fail,0,sizeof(fail)),memset(end,0,sizeof(end));
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
        end[p]=pos;return;
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
    inline void Query(string str){
        int len=str.size(),p=0;
        for(register int i=0;i<len;++i){
            p=ch[p][str[i]-'a'];
            for(register int k=p;k;k=fail[k])    sc[end[k]].cnt+=1;
        }
        return;
    }
}T;
inline bool Cmp(node x,node y){
    return x.cnt==y.cnt ? x.pos < y.pos : x.cnt > y.cnt;
}
int n;
string ptr;
int main(){
    while(true){
        read(n);
        if(!n)  return 0;
        for(register int i=1;i<=n;++i){
            cin>>sc[i].st;
            sc[i].cnt=0,sc[i].pos=i;
            T.Insert(sc[i].st,i);
        }
        cin>>ptr;
        T.Getfail();
        T.Query(ptr);
        sort(sc+1,sc+n+1,Cmp);
        int maxn=sc[1].cnt;
        print(maxn),putchar('\n');
        for(register int i=1;i<=n;++i){
            if(sc[i].cnt!=maxn) break;
            cout<<sc[i].st<<endl;
        }
        T.Mem();
        for(register int i=1;i<=n;++i)  sc[i].Clear();
    }

    return 0;
}
