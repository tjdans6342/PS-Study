#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sz;
vector<pair<int, int>> tree;

void update(int idx, int x, int i) {
	idx += sz;
	tree[idx] = {x, i};
	while (idx /= 2) {
		if (tree[2*idx].first > tree[2*idx+1].first) tree[idx] = tree[2*idx];
		else tree[idx] = tree[2*idx+1];
	}
}

pair<int, int> query(int a, int b) {
	a += sz; b += sz;
	pair<int ,int> ret = {0, -1};

	while (a <= b) {
		if (a%2 == 1) {
			if (ret.first < tree[a].first) ret = tree[a];
			a++;
		}
		if (b%2 == 0) {
			if (ret.first < tree[b].first) ret = tree[b];
			b--;
		}
		a /= 2; b /= 2;
	}

	return ret;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	sz = (1 << ((int)ceil(log2((int)(1e5+10)))));
	tree.assign(2*sz, {0, 0});

	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		int x; cin >> x; 
		v[x] = i;
	}
	vector<int> arr(n);
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		arr[v[x]] = i;
	}

	vector<int> dp(n, 0);
	vector<int> path(n, 0);

	for (int i=0; i<n; i++) {
		int x = arr[i];
		int best, idx;
		tie(best, idx) = query(0, x-1);

		path[i] = idx;
		dp[i] = best+1;
		update(x, dp[i], i);
	}

	for (auto &u : arr) {
		cout << u << ' ';
	}
	cout << '\n';

	for (int i=0; i<n; i++) {
		cout << path[i] << ' ' << dp[i] << "    ";
	}
	cout << '\n';

	ll res = 0;
	vector<bool> processed(n, false);
	for (int i=n-1; i>=0; i--) {
		int cur = i;

		ll total = dp[i], num = 0;

		while (cur >= 0) {
			if (processed[cur]) break;
			processed[cur] = true;
			num++;
			cur = path[cur];
		}

		ll p = num;
		ll q = total - num;

		ll val = max(total*(total-1)*(total-2)/6, 0LL);
		val -= max(q*(q-1)*(q-2)/6, 0LL);

		res += val;
		// if (p >= 3) res += p*(p-1)*(p-2)/6; // mistake point
		// if (p >= 2 && q != 0) res += p*(p-1)/2 * q;
		// if (p >= 1 && q != 0) res += p * max(q*(q-1)/2, 0LL);

		// cout << i << ' ' << total << ' ' << num << '\n';
	}

	if (res == 0) {
		cout << "Attention is what I want" << '\n';
	}
	else {
		cout << "My heart has gone to paradise" << '\n';
		cout << res <<'\n';
	}

	return 0;
}