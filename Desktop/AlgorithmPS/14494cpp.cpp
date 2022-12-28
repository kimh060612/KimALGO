#include <iostream>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll D[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) D[i][1] = 1;
	for (int i = 1; i <= m; i++) D[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			D[i][j] = (D[i - 1][j] + D[i][j - 1] + D[i - 1][j - 1]) % MOD;
		}
	}

	cout << D[n][m] << endl;

	return 0;
}