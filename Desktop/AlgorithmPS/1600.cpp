#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int w, h, k;
int A[201][201], visited[201][201][50];
 
int dx[12] = { 1, -1, 1, -1, 2, -2, 2, -2, 1, -1, 0, 0 };
int dy[12] = { 2, 2, -2, -2, 1, 1, -1, -1, 0, 0, 1, -1 };

bool InRange(int y, int x) { return (1 <= y && y <= h) && (1 <= x && x <= w); }

int main()
{
	cin >> k >> w >> h;
	
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> A[i][j];

	queue<tuple<int, int, int, int>> Q;
	Q.push({0, 0, 1, 1});
	visited[1][1][0] = 1;

	int ans = -1;

	while (!Q.empty())
	{
		int cnt = get<0>(Q.front());
		int _k = get<1>(Q.front());
		int y = get<2>(Q.front());
		int x = get<3>(Q.front());
		Q.pop();

		if (y == h && x == w) {
			ans = cnt;
			break;
		}

		if (_k < k) {
			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (InRange(ny, nx) && !visited[ny][nx][_k + 1] && A[ny][nx] == 0)
				{
					Q.push({ cnt + 1, _k + 1, ny, nx });
					visited[ny][nx][_k + 1] = 1;
				}
			}
		}
		
		for (int i = 8; i < 12; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (InRange(ny, nx) && !visited[ny][nx][_k] && A[ny][nx] == 0)
			{
				Q.push({ cnt + 1, _k, ny, nx });
				visited[ny][nx][_k] = 1;
			}
		}
	}

	cout << ans << endl;
 	return 0;
}