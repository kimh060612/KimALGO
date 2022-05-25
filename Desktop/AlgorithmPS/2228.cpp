#include <iostream>

using namespace std;

int sum[101], DP[101][101];

int max(int a, int b) { return a > b ? a : b; }

int main()
{

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		int x;
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}

	for (int i = 1; i <= m; i++) DP[0][i] = -32768 * 100;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			DP[i][j] = DP[i - 1][j];
			for (int k = 1; k <= i; k++)
			{
				if (k >= 2)DP[i][j] = max(DP[i][j], DP[k - 2][j - 1] + sum[i] - sum[k - 1]);
				else if (k == 1 && j == 1) DP[i][j] = max(DP[i][j], sum[i]);
			}
		}
	}

	cout << DP[n][m] << endl;

	return 0;
}