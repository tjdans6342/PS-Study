#include <bits/stdc++.h>
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    vector<int> v(n+1, -1);
    for (int i=1; i<=n; i++) cin >> v[i];

    int res = 0;
    for (int i=1; i<=n; i++) {
        if (v[i] >= v[i-1]) res++;
    }

    cout << res << '\n';
    return 0;
}