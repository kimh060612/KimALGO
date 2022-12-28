#include <iostream>

using namespace std;

int DP[10001][4];

int main()
{
	std::ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;

	DP[1][1] = 1;
	DP[2][1] = 1;
	DP[2][2] = 1;
	DP[3][1] = 1;
	DP[3][2] = 1;
	DP[3][3] = 1;

	for (int i = 4; i <= 10000; i++)
	{
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}

	while (t--)
	{
		int n;
		cin >> n;
		cout << DP[n][1] + DP[n][2] + DP[n][3] << "\n";
	}
	
	return 0;
}