#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> E[101];
int visited[101];

int main()
{
	int x, y;
	cin >> n;
	cin >> x >> y;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	queue<pair<int, int>> Q;
	Q.push({0, x});
	visited[x] = 1;

	int ans = -1;
	while (!Q.empty())
	{
		int k = Q.front().first;
		int now = Q.front().second;
		Q.pop();

		if (now == y) {
			ans = k;
			break;
		}

		for (int i = 0; i < E[now].size(); i++)
		{
			int nx = E[now][i];
			if (!visited[nx]) {
				Q.push({k + 1, nx});
				visited[nx] = 1;
			}
		}
	}

	cout << ans << endl;
	return 0;
}