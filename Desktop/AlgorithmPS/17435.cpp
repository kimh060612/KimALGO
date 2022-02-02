#include <iostream>
#include <vector>
#include <cmath>
#define MAX (int)log2(500005)

using namespace std;

int F[200001];
vector<vector<int>> DP;
int m;

int fpow(int n, int x)
{
	for (int i = 0; i <= MAX; i++)
	{
		if (n & (1 << i)) x = DP[i][x];
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m;

	DP.resize(MAX + 1, vector<int>(m + 5));
	
	for (int i = 1; i <= m; i++)
	{
		cin >> F[i];
		DP[0][i] = F[i];
	}
	
	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			DP[i][j] = DP[i - 1][DP[i - 1][j]];
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		int n, x;
		cin >> n >> x;
		cout << fpow(n, x) << "\n";
	}

	return 0;
}