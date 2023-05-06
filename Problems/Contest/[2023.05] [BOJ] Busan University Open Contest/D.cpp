#include <bits/stdc++.h>
using namespace std;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;

	vector<vector<int>> dp(2, vector<int>(m, 0));
	int res = 1e8;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) { // dp[i][j]
			cin >> dp[i%2][j];

			int best = 1e8;
			for (int k=0; k<m; k++) { // dp[i-1][:]
				if (j != k) best = min(best, dp[(i+1)%2][k]);
			}
			dp[i%2][j] += best;

			if (i == n-1) res = min(res, dp[i%2][j]);
		}
	}

	cout << res << '\n';
	return 0;
}