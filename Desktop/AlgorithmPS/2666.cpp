#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int n, m, a, b;
int v[22];
int dp[22][22][22];

int min(int a, int b) { return a < b ? a : b; }

int f(int idx, int a, int b) {
	int &res = dp[idx][a][b];
	if (res != -1) return res;
	if (idx > m) return res = 0;
	int t1 = f(idx + 1, v[idx], b) + abs(a - v[idx]);
	int t2 = f(idx + 1, a, v[idx]) + abs(b - v[idx]);
	return res = min(t1, t2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> m;
	for (int i = 1; i <= m; i++) cin >> v[i];
	memset(dp, -1, sizeof dp);
	cout << f(1, a, b);
}