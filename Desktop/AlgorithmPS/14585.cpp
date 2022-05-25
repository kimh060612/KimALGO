#include <iostream>

using namespace std;

int n, m, A[350][350], DP[350][350];

int max(int a, int b) { return a > b ? a : b;  }

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		A[x][y] = 1;
	}

	for (int i = 0; i <= 300; i++)
	{
		for (int j = 0; j <= 300; j++)
		{
			if (i == 0 && j == 0) continue;
			if (i == 0) {
				if (A[i][j])DP[i][j] = max(0, m - (i + j)) + DP[i][j - 1];
				else DP[i][j] = DP[i][j - 1];
			}
			else if (j == 0) {
				if (A[i][j])DP[i][j] = max(0, m - (i + j)) + DP[i - 1][j];
				else DP[i][j] = DP[i - 1][j];
			}
			else {
				if (A[i][j])DP[i][j] = max(0, m - (i + j)) + max(DP[i - 1][j], DP[i][j - 1]);
				else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[300][300] << endl;

	return 0;
}