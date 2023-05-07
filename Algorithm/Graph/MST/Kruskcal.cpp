#include <bits/stdc++.h>
using namespace std;

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
    // if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b]; sz[b] = 0;
    link[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    // Update primary 'sz' array and 'link' array
    sz.assign(N+1, 1);
    link.resize(N+1);
    for (int i=0; i<=N; i++) link[i] = i;

    // Create Edge List
    vector<array<int, 3>> edges;
    // edges.push_back({a, b, w});

    // Sort Edge List in ascending order by edge's weight
    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return a[2] < b[2];
    });

    // Execute Kruskal Algorithm
    int res = 0;
    int edge_num = 0;
    for (auto &[a, b, w] : edges) {
        if (same(a, b)) continue;
        res += w; 
        unite(a, b);

        if (++edge_num == N-1) break;
    }

    return 0;
}