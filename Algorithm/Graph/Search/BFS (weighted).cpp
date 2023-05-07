#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visited;

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    adj.resize(N+1);
    visited.assign(N+1, false);

    // adj[a].push_back({b, w});

    queue<pair<int, int>> q;

    int start;
    q.push({start, 0}); visited[start] = true;

    while (!q.empty()) {
        int node, value;
        tie(node, value) = q.front(); q.pop();

        for (auto &[adj_node, w] : adj[node]) {
            if (visited[adj_node]) continue;
            q.push({adj_node, w}); visited[adj_node] = true;
        }
    }

    return 0;
}