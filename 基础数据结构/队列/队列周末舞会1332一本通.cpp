#include<bits/stdc++.h>
using namespace std;
int qa[100001],qb[100001];
int ah,at,bh,bt;
int main(){
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		qa[i]=i;
	}
	at=a;ah=0;
	for(int i=1;i<=b;i++){
		qb[i]=i;
	}
	bt=b;bh=0;
	int mround;
	cin>>mround;
	for(int i=1;i<=mround;i++){
		ah++;
		int t=qa[ah];
		at++;
		qa[at]=t;
		cout<<t<<" ";
		bh++;
		t=qb[bh];
		bt++;
		qb[bt]=t;
		cout<<t<<endl;
	}
	return 0;
}
