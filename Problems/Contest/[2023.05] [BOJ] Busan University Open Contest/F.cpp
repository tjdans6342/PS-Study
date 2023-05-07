#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> link;
vector<int> sz;

// Union-Find functions
int find(int x) {
    if (link[x] == x) return x;
    else return link[x] = find(link[x]);
}
bool same(int a, int b) {
    return find(a) == find(b);
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b]; sz[b] = 0;
    link[b] = a;
}

// DFS
vector<vector<pair<ll, ll>>> adj;
vector<bool> visited;

ll mx_dist = 0;

void dfs(int node, ll value) {
	if (visited[node]) return;
	visited[node] = true;

	int cnt = 0;
	for (auto &[adj_node, w] : adj[node]) {
		if (visited[adj_node]) continue;
		dfs(adj_node, value+w); cnt++;
	}

	if (cnt == 0) {
		mx_dist = max(mx_dist, value);
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M; cin >> N >> M;

	sz.assign(N+1, 1);
	link.resize(N+1);
	for (int i=1; i<=N; i++) link[i] = i;
	
	vector<array<int, 3>> edges;
	
	for (int i=0; i<M; i++) {
		int a, b, w; cin >> a >> b >> w;
		edges.push_back({a, b, w});
	}

	sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
		return a[2] > b[2];
	});

	adj.resize(N+1);
	visited.assign(N+1, false);

	ll total = 0, edge_num = 0;
	for (auto &[a, b, w] : edges) {
		if (same(a, b)) continue;
		total += w;
		unite(a, b);

		adj[a].push_back({b, w});
		adj[b].push_back({a, w});

		if (++edge_num == N-1) break;
	}

	int start; cin >> start;
	dfs(start, 0);

	cout << 2*total - mx_dist << '\n';
	return 0;
}