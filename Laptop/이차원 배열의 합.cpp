#include <iostream>
#include <fstream>
#define MAX 301

using namespace std;

ifstream fin;
ofstream fout;

int DP[MAX][MAX];

int N, M;

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int val;
			cin >> val;
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + val;
		}
	}

	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		int i,j,x,y;
		cin >> i >> j >> x >> y;
		cout << DP[x][y] - DP[x][j - 1] - DP[i - 1][y] + DP[i - 1][j - 1] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}