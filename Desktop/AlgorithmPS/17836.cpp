#include <iostream>
#include <queue>

using namespace std;

int n, m, t;
int A[101][101], s_y, s_x;
int Dist[101][101], visited[101][101];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0 , 0 };

bool InRange(int y, int x) { return (1 <= x && x <= m) && (1 <= y && y <= n); }

int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> A[i][j];
			if (A[i][j] == 2) {
				s_y = i;
				s_x = j;
			}
			Dist[i][j] = 987654321;
		}

	queue<pair<pair<int, int>, int>> Q;

	Q.push({ {1, 1}, 0 });
	Dist[1][1] = 0;

	while (!Q.empty()) 
	{
		int y = Q.front().first.first;
		int x = Q.front().first.second;
		int k = Q.front().second;
		Q.pop();

		Dist[y][x] = min(Dist[y][x], k);

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (InRange(ny, nx) && A[ny][nx] != 1 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				Q.push({ {ny, nx}, k + 1 });
			}
		}
	}
	
	int dist_p = Dist[n][m], dist_s = (Dist[s_y][s_x] + (n - s_y) + (m - s_x));
	int ans = dist_p < dist_s ? dist_p : dist_s;

	if (ans > t) cout << "Fail" << endl;
	else cout << ans << endl;

	return 0;
}