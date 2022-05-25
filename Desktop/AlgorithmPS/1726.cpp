#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int A[101][101];
int visited[101][101][4];
int sx, sy, dir_s;
int ex, ey, dir_e;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dir_change[4][2] = {
	{3, 2},
	{2, 3},
	{0, 1},
	{1, 0}
};

bool InRange(int y, int x) { return (1 <= y && y <= m) && (1 <= x && x <= n); }

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];

	cin >> sy >> sx >> dir_s;
	cin >> ey >> ex >> dir_e;

	dir_s -= 1;
	dir_e -= 1;

	queue<tuple<int, int, int, int>> Q;
	Q.push(make_tuple(0, dir_s, sy, sx));
	visited[sy][sx][dir_s] = 1;

	int ans = 987654321;
	while (!Q.empty())
	{
		int cnt = get<0>(Q.front());
		int dir_now = get<1>(Q.front());
		int y = get<2>(Q.front());
		int x = get<3>(Q.front());
		Q.pop();
	
		if (y == ey && x == ex && dir_now == dir_e) {
			ans = cnt;
			break;
		}

		// 방향 전환
		int dir_1 = dir_change[dir_now][0];
		if (!visited[y][x][dir_1])
		{
			Q.push(make_tuple(cnt + 1, dir_1, y, x));
			visited[y][x][dir_1] = 1;
		}
			

		int dir_2 = dir_change[dir_now][1];
		if (!visited[y][x][dir_2])
		{
			Q.push(make_tuple(cnt + 1, dir_2, y, x));
			visited[y][x][dir_2] = 1;
		}
			

		// 1,2,3 칸씩 현재 방향으로 이동
		for (int k = 1; k <= 3; k++)
		{
			int ny = y + k * dy[dir_now];
			int nx = x + k * dx[dir_now];
			if (A[ny][nx] != 0) break;
			if (InRange(ny, nx) && !visited[ny][nx][dir_now])
			{
				Q.push(make_tuple(cnt + 1, dir_now, ny, nx));
				visited[ny][nx][dir_now] = 1;
			}
		}
	}

	cout << ans << endl;
	return 0;
}