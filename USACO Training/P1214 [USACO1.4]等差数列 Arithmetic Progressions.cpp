#include<bits/stdc++.h>
using namespace std;
template  <typename T>
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
const int N=25,M=125003;
int a[N],n,m;
bool hav[M];
vector<pair<int,int> > ans;
inline bool Cmp(pair<int,int> x,pair<int,int> y){
    return x.second==y.second ? x.first<y.first : x.second < y.second;
}
int main(){
    read(n),read(m);
    int lim=m*m*2;
    for(register int i=0;i<=m;++i)
        for(register int j=0;j<=m;++j)
            hav[i*i+j*j]=true;

    // puts("????");
    // cout<<lim<<endl;
    for(register int fi=0;fi<=lim-n+1;++fi){
        int d=(lim-fi)/(n-1);
        // cout<<d<<" "<<fi<<endl;
        if(!hav[fi])    continue;
        for(register int j=1;j<=d;++j){
            int tmp=fi;bool fl=false;
            for(register int now=2;now<=n;++now){
                tmp+=j;
                if(!hav[tmp]){fl=true;break;}
            }
            if(!fl) ans.push_back(make_pair(fi,j));
        }
    }
    int siz=ans.size();
    sort(ans.begin(),ans.end(),Cmp);
    if(!siz){puts("NONE");return 0;}
    for(register int i=0;i<siz;++i)    print(ans[i].first),putchar(' '),print(ans[i].second),putchar('\n');
    return 0;
}
