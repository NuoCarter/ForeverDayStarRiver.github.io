#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;

int n,m,len,ind;
int head[MAXN],f[MAXN],top[MAXN],id[MAXN],size[MAXN],son[MAXN],dep[MAXN];
ll w[MAXN],a[MAXN];

struct Edge{
    int to,next;
} e[MAXN * 2];

struct Tree{
    int l,r;
    ll sum,f;
} tree[MAXN * 4];

void add(int u,int v){
    e[++len].to = v;
    e[len].next = head[u];
    head[u] = len;
}

void dfs1(int u,int fa,int d){
    f[u] = fa;
    size[u] = 1;
    dep[u] = d;
    for(int i = head[u];i != -1;i = e[i].next){
        int v = e[i].to;
        if(v == fa)
            continue;
        dfs1(v,u,d + 1);
        size[u] += size[v];
        if(size[v] > size[son[u]])
            son[u] = v;
    }
}

void dfs2(int u,int t){
    top[u] = t;
    id[u] = ++ind;
    a[ind] = w[u];
    if(!son[u])
        return;
    dfs2(son[u],t);
    for(int i = head[u];i != -1;i = e[i].next){
        int v = e[i].to;
        if(v != f[u] && v != son[u])
            dfs2(v,v);
    }
}

void update(int k){
    tree[k].sum = tree[k * 2].sum + tree[k * 2 + 1].sum;
}

void down(int k){
    tree[k * 2].sum += tree[k].f * (tree[k * 2].r - tree[k * 2].l + 1);
    tree[k * 2 + 1].sum += tree[k].f * (tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1);
    tree[k * 2].f += tree[k].f;
    tree[k * 2 + 1].f += tree[k].f;
    tree[k].f = 0;
}

void build(int k,int l,int r){
    tree[k].l = l;
    tree[k].r = r;
    if(l == r){
        tree[k].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2,l,mid);
    build(k * 2 + 1,mid + 1,r);
    update(k);
}

void addInterval(int k,int l,int r,ll val){
    if(tree[k].l >= l && tree[k].r <= r){
        tree[k].f += val;
        tree[k].sum += val * (tree[k].r - tree[k].l + 1);
        return;
    }
    if(tree[k].f)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if(l <= mid)
        addInterval(k * 2,l,r,val);
    if(r > mid)
        addInterval(k * 2 + 1,l,r,val);
    update(k);
}

ll sumInterval(int k,int l,int r){
    ll cnt = 0;
    if(tree[k].l >= l && tree[k].r <= r)
        return tree[k].sum;
    if(tree[k].f)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if(l <= mid)
        cnt += sumInterval(k * 2,l,r);
    if(r > mid)
        cnt += sumInterval(k * 2 + 1,l,r);
    return cnt;
}

void addPoint(int k,int x,ll val){
    if(tree[k].l == tree[k].r){
        tree[k].sum += val;
        return;
    }
    if(tree[k].f)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if(x <= mid)
        addPoint(k * 2,x,val);
    else
        addPoint(k * 2 + 1,x,val);
    update(k);
}

ll sumTree(int x,int y){
    int fx = top[x],fy = top[y];
    ll ans = 0;
    while(fx != fy){
        if(dep[fx] >= dep[fy]){
            ans += sumInterval(1,id[fx],id[x]);
            x = f[fx];
            fx = top[x];
        }else{
            ans += sumInterval(1,id[fy],id[y]);
            y = f[fy];
            fy = top[y];
        }
    }
    if(id[x] <= id[y])
        ans += sumInterval(1,id[x],id[y]);
    else
        ans += sumInterval(1,id[y],id[x]);
    return ans;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%lld",&w[i]);
    for(int i = 1;i < n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    while(m--){
        int op,x;
        ll y;
        scanf("%d%d",&op,&x);
        if(op == 1){
            scanf("%lld",&y);
            addPoint(1,id[x],y);
        }else if(op == 2){
            scanf("%lld",&y);
            addInterval(1,id[x],id[x] + size[x] - 1,y);
        }else if(op == 3)
            printf("%lld\n",sumTree(1,x));
    }
    return 0;
}
