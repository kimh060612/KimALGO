#include <iostream>
#include <algorithm>
#define n_ 106
#define INF 0x7fffffff
using namespace std;

int n, m;
int dp[n_][n_];
bool chk[n_];

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		chk[a] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) { //i번째 날 j개의 쿠폰
			if (dp[i][j] == INF)continue;
			int now = dp[i][j];

			if (chk[i + 1]) {
				dp[i + 1][j] = min(now, dp[i + 1][j]);
			}
			if (j >= 3) {
				dp[i + 1][j - 3] = min(dp[i + 1][j - 3], now);
			}
			dp[i + 1][j] = min(now + 10000, dp[i + 1][j]);
			for (int k = 1; k <= 3; k++) {
				dp[i + k][j + 1] = min(now + 25000, dp[i + k][j + 1]);
			}
			for (int k = 1; k <= 5; k++) {
				dp[i + k][j + 2] = min(now + 37000, dp[i + k][j + 2]);
			}
		}
	}

	int ans = INF;

	for (int i = 0; i < n; i++) {
		if (dp[n][i] < ans) {
			ans = dp[n][i];
		}
	}
	cout << ans;
}
