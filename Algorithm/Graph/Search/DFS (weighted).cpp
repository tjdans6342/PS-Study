#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visited;

// DFS function
void dfs(int node, int value) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto &[adj_node, w] : adj[node]) {
        dfs(adj_node, value+w);
    }
}

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    adj.resize(N+1);
    visited.assign(N+1, false);

    // adj[a].push_back({b, w});

    int start;
    dfs(start, 0);
    
    return 0;
}


