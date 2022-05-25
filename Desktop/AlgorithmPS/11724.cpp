#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> E[1001];
int visited[1001];

void BFS(int x)
{
	queue<int> Q;
	Q.push(x);
	visited[x] = 1;

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();

		for (int i = 0; i < E[now].size(); i++)
		{
			int nx = E[now][i];
			if (!visited[nx]) {
				Q.push(nx);
				visited[nx] = 1;
			}
		}
	}
}

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

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{ 
		if (!visited[i])
		{
			BFS(i);
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}