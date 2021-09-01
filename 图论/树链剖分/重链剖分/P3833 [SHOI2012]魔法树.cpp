#include<bits/stdc++.h>
#define ll long long
#define inf 1<<30
#define INF 1ll<<60
using namespace std;
const int MAXN=1e5+10;
struct node{
    int l,r;
    ll sum,inc;
}tr[MAXN<<2];
#define ls i<<1
#define rs i<<1|1
void pushup(int i){
    tr[i].sum=tr[ls].sum+tr[rs].sum;
}
void pushdown(int i){
    if(!tr[i].inc) return;
    tr[ls].sum+=tr[i].inc*(tr[ls].r-tr[ls].l+1);
    tr[rs].sum+=tr[i].inc*(tr[rs].r-tr[rs].l+1);
    tr[ls].inc+=tr[i].inc;
    tr[rs].inc+=tr[i].inc;
    tr[i].inc=0;
}
void build(int i,int l,int r){
    tr[i].l=l;tr[i].r=r;tr[i].inc=0;
    if(l==r){
        tr[i].sum=0;
        return;
    }int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    pushup(i);
}
void upd(int i,int l,int r,ll v){
    if(tr[i].l>=l&&tr[i].r<=r){
        tr[i].sum+=v*(r-l+1);
        tr[i].inc+=v;return;
    }pushdown(i);
    int mid=tr[i].l+tr[i].r>>1;
    if(r<=mid) upd(ls,l,r,v);
    else if(l>mid) upd(rs,l,r,v);
    else upd(ls,l,mid,v),upd(rs,mid+1,r,v);
    pushup(i);
}
ll query(int i,int l,int r){
    if(tr[i].l>=l&&tr[i].r<=r)
        return tr[i].sum;
    pushdown(i);
    int mid=tr[i].l+tr[i].r>>1;
    if(r<=mid) return query(ls,l,r);
    else if(l>mid) return query(rs,l,r);
    else return query(ls,l,mid)+query(rs,mid+1,r);
}

vector<int> e[MAXN];
int son[MAXN],fa[MAXN],dep[MAXN],siz[MAXN];
void predfs(int x,int f){
    son[x]=-1;fa[x]=f;
    siz[x]=1;
    for(int i=0;i<e[x].size();i++){
        int s=e[x][i];
        if(s==f) continue;
        dep[s]=dep[x]+1;
        predfs(s,x);
        siz[x]+=siz[s];
        if(son[x]==-1||siz[son[x]]<siz[s])
            son[x]=s;
    }
}
int top[MAXN],dfn[MAXN],lnk[MAXN],tot=0;
int ed[MAXN];
void dfs(int x,int tp){
    top[x]=tp;
    dfn[x]=++tot;
    lnk[tot]=x;
    if(son[x]==-1) return;
    dfs(son[x],tp);
    for(int i=0;i<e[x].size();i++){
        int s=e[x][i];
        if(s==fa[x]||s==son[x]) continue;
        dfs(s,s);
    }ed[x]=tot;
}
void cpu(int u,int v,ll x){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        upd(1,dfn[top[u]],dfn[u],x);
        u=fa[top[u]];
    }if(dfn[u]>dfn[v]) swap(u,v);
    upd(1,dfn[u],dfn[v],x);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        x++;y++;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    predfs(1,0);
    dfs(1,1);
    build(1,1,n);
    int Q,u,v;char s;ll t;
    scanf("%d",&Q);
    while(Q--){
        s=getchar();
        while(s!='A'&&s!='Q')
            s=getchar();
        if(s=='A'){
            scanf("%d%d%lld",&u,&v,&t);
            u++;v++;
            cpu(u,v,t);
        }else{
            scanf("%d",&u);
            u++;
            // if(dfn[u]+siz[u]-1!=ed[u])    puts("???");

            printf("%lld\n",query(1,dfn[u],ed[u]));
        }
    }
}
