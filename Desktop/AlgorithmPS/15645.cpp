#include <iostream>
#include <string.h>

using namespace std;

int A[100001][4], DP[100001][4];

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i][1] >> A[i][2] >> A[i][3];
	}

	DP[1][1] = A[1][1];
	DP[1][2] = A[1][2];
	DP[1][3] = A[1][3];

	for (int i = 2; i <= n; i++)
	{
		DP[i][1] = max(DP[i - 1][1], DP[i - 1][2]) + A[i][1];
		DP[i][2] = max(max(DP[i - 1][1], DP[i - 1][2]), DP[i - 1][3]) + A[i][2];
		DP[i][3] = max(DP[i - 1][2], DP[i - 1][3]) + A[i][3];
	}

	int max_ = -987654321;
	for (int j = 1; j <= 3; j++) max_ = max(max_, DP[n][j]);

	memset(DP, 0, sizeof(DP));

	DP[1][1] = A[1][1];
	DP[1][2] = A[1][2];
	DP[1][3] = A[1][3];
	
	for (int i = 2; i <= n; i++)
	{
		DP[i][1] = min(DP[i - 1][1], DP[i - 1][2]) + A[i][1];
		DP[i][2] = min(min(DP[i - 1][1], DP[i - 1][2]), DP[i - 1][3]) + A[i][2];
		DP[i][3] = min(DP[i - 1][2], DP[i - 1][3]) + A[i][3];
	}

	int min_ = 987654321;
	for (int j = 1; j <= 3; j++) min_ = min(min_, DP[n][j]);

	cout << max_ << " " << min_ << endl;

	return 0;
}