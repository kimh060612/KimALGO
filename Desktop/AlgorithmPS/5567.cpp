#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> E[501];
int dist[501];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	queue<int> Q;
	Q.push(1);
	dist[1] = -1;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i = 0; i < E[x].size(); i++)
		{
			int nx = E[x][i];
			if (dist[nx] == 0) {
				Q.push(nx);
				dist[nx] = dist[x] != -1 ? dist[x] + 1 : 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 1 || dist[i] == 2) ans++;
	}

	cout << ans << endl;
	return 0;
}