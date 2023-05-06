#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e6;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector<ll> diff(MAX+2, 0);

	int N; cin >> N;

	// update
	for (int i=0; i<N; i++) {
		int s, e; cin >> s >> e;
		s++; e++;
		diff[s]++;
		diff[e+1]--;
	}

	vector<ll> psum(MAX+2, 0);
	for (int i=1; i<=MAX+1; i++) {
		psum[i] = psum[i-1] + diff[i];
	}

	int Q; cin >> Q;
	while (Q--) { // query
		int t; cin >> t;
		cout << psum[++t] << '\n';
	}

	return 0;
}