#include<bits/stdc++.h>
using namespace std;
#define inf 10000007
const int N = 300005;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=false;
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch))  x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
template <typename T>
inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10^48);
}
int n, head[N], cnt = 1;

int dp[N][3], val[N];
int in[N];
struct Node{
    int v, nxt;
} G[N];

void insert(int u, int v) {
    G[cnt] = (Node) {v, head[u]}; head[u] = cnt++;
}
void DP(int x, int fa) {
    dp[x][0] = 1; dp[x][2] = inf;
    for (int i = head[x]; i; i = G[i].nxt) {
        int v = G[i].v; if(v == fa) continue;
        DP(v, x); dp[x][0] += min(dp[v][1], min(dp[v][0], dp[v][2]));
        dp[x][1] += min(dp[v][0], dp[v][2]);
    }
    for (int i = head[x]; i; i = G[i].nxt) {
        int v = G[i].v; if(v == fa) continue;
        dp[x][2] = min(dp[x][2], dp[x][1] - min(dp[v][0], dp[v][2]) + dp[v][0]);
    }
}

int main() {
    read(n);
    for (int i = 1,x,y; i <= n - 1; ++i) {
        read(x);
            read(y);
            insert(x, y); insert(y, x);
    }
    DP(1, -1);
    print(min(dp[1][0],dp[1][2]));
    return 0;
}
