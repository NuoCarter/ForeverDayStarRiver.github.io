#include <bits/stdc++.h>
#define REP(i, l, r) for(int i = (l); i <= (r); i++)
#define PER(i, r, l) for(int i = (r); i >= (l); i--)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, b) memset(a, b, sizeof(a))
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define mid (l + r >> 1)
using namespace std;
typedef long long LL;
const int N = 100000 + 5;
int a[N], tag_add[N * 4], tag_mul[N * 4], sum[N * 4], MOD;
int merge(int x, int y){
	return (x + y) % MOD;
}
void mul(int x, int d){
	sum[x] = (LL)sum[x] * d % MOD;
	tag_mul[x] = (LL)tag_mul[x] * d % MOD;
	tag_add[x] = (LL)tag_add[x] * d % MOD;
}
void add(int x, int d, int len){
	sum[x] = (sum[x] + (LL)d * len) % MOD;
	tag_add[x] = (tag_add[x] + d) % MOD;
}
void pushdown(int x, int l, int r){
	if (tag_mul[x] != 1){
		mul(lc(x), tag_mul[x]);
		mul(rc(x), tag_mul[x]);
		tag_mul[x] = 1;
	}
	if (tag_add[x]){
		add(lc(x), tag_add[x], mid - l + 1);
		add(rc(x), tag_add[x], r - mid);
		tag_add[x] = 0;
	}
}
void update(int x){
	sum[x] = merge(sum[lc(x)], sum[rc(x)]);
}
void modify_mul(int x, int l, int r, int L, int R, int d){
	if (l > R || r < L) return;
	if (l >= L && r <= R) {mul(x, d); return;}
	pushdown(x, l, r);
	modify_mul(lc(x), l, mid, L, R, d);
	modify_mul(rc(x), mid + 1, r, L, R, d);
	update(x);
}
void modify_add(int x, int l, int r, int L, int R, int d){
	if (l > R || r < L) return;
	if (l >= L && r <= R) {add(x, d, r - l + 1); return;}
	pushdown(x, l, r);
	modify_add(lc(x), l, mid, L, R, d);
	modify_add(rc(x), mid + 1, r, L, R, d);
	update(x);
}
int query(int x, int l, int r, int L, int R){
	if (l > R || r < L) return 0;
	if (l >= L && r <= R) return sum[x];
	pushdown(x, l, r);
	return merge(query(lc(x), l, mid, L, R), query(rc(x), mid + 1, r, L, R));
}
void build(int x, int l, int r){
	tag_mul[x] = 1;
	if (l == r) {sum[x] = a[l]; return;}
	build(lc(x), l, mid);
	build(rc(x), mid + 1, r);
	update(x);
}
int main(){
	int n, m;
	scanf("%d%d",&n,&MOD);
	REP(i, 1, n) scanf("%d", &a[i]);
	build(1, 1, n);
  scanf("%d",&m);
	REP(i, 1, m){
		int tp, l, r, d;
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1){
			scanf("%d", &d);
			modify_mul(1, 1, n, l, r, d);
		} else
		if (tp == 2){
			scanf("%d", &d);
			modify_add(1, 1, n, l, r, d);
		} else
			printf("%d\n", query(1, 1, n, l, r));
	}
}
