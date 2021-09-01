#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+3;
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
int n,v;
int cnt1,cnt2;
struct node{
    int ord,val;
}p1[N],p2[N];
inline bool cmp(node x,node y){return x.val>y.val;}
int sum1[N],sum2[N],ans;
int loc1,loc2;

int main(){
    read(n),read(v);
    for(register int i=1;i<=n;++i){
        int op;read(op);
        if(op==1){
            read(p1[++cnt1].val);
            p1[cnt1].ord=i;
        }
        else{
            read(p2[++cnt2].val);
            p2[cnt2].ord=i;
        }
    }
    sort(p1+1,p1+cnt1+1,cmp);sort(p2+1,p2+cnt2+1,cmp);

    for(register int i=1;i<=cnt2;++i) sum2[i]=sum2[i-1]+p2[i].val;

    for(register int i=1;i<=cnt1;++i) sum1[i]=sum1[i-1]+p1[i].val;

    for(register int i=0;i<=cnt1;++i){
        if(i>v) break;
        if(v-i<=0){
            if(sum1[i]>ans){
                ans=sum1[i];
                loc1=i,loc2=0;
            }
        }
        if(sum1[i]+sum2[min((v-i)/2,cnt2)]>ans){
            ans=sum1[i]+sum2[min((v-i)/2,cnt2)];
            loc1=i,loc2=min((v-i)/2,cnt2);
        }
    }
    print(ans),putchar('\n');

    for(register int i=1;i<=loc1;++i)    print(p1[i].ord),putchar(' ');

    for(register int i=1;i<=loc2;++i)   print(p2[i].ord),putchar(' ');
    return 0;
}
