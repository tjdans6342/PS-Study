#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

int N, M;
vector<vector<int>> adj, dist;
vector<array<int, 3>> edges;

void init() {
	adj.assign(N+1, vector<int>(N+1, INF)); // INF

	for (int i=0; i<M; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][v] = adj[v][u] = min(adj[u][v], w); // value
		edges.push_back({u, v, w});
	}
	for (int i=0; i<=N; i++) adj[i][i] = 0; // 0
}

void floyd() {
	dist.assign(adj.begin(), adj.end());

	for (int k=1; k<=N; k++) { // node's range = [1, N]
		for (int u=1; u<=N; u++) {
			for (int v=1; v<=N; v++) {
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	init();

	floyd();

	return 0;
}