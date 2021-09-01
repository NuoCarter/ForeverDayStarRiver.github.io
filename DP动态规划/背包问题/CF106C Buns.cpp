#include<iostream>
using namespace std;
int dp[10010];
int main(){
    int n,m,c0,d0;
    cin>>n>>m>>c0>>d0;
    for(register int i=c0;i<=n;++i) dp[i]=i/c0*d0;
    int a,b,c,d;
    for(register int i=1;i<=m;++i){
        cin>>a>>b>>c>>d;
        for(register int j=1;j<=a/b;++j){
            for(register int k=n;k>=c;--k) dp[k]=max(dp[k-c]+d,dp[k]);
        }
    }
    cout<<dp[n];
    return 0;
}
