#include <iostream>
#define MOD 1000000007

using namespace std;

int DP[2][1516][3];

int main()
{
	int n;
	cin >> n;

	DP[1][1][2] = 1;
	DP[1][2][0] = 1;
	DP[1][2][1] = 1;
	
	DP[0][1][1] = 1;
	DP[0][2][0] = 1;
	DP[0][2][2] = 1;

	for (int i = 3; i <= n; i++)
	{
		DP[1][i][0] = (DP[1][i - 1][1] + DP[0][i - 1][1]) % MOD;
		DP[1][i][1] = (DP[1][i - 1][2] + DP[0][i - 1][2]) % MOD;
		DP[1][i][2] = (DP[1][i - 1][0] + DP[0][i - 1][0]) % MOD;


		DP[0][i][0] = (DP[1][i - 1][2] + DP[0][i - 1][2]) % MOD;
		DP[0][i][1] = (DP[1][i - 1][0] + DP[0][i - 1][0]) % MOD;
		DP[0][i][2] = (DP[1][i - 1][1] + DP[0][i - 1][1]) % MOD;
	}

	cout << DP[1][n][0] << endl;
	return 0;
}