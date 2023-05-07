#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sz;
struct Seg {
	vector<array<ll, 2>> tree;

	array<ll, 2> merge(array<ll, 2> &l, array<ll, 2> &r) {
		return {l[0]+r[0], l[1]+r[1]};
	}

	void build(int n) {
		for (sz=1; sz<n; sz*=2);
		tree.assign(2*sz, {0, 0});

		for (int i=sz-1; i>=1; i--) tree[i] = merge(tree[2*i], tree[2*i+1]);
	}

	void update(int idx, array<ll, 2> x) {
		tree[idx += sz] = x;
		while (idx /= 2) tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
	}

	array<ll, 2> query(int l, int r, int n=1, int nl=0, int nr=sz-1) {
		if (nr<l || r<nl) return {0, 0};
		if (l<=nl && nr<=r) return tree[n];
		
		int mid = (nl + nr) / 2;
		auto left = query(l, r, 2*n, nl, mid);
		auto right = query(l, r, 2*n+1, mid+1, nr);

		return merge(left, right);
	}
} seg;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	vector<int> v(N);
	for (int i=0; i<N; i++) {
		int x; cin >> x; 
		v[x] = i;
	}
	vector<int> arr(N);
	for (int i=0; i<N; i++) {
		int x; cin >> x;
		arr[v[x]] = i;
	}

	seg.build(N+1);

	ll ans = 0;
	for (auto &u : arr) {
		auto ret = seg.query(0, u-1);
		ans += ret[1];
		seg.update(u, {1, ret[0]});
	}

	if (ans == 0) cout << "Attention is what I want" << '\n';
	else {
		cout << "My heart has gone to paradise" << '\n';
		cout << ans << '\n';
	}

	return 0;
}