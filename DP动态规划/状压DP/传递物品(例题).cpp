#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[20][20];
int dp[1 << 16][20];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                for(int k=0;k<n;k++){
                    if(!(i&(1<<k))){
                        dp[i|1<<k][k]=min(dp[i|1<<k][k],dp[i][j]+a[j][k]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans << endl;
    return 0;
}
