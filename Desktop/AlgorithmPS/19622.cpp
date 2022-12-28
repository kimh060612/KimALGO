#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> V;
int DP[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		V.push_back({ e, {s, t} });
	}

	sort(V.begin(), V.end());

	DP[1] = V[0].second.second;
	DP[2] = V[1].second.second;
	DP[3] = V[2].second.second + DP[1];

	for (int i = 4; i <= n; i++)
	{
		DP[i] = max(DP[i - 2], DP[i - 3]) + V[i - 1].second.second;
	}

	int ans = -987654321;
	for (int i = 1; i <= n; i++) ans = max(ans, DP[i]);

	cout << ans << endl;
	return 0;
}