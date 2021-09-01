#include<bits/stdc++.h>
using namespace std;
int money,n;
int p[1005],w[1005];//p为价格，w为重要度
int q;
struct parts{
	int order;
	int number;
	int im;
	int price;
}a[1005][4];//利用结构体存储价钱与重要度
long long f[32005];
int main(){
	int o=1;
	int sum=0;
	scanf("%d%d",&money,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&p[i],&w[i],&q);
		w[i]*=p[i];//题目定义
		if(q==0){
			sum++;
			a[sum][1].number=sum;
			a[sum][1].price=p[i];
			a[sum][1].im=w[i];
			a[sum][1].order=i;//为后面的主件附件做准备
		}
		else{
			for(int j=1;j<=sum;j++){//主件当前的个数
				if(a[j][1].order==q){//附件的各种赋值
					if(a[j][2].number==0){
						a[j][2].number=2;
						a[j][2].im=w[i];
						a[j][2].price=p[i];
						break;
					}
					else {
						a[j][3].number=3;
						a[j][3].im=w[i];
						a[j][3].price=p[i];
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=sum;i++){
		for(int j=money;j>=1;j--){//也可以写j>=a[i][1].price;
			if(a[i][1].price<=j)	f[j]=max(f[j],f[j-a[i][1].price]+a[i][1].im);
			if(a[i][1].price+a[i][2].price<=j)	f[j]=max(f[j],f[j-a[i][1].price-a[i][2].price]+a[i][1].im+a[i][2].im);
			if(a[i][1].price+a[i][3].price<=j)	f[j]=max(f[j],f[j-a[i][1].price-a[i][3].price]+a[i][1].im+a[i][3].im);
			if(a[i][1].price+a[i][2].price+a[i][3].price<=j)	f[j]=max(f[j],f[j-a[i][1].price-a[i][2].price-a[i][3].price]+a[i][1].im+a[i][2].im+a[i][3].im);
		}
	}
	long long maxn=0;
	for(int i=1;i<=money;i++){
		maxn=max(maxn,f[i]);
	}
	cout<<maxn;
	return 0;
}
