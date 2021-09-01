#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[55][55];
int main() {
    string s;
    cin >> s;
    memset(dp, 0x3f, sizeof(dp));
    for(register int i=0;i<s.size();i++){
    	dp[i][i]=1;
    }
    for(register int l=2;l<=s.size();l++){
        for(register int i=0;i<s.size()-l+1;i++){
            int j=i+l-1;
            if(s[i]==s[j]){
                if(l==2)  dp[i][j]=1;
                else  dp[i][j]=min(min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]+1);
            }
            else{
                for(register int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    printf("%d\n",dp[0][s.size()-1]);
    return 0;
}
