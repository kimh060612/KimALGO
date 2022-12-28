#include <iostream>
#include <string>
#define MOD 1000000009

using namespace std;
typedef long long ll;

int n, m;
int A[3001][3001];
ll DP[3001][3001];

bool InRange(int y, int x) { return (1 <= y && y <= n) && (1 <= x && x <= m); }

ll dfs(int y, int x)
{
	if (y == n && x == m) return 1;
	ll &ret = DP[y][x];
	if (ret != -1) return ret;

	ret = 0;
	if (A[y][x] == 1) 
		ret = dfs(y, x + 1);
	else if (A[y][x] == 2)
		ret = dfs(y + 1, x);
	else if (A[y][x] == 3)
		ret = (dfs(y + 1, x) + dfs(y, x + 1)) %  MOD;

	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'E') A[i][j + 1] = 1;
			else if (s[j] == 'S') A[i][j + 1] = 2;
			else if (s[j] == 'B') A[i][j + 1] = 3;
			else if (s[j] == 'X') A[i][j + 1] = 4;
			DP[i][j + 1] = -1;
		}
	}
	DP[n][m] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (DP[i][j] == -1) {
				dfs(i, j);
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = (ans + DP[i][j]) % MOD;
	cout << ans << endl;
	return 0;
}