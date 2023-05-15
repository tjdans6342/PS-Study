// BOJ 13275
// Manacher Algorithm

#include <bits/stdc++.h>
using namespace std;

struct node {
    int r; // radius
    int p; // preserve
    int c; // center
};

vector<node> manacher(string s) {
    int n = size(s);
    s.resize(2*n+1);

    s[2*n] = '#';
    for (int i=n-1; i>=0; i--) {
        s[2*i+1] = s[i];
        s[2*i] = '#';
    }

    vector<node> ret(2*n+1, {0, 0, 0});
    for (int i=0; i<=2*n; i++) ret[i].c = i;
    int dp_p = -1;
    int dp_c = 0;

    for (auto &[r, p, c] : ret) {
        if (c <= dp_p) {
            int cor_r = ret[2*dp_c-c].r;
            r = min(dp_p-c, cor_r);
        }
        else r = 0;

        while ( (c-r >= 0 && c+r <= 2*n) && (s[c-r] == s[c+r]) ) r++;
        r--; p = c+r;

        if (p > dp_p) {
            tie(dp_p, dp_c) = make_pair(p, c);
        }   
    }

    return ret;
}

int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;
    auto arr = manacher(s);

    int ans = 0;
    for (auto &[r, p, c] : arr) {
        if (c%2 == 0) ans = max(ans, r);
        if (c%2 == 1) ans = max(ans, r);
    }

    cout << ans << '\n';
    return 0;
}