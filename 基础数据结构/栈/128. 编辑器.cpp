#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=1000005;
int n,k,f[N],top1,sum[N],tep;
char op;
stack<int> a,b;
signed main(){
    n=read();
    memset(f,-0x3f,sizeof(f));
    while(n--){
        cin>>op;
        if(op=='I'){
            k=read();
            a.push(k);
            tep=a.size();
            sum[tep]=sum[tep-1]+k;
            f[tep]=max(f[tep-1],sum[tep]);
        }
        else if(op=='D'){if(!a.empty())a.pop();}
        else if(op=='L'){
            if(!a.empty()){b.push(a.top());a.pop();}
        }
        else if(op=='R'){
            if(!b.empty()){
                a.push(b.top());
                b.pop();
                tep=a.size();
                sum[tep]=sum[tep-1]+a.top();
                f[tep]=max(f[tep-1],sum[tep]);
            }
        }
        else if(op=='Q'){
            k=read();
            printf("%d\n",f[k]);
        }
    }
    return 0;
}
