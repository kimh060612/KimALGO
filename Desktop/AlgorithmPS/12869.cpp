#include <iostream>
#include <vector>

using namespace std;

int DP[61][61][61], n;
vector<int> A;

int ack[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3} };

int min(int a, int b) { return a < b ? a : b; }

int dfs(vector<int> S)
{
	if (S[0] == 0 && S[1] == 0 && S[2] == 0) return 0;
	
	if (DP[S[0]][S[1]][S[2]] != -1) return DP[S[0]][S[1]][S[2]];

	DP[S[0]][S[1]][S[2]] = 987654321;
	for (int i = 0; i < 6; i++)
	{
		vector<int> L;
		L.assign(3, 0);
		for (int j = 0; j < 3; j++)
			L[j] = S[j] - ack[i][j] > 0 ? S[j] - ack[i][j] : 0;
		DP[S[0]][S[1]][S[2]] = min(DP[S[0]][S[1]][S[2]], dfs(L) + 1);
	}
	return DP[S[0]][S[1]][S[2]];
}

int main()
{
	cin >> n;
	A.assign(3, 0);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i <= 60; i++)
		for (int j = 0; j <= 60; j++)
			for (int k = 0; k <= 60; k++)
				DP[i][j][k] = -1;

	int ans = dfs(A);

	cout << ans << endl;

	return 0;
}