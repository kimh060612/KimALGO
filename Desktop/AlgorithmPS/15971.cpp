#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, s, e;
int visited[100001];
vector<pair<int, int>> A[100001];
int DP[100001];

int main()
{
	cin >> n >> s >> e;
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		A[a].push_back({b, c});
		A[b].push_back({a, c});
	}

	queue<pair<int, int>> Q;
	vector<int> E;
	Q.push({ s, 0 });

	int ans = 0;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int k = Q.front().second;
		Q.pop();

		if (x == e)
			ans = k;
		visited[x] = 1;

		for (int i = 0; i < A[x].size(); i++)
		{
			int y = A[x][i].first;
			int w = A[x][i].second;
			if (!visited[y])
			{
				Q.push({ y, max(k, w) });
				DP[y] = DP[x] + w;
			}
		}

	}

	cout << DP[e] - ans << endl;

	return 0;
}