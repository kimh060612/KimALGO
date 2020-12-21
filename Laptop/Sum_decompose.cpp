#include <iostream>
#define INF 201
#define MOD 1000000000

using namespace std;

int N, K;
int DP[INF][INF];

int main()
{

	cin >> N >> K;

	for (int i = 1; i <= N; i++)DP[i][1] = 1;
	for (int i = 1; i <= K; i++)DP[1][i] = i;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1])%MOD;
		}
	}

	cout << DP[N][K]%MOD << endl;

	return 0;
}