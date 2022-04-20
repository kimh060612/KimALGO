#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, m, k;
int A[51][51], visited[51][51];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 ,0 ,1, -1 };

bool InRange(int y, int x) { return (0 <= y && y < n) && (0 <= x && x < m); }

void BFS(int sy, int sx)
{
	queue<pair<int, int>> Q;
	Q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (InRange(ny, nx) && !visited[ny][nx] && A[ny][nx] == 1) {
				visited[ny][nx] = 1;
				Q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		memset(A, 0, sizeof(A));
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= k; i++)
		{
			int y, x;
			cin >> x >> y;
			A[y][x] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (A[i][j] == 1 && !visited[i][j])
				{
					BFS(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}