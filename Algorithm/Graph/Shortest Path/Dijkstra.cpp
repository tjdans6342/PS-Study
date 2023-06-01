#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct Node {
	int node, dist;
	Node(int a, int b) : node(a), dist(b) {}

	bool operator<(const Node &b) const {
		return b.dist < dist;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N;
	N = 0;

	vector<vector<pii>> adjList(N+1);
	vector<int> dist(N+1, -1);

	// Input
	// ~


	// Dijkstra
	priority_queue<Node> pq;
	pq.push(Node(0, 0)); // {start_node, start_dist} = {0, 0}

	while (pq.size()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.node] != -1) continue;
		dist[cur.node] = cur.dist;

		for (auto &[adjNode, adjDist] : adjList[cur.node]) {
			if (dist[adjNode] != -1) continue;
			pq.push(Node(adjNode, cur.dist + adjDist));
		}
	}

	return 0;
}