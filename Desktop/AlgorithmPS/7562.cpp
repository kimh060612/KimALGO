#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n;
int visited[301][301];

int dx[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int dy[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };

bool InRange(int y, int x) { return (0 <= y && y < n) && (0 <= x && x < n); }

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, 0, sizeof(visited));
		cin >> n;
		int sy, sx, ey, ex;
		cin >> sy >> sx;
		cin >> ey >> ex;

		queue<pair<int, pair<int, int>>> Q;
		Q.push({ 0, { sy, sx }});
		visited[sy][sx] = 1;

		int ans = 0;
		while (!Q.empty())
		{
			int cnt = Q.front().first;
			int y = Q.front().second.first;
			int x = Q.front().second.second;
			Q.pop();

			if (y == ey && x == ex) {
				ans = cnt;
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (InRange(ny, nx) && !visited[ny][nx])
				{
					visited[ny][nx] = 1;
					Q.push({ cnt + 1, {ny, nx} });
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}