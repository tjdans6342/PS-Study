#include <bits/stdc++.h>
using namespace std;

int n, m; 

int search(vector<int> &v, int c, int sz) {
	int ret = 0;

	for (int i=0; i<sz; i++) {
		if (i == 0) {
			if (v[i] == c) ret++;
		} 
		else {
			if (v[i] == c && v[i-1] != c) ret++;
		}
	}

	return ret;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	int res = 0;
	for (int i=0; i<n; i++) {
		vector<vector<int>> parts;
		vector<int> v;
		for (int j=0; j<m; j++) {
			int x; cin >> x;
			if (x == 0) {
				if (!v.empty()) parts.push_back(v);
				v.clear();
			}
			else v.push_back(x);
		}
		if (!v.empty()) parts.push_back(v);

		for (auto &part: parts) {
			int sz = part.size();

			int case1 = 0;
			vector<int> v1(sz, 0);
			for (int  j=0; j<sz; j++) {
				if (part[j] == 2) v1[j] = 1; 
				else v1[j] = part[j];
			}		
			case1 += search(v1, 1, sz);
			case1 += search(part, 2, sz);

			int case2 = 0;
			vector<int> v2(sz, 0);
			for (int  j=0; j<sz; j++) {
				if (part[j] == 1) v2[j] = 2; 
				else v2[j] = part[j];
			}
			case2 += search(v2, 2, sz);
			case2 += search(part, 1, sz);

			res += min(case1, case2);
		}
	}

	cout << res << '\n';
	return 0;
}