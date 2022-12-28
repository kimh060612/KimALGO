#include <iostream>
#define MOD 1000000007

using namespace std;

long long DP[1000001][2];

int main()
{
	int n;
	cin >> n;

	DP[1][0] = 2;
	DP[2][0] = 7;
	DP[2][1] = 1;

	for (int i = 3; i <= n; i++)
	{
		DP[i][1] = (DP[i - 1][1] + DP[i - 3][0]) % MOD;
		DP[i][0] = (3 * DP[i - 2][0] + 2 * DP[i - 1][0] + 2 * DP[i][1]) % MOD;
	}

	cout << DP[n][0] << endl;

	return 0;
}