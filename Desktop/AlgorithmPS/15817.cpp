#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, x;
int len[101];
int cnt[101];
int dp[101][10001];  // dp[i][j] -> i번째 파이프를 써서 길이 j를 만들 수 있는 경우

int go(int idx, int length)
{
	if (length == x)
		return 1;
	if (length > x) return 0;
	if (idx == n) return 0;
	int& ret = dp[idx][length];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int num = 0; num <= cnt[idx]; ++num)
		ret += go(idx + 1, length + len[idx] * num);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> len[i] >> cnt[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = -1;
		}
	}
	cout << go(0, 0);
}