#include<bits/stdc++.h>
using namespace std;

template<typename T>
inline void Read(T &n){
    char ch; bool flag=0;
    while(!isdigit(ch=getchar()))if(ch=='-')flag=1;
    for(n=ch^48;isdigit(ch=getchar());n=(n<<1)+(n<<3)+(ch^48));
    if(flag)n=-n;
}
template <typename T>
inline void print(T x){
  if(x<0) putchar('-'),x=-x;
  if(x>9) print(x/10);
  putchar(x%10^48);
}
typedef long long ll;
const int MAXN = 300005;

int n, m;

struct _{
    int nxt, to;ll len;
    _(int nxt=0, int to=0, ll len=0):nxt(nxt),to(to),len(len){}
}edge[MAXN<<1];
int fst[MAXN], tot;

inline void Add_Edge(int f, int t, ll len){
    edge[++tot] = _(fst[f], t, len); fst[f] = tot;
    edge[++tot] = _(fst[t], f, len); fst[t] = tot;
}

int belong[MAXN];
ll dis_fa[MAXN], dis[MAXN];
int top[MAXN],dep[MAXN],loc[MAXN],dfn[MAXN],son[MAXN],sz[MAXN],fa[MAXN],cnt;
void Dfs1(int x, int y){
    dep[x] = dep[y]+1;
    belong[x] = (dep[x]==2?x:belong[y]);
    fa[x] = y;
    sz[x] = 1;
    for(register int u=fst[x]; u; u=edge[u].nxt){
        int v=edge[u].to;
        if(v==y) continue;
        dis[v] = dis[x]+edge[u].len;
        Dfs1(v,x);
        dis_fa[v] = edge[u].len;
        sz[x] += sz[v];
        if(sz[v] > sz[son[x]])
            son[x] = v;
    }
}

void Dfs2(int x, int y){
    top[x] = y;
    loc[x] = cnt;
    dfn[cnt] = x;
    cnt++;
    if(son[x])
        Dfs2(son[x],y);
    for(register int u=fst[x]; u; u=edge[u].nxt){
        int v=edge[u].to;
        if(v==fa[x] or v==son[x]) continue;
        Dfs2(v,v);
    }
}

inline int Jump(int x, ll height){
    while(dis[x]-height <= dis[top[x]]){
        height -= dis[x]-dis[top[x]];
        x = top[x];

        if(height<dis_fa[x]) return x;

        height -= dis_fa[x];
        x = fa[x];
    }

    int head=max(1,loc[top[x]]), tail=loc[x], mid;
    while(head<tail){
        mid = head+tail >> 1;
        if(dis[x]-height<=dis[dfn[mid]])
            tail = mid;
        else
            head = mid+1;
    }
    return dfn[head];
}

struct First_Son{
    int id;ll need;
    inline bool operator <(const First_Son &k)const{return need<k.need;}
    #define id(x) fst_son[x].id
    #define need(x) fst_son[x].need
}fst_son[MAXN];
int son_num;

int Start[MAXN];

struct Skip{
    int belong;
    ll remain;
    bool used;
    inline bool operator <(const Skip &k)const{return remain<k.remain;}
    #define root(x) skipped[x].belong
    #define remain(x) skipped[x].remain
    #define used(x) skipped[x].used
}skipped[MAXN];
int skip_num;

bool Controlled[MAXN], vis[MAXN];
void Dfs(int x){
    if(Controlled[x]) return;
    vis[x] = true;
    bool leaf=true, All=true;
    for(register int u=fst[x]; u; u=edge[u].nxt){
        int v=edge[u].to;
        if(vis[v]) continue;
        Dfs(v);
        leaf=false;
        All &= Controlled[v];
    }
    if(All and not leaf)
        Controlled[x] = true;
    vis[x] = false;
}

int min_id[MAXN];

inline bool Check(ll mid){
    skip_num=0;
    for(register int i=1; i<=n; i++) Controlled[i] = false;

    for(register int i=1; i<=m; i++)
        if(dis[Start[i]]<=mid)
            skipped[++skip_num] = (Skip){belong[Start[i]],mid-dis[Start[i]],false};
        else
            Controlled[Jump(Start[i],mid)] = true;
    sort(skipped+1,skipped+skip_num+1);

    for(register int i=1; i<=son_num; i++) min_id[id(i)] = 0;
    for(register int i=1; i<=skip_num; i++)
        if(not min_id[root(i)])
            min_id[root(i)] = i;

    Dfs(1);

    int id=skip_num;
    for(register int i=son_num; i>=1; i--){
        int now=id(i);
        if(Controlled[now]) continue;
        if(min_id[now] and not used(min_id[now])){
            used(min_id[now]) = true;
            continue;
        }
        while(id and used(id)) id--; if(id<=0) return false;
        if(remain(id)<need(i)) return false;
        used(id) = true; id--;
    }

    return true;
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
    Read(n);
    for(register int i=1; i<n; i++){
        int f, t; ll len;
        Read(f); Read(t); Read(len);
        Add_Edge(f,t,len);
    }

    Dfs1(1,1);
    Dfs2(1,1);

    ll max_dis=0;
    for(register int i=1; i<=n; i++) max_dis=max(max_dis,dis[i]);

    for(register int u=fst[1]; u; u=edge[u].nxt)
        fst_son[++son_num] = (First_Son){edge[u].to,edge[u].len};
    sort(fst_son+1,fst_son+son_num+1);

    Read(m);
    for(register int i=1; i<=m; i++) Read(Start[i]);

    if(m<son_num){
        puts("-1");
        return 0;
    }

    ll l=0, r=max_dis+fst_son[son_num].need, mid;
    while(l<r){
        mid = l+r >> 1;
        if(Check(mid))
            r = mid;
        else
            l = mid+1;
    }
    print(l);
    return 0;
}
