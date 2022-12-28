#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m;
int A[51][51], visited[51][51], DP[51][51];

int dx[4] = { 1, -1 ,0 ,0 };
int dy[4] = { 0, 0, 1, -1 };

bool InRange(int y, int x) { return (1 <= y && y <= n) && (1 <= x && x <= m); }
int max(int a, int b) { return a > b ? a : b; }

void bfs(int _y, int _x)
{
	queue<pair<int, int>> Q;
	Q.push({ _y, _x });
	visited[_y][_x] = 1;
	DP[_y][_x] = 0;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!visited[ny][nx] && A[ny][nx] == 1 && InRange(ny, nx))
			{
				Q.push({ny, nx});
				DP[ny][nx] = DP[y][x] + 1;
				visited[ny][nx] = 1;
			}
		}

	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char s[55];
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'L') A[i][j + 1] = 1;
			else A[i][j + 1] = 0;
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i][j])
			{
				memset(visited, 0, sizeof(visited));
				memset(DP, 0, sizeof(DP));
				bfs(i, j);
				for (int y = 1; y <= n; y++)
					for (int x = 1; x <= m; x++)
						ans = max(ans, DP[y][x]);
			}
		}
	}

	cout << ans << endl;
	return 0;
}