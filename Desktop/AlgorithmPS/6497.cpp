#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int> &parent, int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

bool findParent(vector<int> &parent, int x, int y)
{
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x == y) return true;
	else return false;
}

void unionParent(vector<int> &parent, int x, int y)
{
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		vector<pair<int, pair<int, int>>> A;
		vector<int> parent;
		parent.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) parent[i] = i;
		int sum = 0;
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			A.push_back({ z, {x, y} });
			sum += z;
		}
		sort(A.begin(), A.end());

		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			int z = A[i].first;
			int x = A[i].second.first;
			int y = A[i].second.second;

			if (!findParent(parent, x, y))
			{
				unionParent(parent, x, y);
				ans += z;
			}
		}
		cout << sum - ans << endl;
	}
	return 0;
}