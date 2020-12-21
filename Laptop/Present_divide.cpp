#include <iostream>
#define MOD 1000000000
#define INF 1000001

using namespace std;

int N;
long long DP[INF];

int main()
{
	cin >> N;

	DP[0] = 0;
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 2;

	for (int i = 4; i <= N; i++)
	{
		DP[i] = ((i - 1)*(DP[i - 1] + DP[i - 2]) % MOD);
	}

	cout << DP[N]%MOD << endl;

	return 0;
}