#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int A[101][101], visited[101][101], B[101][101], C[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;

bool InRange(int y, int x) { return (1 <= y && y <= n) && (1 <= x && x <= m); }

void BFS(int y, int x)
{
	if (visited[y][x]) return;

	queue <pair<int, int>> Q;
	Q.push({y, x});
	visited[y][x] = 1;

	while (!Q.empty())
	{
		int now_y = Q.front().first;
		int now_x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (InRange(ny, nx) && !visited[ny][nx] && B[ny][nx] == 0) {
				Q.push({ny, nx});
				visited[ny][nx] = 1;
			}
			if (InRange(ny, nx) && B[ny][nx] == 1) {
				C[ny][nx] += 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> A[i][j];
			B[i][j] = A[i][j];
		}
	
	int t = 1;
	while (1)
	{
		memset(visited, 0, sizeof(visited));
		memset(C, 0, sizeof(C));
		BFS(1, 1);

		bool flag = false;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (B[i][j] == 1 && C[i][j] >= 2) {
					B[i][j] = 0;
				}
				if (B[i][j] == 1) flag = true;
			}
		}

		if (!flag) break;

		t++;
	}
		
	cout << t << endl;
	return 0;
}