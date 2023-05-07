#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

// DFS function
void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto &adj_node : adj[node]) {
        dfs(adj_node);
    }
}

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    adj.resize(N+1);
    visited.assign(N+1, false);

    // adj[a].push_back(b);

    int start;
    dfs(start);
    
    return 0;
}


