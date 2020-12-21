#include <iostream>
#define MOD 9901
#define INF 100001

using namespace std;

int N;
int DP[INF][3];

int main()
{
	cin >> N;

	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;

	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % MOD;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % MOD;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
	}

	cout << (DP[N][0] + DP[N][1] + DP[N][2])%MOD << endl;

	return 0;

}