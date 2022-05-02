#include <iostream>

using namespace std;

int n, m;
int A[1001][1001];
int DP[4][1001][1001];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> A[i][j];
		}
			
	for (int j = 1; j <= m; j++)
		for (int k = 1; k <= 3; k++)
			DP[k][1][j] = A[1][j];

	for (int i = 2; i <= n; i++)
	{
		DP[1][i][1] = min(DP[2][i - 1][2], DP[3][i - 1][2]) + A[i][1];
		DP[2][i][1] = DP[1][i - 1][1] + A[i][1];
		DP[3][i][1] = 0x7fffffff;
		for (int j = 2; j < m; j++)
		{
			DP[1][i][j] = min(DP[2][i - 1][j + 1], DP[3][i - 1][j + 1]) + A[i][j];
			DP[2][i][j] = min(DP[1][i - 1][j], DP[3][i - 1][j]) + A[i][j];
			DP[3][i][j] = min(DP[2][i - 1][j - 1], DP[1][i - 1][j - 1]) + A[i][j];
		}
		DP[1][i][m] = 0x7fffffff;
		DP[2][i][m] = DP[3][i - 1][m] + A[i][m];
		DP[3][i][m] = min(DP[2][i - 1][m - 1], DP[1][i - 1][m - 1]) + A[i][m];
	}

	int ans = 0x7fffffff;
	for (int k = 1; k <= 3; k++)
		for (int j = 1; j <= m; j++)
			ans = min(ans, DP[k][n][j]);

	std::cout << ans << endl;

	return 0;
}