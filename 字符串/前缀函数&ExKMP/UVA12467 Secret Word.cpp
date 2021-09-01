#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
string s1,s2;
int pi[N<<1],T,ansr,len;
int main(){
    scanf("%d",&T);
    while(T--){
        cin>>s2;
        reverse(s2.begin(),s2.end());
        s1=s2;reverse(s2.begin(),s2.end());
        s1=s2+'#'+s1;
        pi[0]=ansr=len=0;
        int siz=s1.size();
        memset(pi,0,sizeof(pi));
        for(register int i=1;i<siz;++i){
            int j=pi[i-1];
            while(j&&s1[i]!=s1[j])  j=pi[j-1];
            if(s1[i]==s1[j])    ++j;
            pi[i]=j;
            if(pi[i]>len&&i>siz/2)    len=pi[i],ansr=i;
        }

        for(register int i=ansr;i>ansr-len;--i)    cout<<s1[i];
        puts("");
    }

    return 0;
}
