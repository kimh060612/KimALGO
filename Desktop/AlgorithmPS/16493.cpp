#include <iostream>

using namespace std;

int A[30][3], DP[30][300];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> A[i][1] >> A[i][2];
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j >= A[i][1]) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - A[i][1]] + A[i][2]);
			else DP[i][j] = DP[i - 1][j];
		}
	}
	cout << DP[m][n] << endl;

	return 0;
}