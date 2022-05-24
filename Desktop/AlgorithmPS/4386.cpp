#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
pair<double, double> A[101];
tuple<double, int, int> E[10001];
int parent[101];

double distance(pair<double, double> a, pair<double, double> b)
{
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	if (x < y) {
		parent[x] = y; 
	}
	else {
		parent[y] = x; 
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cnt++;
			E[cnt] = make_tuple(distance(A[i], A[j]), i, j) ;
		}
	}
	sort(E + 1, E + cnt + 1);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	double ans = 0;
	for (int i = 1; i <= cnt; i++)
	{
		double w = get<0>(E[i]);
		int x = get<1>(E[i]);
		int y = get<2>(E[i]);

		if (find(x) != find(y))
		{
			Union(x, y);
			ans += w;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << endl;
	return 0;
}