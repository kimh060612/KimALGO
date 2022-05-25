#include <iostream>
#include <algorithm>

using namespace std;

int T, k, DP[101][10001];
pair<int, int> A[101];

int main()
{
	cin >> T >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> A[i].first >> A[i].second;
	}

	sort(A + 1, A + 1 + k);

	for (int i = 1; i <= k; i++)
	{
		DP[0][i - 1] = 1;
		for (int j = 0; j <= A[i].second; j++)
		{
			for (int k = 0; k <= T; k++)
			{
				if (k + A[i].first * j > T) break;
				DP[i][k + A[i].first * j] += DP[i - 1][k];
			}
		}
	}

	//for (int i = 1; i <= k; i++)
	//{
	//	for (int j = 1; j <= t; j++) cout << dp[i][j] << " ";
	//	cout << endl;
	//}

	cout << DP[k][T] << endl;

	return 0;
}