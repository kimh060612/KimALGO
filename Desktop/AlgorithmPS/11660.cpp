#include <iostream>

using namespace std;

int A[1025][1025], DP[1026][1026];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += A[i][1];
		DP[i][1] = sum;
	}

	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += A[1][i];
		DP[1][i] = sum;
	}

	for (int i = 2; i <= n + 1; i++)
	{
		for (int j = 2; j <= n + 1; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + A[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && y1 == y2) {
			cout << A[x1][y1] << "\n";
		}
		else {
			int area = DP[x2 + 1][y2 + 1] - DP[x2 + 1][y1] - DP[x1][y2 + 1] + DP[x1][y1];
			cout << area << "\n";
		}
	}

	return 0;
}