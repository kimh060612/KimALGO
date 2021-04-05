#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define int int64_t
int cnt[1 << 10];

int32_t main() {
	fastio;
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int t = 0;
		for (const auto& i : s) t |= 1 << (i & 15);
		cnt[t]++;
	}
	for (int i = 0; i < 1 << 10; i++) for (int j = 0; j < 1 << 10; j++) {
		if (i & j) ans += cnt[i] * cnt[j];
	}
	cout << (ans - n >> 1) << '\n';
    
}