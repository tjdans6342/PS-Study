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

    // if (!same(a, b)) unite(a, b);

    return 0;
}