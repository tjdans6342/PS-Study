 // BOJ 10999
 // Lazy SegTree

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sz;
struct Seg {
	vector<ll> tree, lazy;

	void build(int n) {
		for (sz=1; sz<n; sz*=2);
		tree.assign(2*sz, 0);
		lazy.assign(2*sz, 0);

		for (int i=sz; i<sz+n; i++) cin >> tree[i];
		for (int i=sz-1; i>=1; i--) tree[i] = tree[2*i] + tree[2*i+1];
	}

	void update(int l, int r, ll x, int n=1, int nl=0, int nr=sz-1) {
		propagate(n, nl, nr);
		if (nr<l || r<nl) return;
		if (l<=nl && nr<=r) {
			lazy[n] += x;
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) / 2;
		update(l, r, x, 2*n, nl, mid);
		update(l, r, x, 2*n+1, mid+1, nr);
		tree[n] = tree[2*n] + tree[2*n+1]; // update current(high-position) node
	}

	ll query(int l, int r, int n=1, int nl=0, int nr=sz-1) {
		propagate(n, nl, nr);

		if (nr<l || r<nl) return 0;
		if (l<=nl && nr<=r) return tree[n];

		int mid = (nl + nr) / 2;
		return query(l, r, 2*n, nl, mid) + query(l, r, 2*n+1, mid+1, nr);
	}

	void propagate(int n, int nl, int nr) {
		if (lazy[n] != 0) {
			if (n < sz) { // (if not leaf node) propagte child node
				lazy[2*n] += lazy[n];
				lazy[2*n+1] += lazy[n];
			}
			// update current node
			tree[n] += lazy[n] * (nr-nl+1);
			lazy[n] = 0;
		}
	}
} seg;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	seg.build(N);

	for (int i=0; i<M+K; i++) {
		ll op, a, b, x; cin >> op >> a >> b;

		if (op == 1) {
			cin >> x;
			seg.update(a-1, b-1, x);
		}	
		if (op == 2) {
			cout << seg.query(a-1, b-1) << '\n';
		}
	}

	return 0;
}
