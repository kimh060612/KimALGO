#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
int M[1001], W[1001];
int DP[1001][1001];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> M[i];
	for (int i = 1; i <= m; i++) cin >> W[i];
	sort(M + 1, M + n + 1);
	sort(W + 1, W + m + 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j) DP[i][j] = DP[i - 1][j - 1] + abs(M[i] - W[j]);
			else if (i > j)
				DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - 1] + abs(M[i] - W[j]));
			else if (i < j)
				DP[i][j] = min(DP[i][j - 1], DP[i - 1][j - 1] + abs(M[i] - W[j]));
		}
	}
	cout << DP[n][m] << endl;
	return 0;
}