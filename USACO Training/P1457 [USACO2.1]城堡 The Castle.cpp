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
const int N=53;
int a[N][N],n,m,cnt,bel[N][N];
int dir[5][3]={{0,-1},{-1,0},{0,1},{1,0}};
bool vis[N][N];
int siz[N*N],res;
inline void Dfs(int x,int y,int now){
    vis[x][y]=true;bel[x][y]=now;
    siz[bel[x][y]]++;res=max(res,siz[bel[x][y]]);
    for(int i=0;i<4;++i){
        // cout<<a[x][y]<<"???"<<now<<endl;
        // cout<<a[x][y]<<" "<<(1<<i)<<" "<<(a[x][y] & (1<<i))<<endl;
        if((a[x][y] & (1<<i))) continue;
        // cout<<x+dir[i][0]<<" "<<y+dir[i][1]<<endl;
        if(vis[x+dir[i][0]][y+dir[i][1]])   continue;
        Dfs(x+dir[i][0],y+dir[i][1],now);
    }
    return;
}
char andir[4]={'?','N','E'};
int main(){
    read(m),read(n);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            read(a[i][j]);

    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            if(!bel[i][j])
                Dfs(i,j,++cnt);

    print(cnt),putchar('\n'),print(res),putchar('\n');

    int maxn=0,rx,ry;
    char rdir;
    for(register int j=1;j<=m;++j){
        for(register int i=n;i>=1;--i){
            for(register int k=1;k<=2;++k){
                if((a[i][j] & (1<<k))){
                    int tx=i+dir[k][0],ty=j+dir[k][1];
                    if(bel[tx][ty]==bel[i][j])  continue;
                    if(siz[bel[tx][ty]]+siz[bel[i][j]]>maxn){
                        maxn=siz[bel[tx][ty]]+siz[bel[i][j]];
                        rx=i,ry=j;rdir=andir[k];
                    }
                }
            }
        }
    }
    print(maxn),putchar('\n');
    print(rx),putchar(' '),print(ry),putchar(' '),putchar(rdir),putchar('\n');
    return 0;
}
