#include <iostream>
#include <string.h>

using namespace std;

int DP[30][10001], A[30];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		cin >> m;
		memset(DP, 0, sizeof(DP));

		for (int i = 1; i <= n; i++) DP[i][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (j >= A[i]) DP[i][j] = DP[i][j - A[i]] + DP[i - 1][j];
				else DP[i][j] = DP[i - 1][j];
			}
		}
		cout << DP[n][m] << endl;
	}
	return 0;
}