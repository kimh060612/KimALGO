#include <iostream>

using namespace std;

int N;
int tri[501][501], DP[501][501];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}

	DP[1][1] = tri[1][1];
	for (int i = 2; i <= N; i++)
	{
		DP[i][1] = DP[i - 1][1] + tri[i][1];
		for (int j = 2; j <= i - 1; j++)
		{
			DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + tri[i][j];
		}
		DP[i][i] = DP[i - 1][i - 1] + tri[i][i];
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) ans = max(ans, DP[N][i]);
	cout << ans << endl;
	return 0;
}