#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int M=203,N=14005;
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
ll cnt2[N],cnt5[N],n,k,dp[2][M][N];
ll a[N];

inline void Bre(int i){
    ll tep=a[i];
    while(tep%5==0){cnt5[i]++;tep/=5;}
    while(tep%2==0){cnt2[i]++;tep/=2;}
    return;
}
int lim=14000,sum2;
signed main(){
    read(n),read(k);
    for(register int i=1;i<=n;++i){read(a[i]);Bre(i);}
    int now=1;
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    // for(register int i=1;i<=n;++i)  cout<<cnt1[i]<<" "<<cnt2[i]<<endl;

    for(register int i=1;i<=n;++i){
        int to=now^1;
        sum2+=cnt2[i];
        for(register int j=0;j<=min(i,k);++j){
            for(register int o=0;o<=sum2;++o){
                dp[now][j][o]=max(dp[now][j][o],dp[to][j][o]);
                if(j>=1&&o>=cnt2[i]&&dp[to][j-1][o-cnt2[i]]>=0) dp[now][j][o]=max(dp[now][j][o],dp[to][j-1][o-cnt2[i]]+cnt5[i]);
            }
        }
        now^=1;
    }
    ll ans=0;
    for(register int i=0;i<=lim;++i){
        ans=max(ans,min(i,dp[now^1][k][i]));
        // if(!flag&&ans==2){
        //     print(i),putchar('\n');
        //     flag=true;
        // }
        // if(i<=10)
        // cout<<dp[now][k][i]<<endl;
    }
    print(ans);
    return 0;
}
