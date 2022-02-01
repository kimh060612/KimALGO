#include <iostream>
#include <string.h>

using namespace std;

int A[1001][1001], DP[1001][1001];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main()
{
	while (1)
	{
		int n, m;
		cin >> n >> m;
		memset(DP, 0, sizeof(DP));
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> A[i][j];
				DP[i][j] = A[i][j];
				if (A[i - 1][j] != 0 && A[i][j - 1] != 0 && A[i - 1][j - 1] != 0) {
					if (A[i][j] != 0)DP[i][j] = min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]) + 1;
				}
			}
		}
		int ans = -987654321;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans = max(ans, DP[i][j]);
				// cout << DP[i][j] << " ";
			}
			// cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}