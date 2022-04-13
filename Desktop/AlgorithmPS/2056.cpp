#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, Edge[10001], T[10001];
int DP[10001];
vector<int> P[10001];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t, m;
		cin >> t >> m;
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			P[x].push_back(i);
		}
		Edge[i] = m;
		T[i] = t;
		DP[i] = -1;
	}

	queue<pair<int, int>> Q;
	for (int i = 1; i <= n; i++)
	{
		if (Edge[i] == 0) { 
			Q.push({ i, T[i] });
			DP[i] = T[i];
		}
	}

	while (!Q.empty())
	{
		int x = Q.front().first;
		int t = Q.front().second;
		Q.pop();
		
		for (int i = 0; i < P[x].size(); i++)
		{
			int y = P[x][i];
			DP[y] = max(DP[y], T[y] + t);
			Edge[y] -= 1;
			if (Edge[y] == 0) {
				Q.push({ y, DP[y] });
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) ans = max(DP[i], ans);
	cout << ans << endl;
	return 0;
}