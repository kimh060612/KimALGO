#include <iostream>

using namespace std;
typedef long long ll;

ll N, M, arr[15][100005], DP[15][100005], ans;

ll max(ll a, ll b) { return a > b ? a : b; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ll tmp = 0;
			for (int k = 1; k <= M; k++) {
				if (i != 1 && j == k)
					tmp = max(DP[k][i - 1] + arr[j][i] / 2, tmp);
				else
					tmp = max(DP[k][i - 1] + arr[j][i], tmp);
			}
			DP[j][i] = tmp;
		}
	}
	for (int i = 1; i <= M; i++)
		ans = max(DP[i][N], ans);
	cout << ans;
	return 0;
}