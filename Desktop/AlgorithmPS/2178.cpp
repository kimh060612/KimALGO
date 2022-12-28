#include <iostream>
#include <queue>
#define MAX 101
#define INF 987654321

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int A[MAX][MAX];
int DP[MAX][MAX];
int check[MAX][MAX];
int N, M;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		char tmp[101];
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			A[i][j + 1] = tmp[j] - '0';
			DP[i][j + 1] = INF;
		}
	}

	queue<pair<int, int>> Q;
	Q.push(make_pair(1, 1));
	DP[1][1] = 1;
	check[1][1] = 1;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (A[ny][nx] && !check[ny][nx])
			{
				check[ny][nx] = 1;
				DP[ny][nx] = min(DP[y][x] + 1, DP[ny][nx]);
				Q.push(make_pair(nx, ny));
			}
		}
	}

	cout << DP[N][M] << endl;

	return 0;
}