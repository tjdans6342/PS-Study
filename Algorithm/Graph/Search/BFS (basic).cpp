#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    adj.resize(N+1);
    visited.assign(N+1, false);

    // adj[a].push_back(b);

    queue<int> q;

    int start;
    q.push(start); visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (auto &adj_node : adj[node]) {
            if (visited[adj_node]) continue;
            q.push(adj_node); visited[adj_node] = true;
        }
    }

    return 0;
}