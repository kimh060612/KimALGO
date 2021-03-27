#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, a[51], ans =0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		ll left = i - 1;
		ll right = i + 1;
		ll cnt = 0;
		for (int j = i-1; j >-1; j--) {
			if (j == i - 1) {
				cnt += 1;
				continue;
			}
			ll d1 = (i - j);
			ll h1 = (a[i] - a[j]);
			ll d2 = (i - left);
			ll h2 = (a[i] - a[left]);
			// h1/d1 < h2/d2 여야 보임
			if (h1 * d2 < h2 * d1) {
				left = j;
				cnt += 1;
			}
		}
		for (int j = i + 1; j < n; j++) {
			if (j == i + 1) {
				cnt += 1;
				continue;
			}
			ll d1 = (i - j);
			ll h1 = (a[i] - a[j]);
			ll d2 = (i - right);
			ll h2 = (a[i] - a[right]);
			// h1/d1 > h2/d2 여야 보임
			if (h1 * d2 > h2 * d1) {
				right = j;
				cnt += 1;
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans;
}