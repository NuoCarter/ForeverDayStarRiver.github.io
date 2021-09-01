#include <iostream>
#include <cstdio>
using namespace std;
const int mm=1<<19;
const int cc[9][9]= {{3,3,0,3,3,0,0,0,0},
    {3,3,3,0,0,0,0,0,0},
    {0,3,3,0,3,3,0,0,0},
    {3,0,0,3,0,0,3,0,0},
    {0,3,0,3,3,3,0,3,0},
    {0,0,3,0,0,3,0,0,3},
    {0,0,0,3,3,0,3,3,0},
    {0,0,0,0,0,0,3,3,3},
    {0,0,0,0,3,3,0,3,3}
};
bool v[4][4][4][4][4][4][4][4][4];
struct Node
{
    int status[9];
    int step,path;
};
Node q[mm];
int cl[9];
int head,tail;
bool bb=1;
int ans;
bool isEnd(int c[])
{
    for(int i=0; i<9; i++)
        if(c[i]!=0)return 0;
    return 1;
}
void printout(int i)
{
    if(q[i].path<0)return;
    printout(q[i].path);
    printf("%d ",q[i].step+1);
}
int main()
{
    //freopen(".in" ,"r",stdin)
    //freopen(".out" ,"w",stdout)
    for(int i=0; i<9; i++)
    {
        cin>>cl[i];
        cl[i]%=12;
    }
    v[cl[0]/3][cl[1]/3][cl[2]/3][cl[3]/3][cl[4]/3][cl[5]/3][cl[6]/3][cl[7]/3][cl[8]/3]=1;
    if(v[0][0][0][0][0][0][0][0][0])
        return 0;
    for(int i=0; i<9; i++)
        q[0].status[i]=cl[i];
    q[0].step=-1;
    q[0].path=-1;
    head=tail=0;
    while(head<=tail&&tail<mm-10&&bb)
    {
        int tc[9];
        for(int k=0; k<9; k++)
        {
            for(int i=0; i<9; i++)
                tc[i]=(q[head].status[i]+cc[k][i])%12;
            if(v[tc[0]/3][tc[1]/3][tc[2]/3][tc[3]/3][tc[4]/3][tc[5]/3][tc[6]/3][tc[7]/3][tc[8]/3])continue;
            v[tc[0]/3][tc[1]/3][tc[2]/3][tc[3]/3][tc[4]/3][tc[5]/3][tc[6]/3][tc[7]/3][tc[8]/3]=1;
            ++tail;
            for(int i=0; i<9; i++)
                q[tail].status[i]=tc[i];
            q[tail].step=k;
            q[tail].path=head;
            if(v[0][0][0][0][0][0][0][0][0])
            {
                ans=tail;
                bb=0;
                break;
            }
        }
        ++head;
    }
    printout(ans);
    return 0;
}
