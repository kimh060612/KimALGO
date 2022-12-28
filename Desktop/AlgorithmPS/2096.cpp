#include <iostream>

using namespace std;

int A[100001][3];
int minDP[2][3];
int maxDP[2][3];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 2; j++)
			cin >> A[i][j];

	maxDP[1][0] = A[1][0];
	maxDP[1][1] = A[1][1];
	maxDP[1][2] = A[1][2];
	minDP[1][0] = A[1][0];
	minDP[1][1] = A[1][1];
	minDP[1][2] = A[1][2];

	for (int i = 2; i <= n; i++)
	{
		maxDP[2][0] = max(maxDP[1][0], maxDP[1][1]) + A[i][0];
		maxDP[2][1] = max(maxDP[1][0], max(maxDP[1][1], maxDP[1][2])) + A[i][1];
		maxDP[2][2] = max(maxDP[1][1], maxDP[1][2]) + A[i][2];
		maxDP[1][0] = maxDP[2][0];
		maxDP[1][1] = maxDP[2][1];
		maxDP[1][2] = maxDP[2][2];
	}

	for (int i = 2; i <= n; i++)
	{
		minDP[2][0] = min(minDP[1][0], minDP[1][1]) + A[i][0];
		minDP[2][1] = min(minDP[1][0], min(minDP[1][1], minDP[1][2])) + A[i][1];
		minDP[2][2] = min(minDP[1][1], minDP[1][2]) + A[i][2];
		minDP[1][0] = minDP[2][0];
		minDP[1][1] = minDP[2][1];
		minDP[1][2] = minDP[2][2];
	}

	int maxANS = max(max(maxDP[1][0], maxDP[1][1]), maxDP[1][2]);
	int minANS = min(min(minDP[1][0], minDP[1][1]), minDP[1][2]);

	cout << maxANS << " " << minANS << "\n";

	return 0;
}