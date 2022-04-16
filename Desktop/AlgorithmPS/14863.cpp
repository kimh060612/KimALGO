#include <iostream>

using namespace std;

int n, k;
pair<int, int> Time[101];
pair<int, int> Cost[101];
int DP[101][100001];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> Time[i].first >> Cost[i].first >> Time[i].second >> Cost[i].second;
	}

	DP[1][Time[1].first] = Cost[1].first;
	DP[1][Time[1].second] = max(DP[1][Time[1].second], Cost[1].second);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (DP[i - 1][j] == 0) continue;
			else {
				if (j + Time[i].first <= k) DP[i][j + Time[i].first] = max(DP[i][j + Time[i].first], DP[i - 1][j] + Cost[i].first);
				if (j + Time[i].second <= k) DP[i][j + Time[i].second] = max(DP[i][j + Time[i].second], DP[i - 1][j] + Cost[i].second);
			}
		}
	}

	int ans = -1;
	for (int j = 1; j <= k; j++) ans = max(DP[n][j], ans);

	cout << ans << endl;

	return 0;
}