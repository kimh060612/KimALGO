#include <iostream>
#include <vector>

using namespace std;

int n, m;
int H[5001], visited[5001], DP[5001];
vector<int> E[5001];

int max(int a, int b) { return a > b ? a : b; }

int dfs(int now)
{
	int &ret = DP[now];
	if (ret != 0) return ret;
	visited[now] = 1;

	ret = 1;
	for (int i = 0; i < E[now].size(); i++)
	{
		int nx = E[now][i];
		if (!visited[nx] && H[now] < H[nx])
		{
			ret = max(ret, dfs(nx) + 1);
		}
	}
	visited[now] = 0;
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> H[i];
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (DP[i] == 0) {
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << DP[i] << endl;
	return 0;
}