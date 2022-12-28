#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
vector<int> E[10001];
int visited[10001];

int max(int a, int b) { return a > b ? a : b; }

bool compare(const pair<int, int> &i, const pair<int, int> &j)
{
	if (i.first == j.first) return i.second < j.second;
	else return i.first > j.first;
}

int dfs(int x)
{
	int res = 1;
	visited[x] = 1;
	for (int i = 0; i < E[x].size(); i++)
	{
		if (!visited[E[x][i]]) res += dfs(E[x][i]);
	}
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		E[b].push_back(a);
	}

	int ans = -1;
	vector<pair<int, int>> A;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		int k = dfs(i);
		A.push_back({k, i});
	}
	sort(A.begin(), A.end(), compare);

	for (int i = 0; i < A.size(); i++)
	{
		if (A[0].first == A[i].first) cout << A[i].second << " ";
		else break;
	}
	cout << endl;
	return 0;
}