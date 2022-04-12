#include <iostream>
#include <queue>

using namespace std;

int m, n, h;
int A[101][101][101], check[101][101][101];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool InRange(int z, int y, int x) {
	return (1 <= z && z <= h) &&
		(1 <= y && y <= n) &&
		(1 <= x && x <= m);
}

int main()
{

	queue<pair<int, pair<int, int>>> Q;
 
	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> A[k][i][j];
				check[k][i][j] = 987654321;
				if (A[k][i][j] == 1) { Q.push({ k, {i, j} }); check[k][i][j] = 0; }
			}
				
	while (!Q.empty())
	{
		int z = Q.front().first;
		int y = Q.front().second.first;
		int x = Q.front().second.second;
		Q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (InRange(nz, ny, nx) && A[nz][ny][nx] == 0)
			{
				check[nz][ny][nx] = min(check[nz][ny][nx], check[z][y][x] + 1);
				A[nz][ny][nx] = 1;
				Q.push({ nz, {ny, nx} });
			}
		}
	}

	int flag = true;
	int ans = -1;
	for (int k = 1; k <= h; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (A[k][i][j] == 0) flag = false;
				if (ans < check[k][i][j] && A[k][i][j] != -1) ans = check[k][i][j];
			}
	
	if (!flag) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}