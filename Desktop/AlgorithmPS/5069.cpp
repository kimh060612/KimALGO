#include <iostream>
using namespace std;
int DP[15][21][21];
int dy[] = { 0,0,1,1,-1,-1 };
int dx[] = { 1,-1,1,0,-1,0 };
int main(void) {
	int T, a;
	cin >> T;
	DP[0][10][10] = 1;
	for (int i = 1; i < 15; i++)
		for (int t = 1; t < 21; t++)
			for (int y = 1; y < 21; y++)
				for (int u = 0; u < 6; u++)
					if (t + dx[u] > 0 && t + dx[u] < 21 && y + dy[u] > 0 && y + dy[u] < 21)
						DP[i][t][y] += DP[i - 1][t + dx[u]][y + dy[u]];
	while (T--) {
		cin >> a;
		cout << DP[a][10][10] << endl;
	}
	return 0;
}
