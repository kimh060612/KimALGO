#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, A[51][51];
int DP[51][51];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool InRange(int y, int x) { return (1 <= y && y <= n) && (1 <= x && x <= n); }

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char s[51];
		cin >> s;
		for (int j = 1; j <= n; j++)
		{
			A[i][j] = s[j - 1] - '0';
			DP[i][j] = 987654321;
		}
	}

	queue<tuple<int, int, int>> Q;
	if (DP[1][1] == 0) { 
		Q.push({ 1, 1, 1 });
		DP[1][1] = 1;
	}
	else {
		Q.push({ 1, 1, 0 });
		DP[1][1] = 0;
	}

	int ans = 987654321;

	while (!Q.empty())
	{
		int y = get<0>(Q.front());
		int x = get<1>(Q.front());
		int cnt = get<2>(Q.front());
		Q.pop();

		if (y == n && x == n)
		{
			ans = min(ans, cnt);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (InRange(ny, nx))
			{
				if (A[ny][nx] == 0)
				{
					if (DP[ny][nx] > cnt + 1)
					{
						DP[ny][nx] = cnt + 1;
						Q.push({ ny, nx, cnt + 1 });
					}
				}
				else if (A[ny][nx] == 1) { 
					if (DP[ny][nx] > cnt)
					{
						DP[ny][nx] = cnt;
						Q.push({ ny, nx, cnt });
					}
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}