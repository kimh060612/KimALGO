#include <iostream>
#define MOD 1000000009

using namespace std;

long long DP[100001][4];

int main()
{
	DP[1][1] = DP[2][2] = DP[3][1] = DP[3][2] = DP[3][3] = 1;
	for (int i = 4; i <= 100000; i++)
	{
		if (i - 1 >= 0) {
			DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % MOD;
		}
		if (i - 2 >= 0) {
			DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % MOD;
		}
		if (i - 3 >= 0) {
			DP[i][3] = (DP[i - 3][2] + DP[i - 3][1]) % MOD;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (DP[n][1] + DP[n][2] + DP[n][3]) % MOD << endl;
	}

	return 0;
}