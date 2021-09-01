/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年10月22日 星期二 11时02分10秒
*******************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct IO{
    template<typename T>
    IO & operator>>(T&res)
    {
        T q=1;char ch;
        while((ch=getchar())<'0' or ch>'9')if(ch=='-')q=-q;
        res=(ch^48);
        while((ch=getchar())>='0' and ch<='9') res=(res<<1)+(res<<3)+(ch^48);
        res*=q;
        return *this;
    }
}cin;

struct edge{
    int to,next,w;
    edge(int a=0,int b=0,int c=0):to(a),next(b),w(c){}
};

const int maxn=2e5+10;
const int mod=1e9+7;
int id,n,m1,m2,head[maxn],cnt,size[maxn][2],col[maxn],c,a[maxn],fac[maxn],b[maxn];
long long ans=1;
bool vis[maxn],flag;
edge e[maxn<<1];

void add(int u,int v,int w){
    e[++cnt]=edge(v,head[u],w);
    head[u]=cnt;
}

void dfs(int now,int s,int fa){
    if(vis[now]){ flag=1;return;}
    vis[now]=1;
    col[c]++;
    bool fg=0;
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=fa)
            dfs(e[i].to,e[i].w,now),fg=1;
    if(!fg) a[c]=s;
}

int main(){
    cin>>id>>n>>m1>>m2;
    int u,v;
    for(int i=1;i<=m1+m2;i++)
    {
        cin>>u>>v;
        add(u,v,i<=m1);
        add(v,u,i<=m1);
    }
    memset(a,-1,sizeof a);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            flag=0;
            ++c,dfs(i,1,0);
            if(!flag)
            {
                // printf("%d??\n",a[c]);
                size[col[c]][a[c]]++;
                if(col[c]%2==0)
                    ans=ans*2%mod;
            }
            else
                ans=ans*col[c],b[col[c]]++;
                // printf("%lld??\n",ans);
        }
    fac[0]=fac[1]=1;
    for(int i=2;i<=n;i++)
        fac[i]=fac[i-1]*1ll*i%mod;
    for(int i=1;i<=n;i++)
    {
        // printf("%lld\n",ans);
        printf("%lld\n",size[i][1]);
        if(i%2==0)
            for(int j=0;j<=1;j++)
                ans=1ll*ans*fac[size[i][j]]%mod;
        else
            ans=1ll*ans*fac[size[i][0]+size[i][1]]%mod;
        ans=1ll*ans*fac[b[i]]%mod;
        // printf("%lld\n",ans);
    }
    ans=(fac[n]-ans+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
