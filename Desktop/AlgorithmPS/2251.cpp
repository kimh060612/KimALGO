#include <iostream>

using namespace std;
int A, B, C;
int answer[201], DP[201][201][201], visited[201][201][201];

int min(int a, int b) { return a < b ? a : b; }

void dfs(int a, int b, int c)
{
	if (DP[a][b][c]) return;

	if (a == 0) {
		answer[c] = 1;
		DP[a][b][c] = 1;
	}

	visited[a][b][c] = 1;

	if (a != 0) {
		int da1 = min(a, B - b);
		int da2 = min(a, C - c);
		if (!visited[a - da1][b + da1][c]) dfs(a - da1, b + da1, c);
		if (!visited[a - da2][b][c + da2]) dfs(a - da2, b, c + da2);
	}
	if (b != 0) {
		int db1 = min(b, A - a);
		int db2 = min(b, C - c);
		if (!visited[a + db1][b - db1][c]) dfs(a + db1, b - db1, c);
		if (!visited[a][b - db2][c + db2]) dfs(a, b - db2, c + db2);
	}
	if (c != 0) {
		int dc1 = min(c, B - b);
		int dc2 = min(c, A - a);
		if (!visited[a][b + dc1][c - dc1]) dfs(a, b + dc1, c - dc1);
		if (!visited[a + dc2][b][c - dc2]) dfs(a + dc2, b, c - dc2);
	}
}

int main()
{
	cin >> A >> B >> C;

	dfs(0, 0, C);

	for (int i = 0; i <= 200; i++)
	{
		if (answer[i] == 1)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}