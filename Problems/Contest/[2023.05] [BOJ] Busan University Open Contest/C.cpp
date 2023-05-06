#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> arr;
vector<vector<double>> dp;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	arr.assign(N, vector<int>(M));
	dp.assign(N, vector<double>(M, 0));

	int sy, sx;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) sy = i, sx = j;
		}
	}

	dp[sy][sx] = 1e100;
	for (int i=1; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (arr[i][j] == 1) continue;
			else {
				// left
				if (j > 0 && arr[i][j-1] == 1 && arr[i-1][j] == 0) {
					dp[i][j] += dp[i-1][j-1]/2;
				}
				// right
				if (j < M-1 && arr[i][j+1] == 1 && arr[i-1][j] == 0) {
					dp[i][j] += dp[i-1][j+1]/2;
				}
				// mid
				dp[i][j] += dp[i-1][j];
			}
		}
	}

	double best = 0.0;
	int idx = -1;
	for (int j=0; j<M; j++) {
		if (best < dp[N-1][j]) {
			best = dp[N-1][j];
			idx = j;
		}
	}

	cout << idx << '\n';
	return 0;
}