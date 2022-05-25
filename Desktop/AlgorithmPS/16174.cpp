#include <iostream>
#include <string.h>

using namespace std;

int A[65][65], DP[65][65];
int visited[65][65];
int n;

int dfs(int y, int x)
{
	if (y == n && x == n) return 1;
	if (DP[y][x] != -1) return DP[y][x];

	visited[y][x] = 1;
	int dx = A[y][x];
	int ret_1 = 0, ret_2 = 0;
	if (x + dx <= n && !visited[y][x + dx]) ret_1 = dfs(y, x + dx);
	if (y + dx <= n && !visited[y + dx][x]) ret_2 = dfs(y + dx, x);
	DP[y][x] = ret_1 || ret_2 ? 1 : 0;
	visited[y][x] = 0;
	return DP[y][x];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
		}
	}

	memset(DP, -1, sizeof(DP));
	int res = dfs(1, 1);

	if (res) cout << "HaruHaru" << endl;
	else cout << "Hing" << endl;
	return 0;
}