#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll DP[100001];
vector<int> B[100001];

void dfs(int s)
{
	for (int i = 0; i < B[s].size(); i++)
	{
		int next = B[s][i];
		DP[next] += DP[s];
		dfs(next);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int t;
	cin >> t;
	for (int i = 2; i <= n; i++)
	{
		int a;
		cin >> a;
		B[a].push_back(i);
	}
	for (int i = 1; i <= m; i++)
	{
		int e, w;
		cin >> e >> w;
		DP[e] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++) cout << DP[i] << " ";
	cout << endl;
	return 0;
}