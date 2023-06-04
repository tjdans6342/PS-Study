// BOJ 2042
// SegTree (top-down)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sz;
struct Seg {
	vector<ll> tree;
	
	ll merge(ll left, ll right) {
		return left + right;
	}
	
	void build(int n) {
		for (sz=1; sz<n; sz*=2); // sz >= n
		tree.assign(2*sz, 0);

		for (int i=sz; i<sz+n; i++) cin >> tree[i];
		for (int i=sz-1; i>=1; i--) tree[i] = merge(tree[2*i], tree[2*i+1]);
	}

	void update(int idx, ll x) {
		tree[idx += sz] = x;
		while (idx /= 2) tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
	}

	ll query(int l, int r, int n=1, int nl=0, int nr=sz-1) {
		if (nr<l || r<nl) return 0;
		if (l<=nl && nr<=r) return tree[n];
		
		int mid = (nl + nr) / 2;
		return merge(query(l, r, 2*n, nl, mid), query(l, r, 2*n+1, mid+1, nr));
	}
} seg;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	seg.build(N);

	for (int i=0; i<M+K; i++) {
		ll op, a, b; cin >> op >> a >> b;

		if (op == 1) seg.update(a-1, b);
		if (op == 2) cout << seg.query(a-1, b-1) << '\n';
	}

	return 0;
}
