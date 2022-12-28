#include <iostream>
#include <string.h>

using namespace std;

int DP[100][1001], A[100];
int N, S, M;

int max(int a, int b) { return a > b ? a : b; }

int maxVol(int n, int p)
{
	if (n == N + 1) return p;
	if (DP[n][p] != -1) return DP[n][p];
	if (p < 0 || p > M) return -100;
	int mp = p - A[n];
	int pp = p + A[n];

	int ret = -100;
	if (mp >= 0) ret = max(ret, maxVol(n + 1, mp));
	if (pp <= M) ret = max(ret, maxVol(n + 1, pp));

	DP[n][p] = ret;
	return DP[n][p];
}

int main()
{
	
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	memset(DP, -1, sizeof(DP));

	int ans = maxVol(1, S);

	if (ans == -100) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}