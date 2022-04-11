#include <iostream>
#include <vector>

using namespace std;

int DP[61][61][61], n;
vector<int> A;

int ack3[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3} };
int ack2[2][2] = { {9, 3}, {3, 9} };
int ack1 = 9;

int min(int a, int b) { return a < b ? a : b; }

int dfs(vector<int> S, int depth)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
		if (S[i] != 0) flag = false;
	if (flag) return depth;
	
	if (n == 3) {
		if (DP[S[0]][S[1]][S[2]] != 987654321) return DP[S[0]][S[1]][S[2]];
		for (int i = 0; i < 6; i++)
		{
			vector<int> L;
			L.assign(n, 0);
			for (int j = 0; j < n; j++)
				L[j] = S[j] - ack3[i][j] > 0 ? S[j] - ack3[i][j] : 0;
			DP[S[0]][S[1]][S[2]] = min(DP[S[0]][S[1]][S[2]], dfs(L, depth + 1));
		}
		return DP[S[0]][S[1]][S[2]];
	}
	else if (n == 2) {
		if (DP[S[0]][S[1]][0] != 987654321) return DP[S[0]][S[1]][0];
		for (int i = 0; i < 2; i++)
		{
			vector<int> L;
			L.assign(n, 0);
			for (int j = 0; j < n; j++)
				L[j] = S[j] - ack2[i][j] > 0 ? S[j] - ack2[i][j] : 0;
			DP[S[0]][S[1]][0] = min(DP[S[0]][S[1]][0], dfs(L, depth + 1));
		}
		return DP[S[0]][S[1]][0];
	}
	else {
		if (DP[S[0]][0][0] != 987654321) return DP[S[0]][0][0];
		vector<int> L;
		L.assign(n, 0);
		L[0] = S[0] - ack1 > 0 ? S[0] - ack1 : 0;
		DP[S[0]][0][0] = min(DP[S[0]][0][0], dfs(L, depth + 1));
		return DP[S[0]][0][0];
	}
}

int main()
{
	cin >> n;
	A.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i <= 60; i++)
		for (int j = 0; j <= 60; j++)
			for (int k = 0; k <= 60; k++)
				DP[i][j][k] = 987654321;

	int ans = dfs(A, 0);

	cout << ans << endl;

	return 0;
}