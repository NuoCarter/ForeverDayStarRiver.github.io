#include <bits/stdc++.h>
using namespace std;
const int N=210000;
int n,k,head[N],maxE,d[N],maxd,stx;
int p,f[N],vd[N],pro[N],maxx;
struct Edge{int nxt,to;}e[N];
inline void Add(int u,int v)
{
	e[++maxE].nxt=head[u];
	head[u]=maxE;
	e[maxE].to=v;
}
bool cp(int x,int y){return x>y;}
void DFSFind1(int x,int before)
{
	if(d[x]>maxd) maxd=d[x],stx=x;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==before) continue;
		d[e[i].to]=d[x]+1;
		DFSFind1(e[i].to,x);
	}
}
void DFSFind2(int x,int before)
{
	if(d[x]>maxd) maxd=d[x],stx=x;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==before) continue;
		d[e[i].to]=d[x]+1;f[e[i].to]=x;
		DFSFind2(e[i].to,x);
	}
}
void DFSFind3(int x,int before)
{
	d[x]=d[before]+1;vd[x]=d[x];
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==before) continue;
		DFSFind3(e[i].to,x);
		vd[x]=max(vd[x],vd[e[i].to]);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		Add(u,v);Add(v,u);
	}
    DFSFind1(1,0);memset(d,0,sizeof(d));
    maxd=0;DFSFind2(stx,0);p=stx;
    for(int i=1;i<=(d[stx]+1)/2;i++) p=f[p];
	memset(d,0,sizeof(d));
	DFSFind3(p,0);
	for(int i=1;i<=n;i++) pro[i]=vd[i]-d[i];
	sort(pro+1,pro+1+n,cp);
	printf("%d\n",pro[k+1]+1);
	return 0;
}
