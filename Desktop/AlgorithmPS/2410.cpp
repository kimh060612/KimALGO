#include <iostream>
#include <math.h>
#define INF 1000001
#define MOD 1000000000

using namespace std;

int n;
int DP[INF][30];

int main()
{
	cin >> n;

	for (int i = 0; i < 20; i++)DP[0][i] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i >= (1 << j))
			{
				DP[i][j] = (DP[i][j - 1] + DP[i - (1 << j)][j])%MOD;
			}
			else
			{
				DP[i][j] = DP[i][j - 1];
			}
		}
	}

	cout << DP[n][19] << endl;
}