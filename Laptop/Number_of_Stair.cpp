#include <iostream>
#define MOD 1000000000

using namespace std;

int N;
int DP[101][10][1 << 10];

int main()
{
	cin >> N;
	
	const int INF = (1 << 10) - 1;

	for (int j = 1; j <= 9; ++j)
		DP[1][j][1 << j] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= INF; ++k) {
				if (j == 0)
					DP[i][0][k | (1 << 0)] = (DP[i][0][k | (1 << 0)] + DP[i - 1][1][k]) % MOD;
				else if (j == 9)
					DP[i][9][k | (1 << 9)] = (DP[i][9][k | (1 << 9)] + DP[i - 1][8][k]) % MOD;
				else {
					DP[i][j][k | (1 << j)] = (DP[i][j][k | (1 << j)] + DP[i - 1][j - 1][k]) % MOD;
					DP[i][j][k | (1 << j)] = (DP[i][j][k | (1 << j)] + DP[i - 1][j + 1][k]) % MOD;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = (ans + DP[N][i][INF]) % MOD;
	}

	cout << ans % MOD << endl;
	return 0;
}