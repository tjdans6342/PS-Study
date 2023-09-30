// BOJ 13275
// Manacher Algorithm
// 가장 긴 팰린드롬 문자열의 길이를 O(n)에 판별하는 알고리즘
// - 현재 지점을 중심으로 하는 가장 긴 팰린드롬 문자열의 반지름을 저장(arr[i].r)하며 
// - 이를 이용하여 다음 지점 i을 살펴볼 때 그 지점이 dp_p(현재까지 살펴본 구역) 보다 작다면 
// - i의 대칭점(i')의 r(arr[i'].r)을 살펴보며 arr[i].r을 효율적으로 갱신하는 알고리즘이다.

#include <bits/stdc++.h>
using namespace std;

struct node {
    int r; // radius (현재 점 기준으로 가장 긴 반지름)
    int p; // preserve (지금까지 살펴본 구역(의 최대 인덱스))
    int c; // center (preserve에 해당하는 중심점 좌표 (처음엔 자기 자신 인덱스를 가짐))
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

        while ( (c-r >= 0 && c+r <= 2*n) && (s[c-r] == s[c+r]) ) r += 1;
        // (c-r >= 0 && c+r <= 2*n) : 문자열의 범위를 넘어가지 않아야 함
        // (s[c-r] == s[c+r]) : 팰린드롬이어야 하므로 문자가 같아야 함
        r -= 1;

        if (c+r > dp_p) tie(dp_p, dp_c) = make_pair(c+r, c); // 현재 지점에 의해서 dp_p와 dp_c가 갱신되었다면 갱신하기
        tie(p, c) = make_pair(dp_p, dp_c); // 지금까지 살펴 본 최대 구간 dp_p와 그때의 dp_c(중심점)을 p와 c에 갱신
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