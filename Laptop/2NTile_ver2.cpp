#include <iostream>
#define MOD 10007

using namespace std;

int DP[1001];

int main()
{
	int N;
	cin >> N;

	DP[1] = 1;
	DP[2] = 3;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] * 2)%MOD;
	}

	cout << DP[N] % MOD << endl;

	return 0;
}