// BOJ 11238
// Fast Matrix Exponentation for Fibonacci Sequence

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

// GCD
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

// Fast Matrix Exponentation
array<array<ll, 2>, 2> basic = {1, 1, 1, 0};

array<array<ll, 2>, 2> mul(array<array<ll, 2>, 2> &a, array<array<ll, 2>, 2> &b) { // multiplication of 'a' and 'b'
	array<array<ll, 2>, 2> ret;

	ret[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
	ret[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
	ret[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
	ret[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;

	return ret;
}

array<array<ll, 2>, 2> mpow(array<array<ll, 2>, 2> &m, ll n) { // The 'n'th power of matrix 'm'
	if (n == 1) return basic;

    auto ret = mpow(m, n/2);
	ret = mul(ret, ret);
	if (n%2 == 1) ret = mul(ret, basic);

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int tc; cin >> tc;
	while (tc--) {
		ll a, b; cin >> a >> b;
		ll n = gcd(a, b);

		auto ans = mpow(basic, n);
		cout << ans[0][1] << '\n';
	}

	return 0;
}