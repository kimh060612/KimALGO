#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> E[100001];
int parent[100001], visited[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	queue<int> Q;
	Q.push(1);
	parent[1] = -1;
	visited[1] = 1;

	while (!Q.empty()) 
	{
		int x = Q.front();
		Q.pop();

		for (int i = 0; i < E[x].size(); i++)
		{
			int nx = E[x][i];
			if (!visited[nx]) {
				visited[nx] = 1;
				parent[nx] = x;
				Q.push(nx);
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}