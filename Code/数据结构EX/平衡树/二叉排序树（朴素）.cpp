#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+10;
int n,cnt=1,a[N];//cnt是树的节点总数 
struct node{
	int lc=0,rc=0,val=0,w=0;//lc,rc是两个儿子,val是当前节点的值,w是当前节点有几个 
}t[N];
void insert(int o,int v){//向点o插入一个v 
	if(!t[o].val){//若这个节点是空的 
		t[o].val=v;
		t[o].w++; 
		return ;
	}
	if(t[o].val==v){//若这个节点刚好等于 
	    t[o].w++;
	    return ;
	}
    if(t[o].val>v){//往右子树遍历 
    	if(!t[o].lc){
    		cnt++;
    	    t[o].lc=cnt;
		}
    	insert(t[o].lc,v);
    	return ;
	}
	if(t[o].val<v){//往左子树遍历 
		if(!t[o].rc){
			cnt++;
		    t[o].rc=cnt;
		}
		insert(t[o].rc,v);
	}
	return ; 
}
void dfs(int o){//遍历这棵二叉排序树 
	if(!t[o].val) return ;
	if(t[o].lc) dfs(t[o].lc);//往左遍历
	cout<<t[o].val<<" ";//输出根节点 
	if(t[o].rc) dfs(t[o].rc);//往右遍历 
	return ; 
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insert(1,a[i]);
	}
	dfs(1);
	return 0;
}

