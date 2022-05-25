#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m;
int A[51][51], visited[51][51];

int dx[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

bool InRange(int y, int x) { return (1 <= y && y <= n) && (1 <= x && x <= m); }

void BFS(int y, int x)
{
	queue<pair<int, int>> Q;
	Q.push({y, x});
	visited[y][x] = 1;

	while (!Q.empty())
	{
		int y_ = Q.front().first;
		int x_ = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y_ + dy[i];
			int nx = x_ + dx[i];
			if (InRange(ny, nx) && !visited[ny][nx] && A[ny][nx] == 1)
			{
				visited[ny][nx] = 1;
				Q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	while (1)
	{
		cin >> m >> n;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> A[i][j];
		memset(visited, 0, sizeof(visited));

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!visited[i][j] && A[i][j] == 1) {
					BFS(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}