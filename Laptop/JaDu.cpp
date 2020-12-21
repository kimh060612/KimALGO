#include <iostream>
#include <fstream>
#define INF 1001
#define max(a, b) a > b ? a : b

using namespace std;

int T, W;
int A[INF];
int DP[3][INF][32];

int main()
{
	cin >> T >> W;

	for (int i = 1; i <= T; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= T; i++)
	{
		for (int j = 1; j <= W+1; j++)
		{
			if (A[i] == 1)
			{
				DP[1][i][j] = max(DP[1][i - 1][j] + 1, DP[2][i - 1][j - 1] + 1);
				DP[2][i][j] = max(DP[1][i - 1][j - 1], DP[2][i - 1][j]);
			}
			else
			{
				if (i == 1 && j == 1)continue;
				DP[1][i][j] = max(DP[1][i - 1][j], DP[2][i - 1][j - 1]);
				DP[2][i][j] = max(DP[1][i - 1][j - 1] + 1, DP[2][i - 1][j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= W + 1; i++)
	{
		if (DP[1][T][i] > DP[2][T][i])
		{
			if (DP[1][T][i] > ans) ans = DP[1][T][i];
		}
		else
		{
			if (DP[2][T][i] > ans) ans = DP[2][T][i];
		}
	}

	cout << ans << endl;

	return 0;
}