#include <iostream>

using namespace std;
typedef long long ll;

int A[1001], B[1001];
ll DP[1001][10001];

ll max(ll a, ll b) { return a > b ? a : b; }

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> A[i] >> B[i];
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j >= B[i])DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - B[i]] + A[i]);
			else DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[k][n] << endl;

	return 0;
}