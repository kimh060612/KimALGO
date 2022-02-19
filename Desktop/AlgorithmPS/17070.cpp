#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int A[20][20], DP[20][20][3], visited[20][20];
int n;

int direction(int dy, int dx)
{
	if (dy == 0 && dx == 1) return 0;
	else if (dy == 1 && dx == 0) return 1;
	else if (dy == 1 && dx == 1) return 2;
	else return -1;
}

int dfs(int sy, int sx, int ey, int ex, int dir)
{
	if (ey == n && ex == n) return 1;
	if (DP[ey][ex][dir] != -1) return DP[ey][ex][dir];

	visited[ey][ex] = 1;

	int ret = 0;
	if (!A[ey][ex + 1] && ex + 1 <= n && (dir == 0 || dir == 2) && !visited[ey][ex + 1])
		ret += dfs(ey, ex, ey, ex + 1, 0);
	if (!A[ey + 1][ex] && ey + 1 <= n && (dir == 1 || dir == 2) && !visited[ey + 1][ex])
		ret += dfs(ey, ex, ey + 1, ex, 1);
	if (!A[ey + 1][ex] && !A[ey][ex + 1] && !A[ey + 1][ex + 1] && ey + 1 <= n && ex + 1 <= n && !visited[ey + 1][ex + 1])
		ret += dfs(ey, ex, ey + 1, ex + 1, 2);
	DP[ey][ex][dir] = ret;
	visited[ey][ex] = 0;

	return DP[ey][ex][dir];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
			for (int k = 0; k < 3; k++)DP[i][j][k] = -1;
		}
	}
	visited[1][1] = 1;
	visited[1][2] = 1;
	DP[n][n][0] = 1;
	DP[n][n][1] = 1;
	DP[n][n][2] = 1;

	int ans = dfs(1, 1, 1, 2, 0);
	
	if (ans == -1)cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}