#include <iostream>

using namespace std;

int h, w;
int A[301][301], DP[301][301], visit[301][301];

int max(int a, int b) { return a > b ? a : b; }

int dfs(int y, int x)
{
	if (x > w || y > h) return 0;
	
	if (DP[y][x] != -1) return DP[y][x];

	visit[y][x] = 1;
	if (x == w && y == h) return A[h][w];

	DP[y][x] = max(dfs(y, x + 1), dfs(y + 1, x)) + A[y][x];
	
	visit[y][x] = 0;
	return DP[y][x];
}

int main()
{
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> A[i][j];
			DP[i][j] = -1;
		}
	}

	cout << dfs(1, 1) << endl;

	return 0;
}