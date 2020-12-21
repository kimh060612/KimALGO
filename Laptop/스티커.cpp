#include <iostream>
#include <fstream>
#include <memory.h>
#define INF 100001
#define max(a, b) a > b ? a : b 

using namespace std;

ifstream fin;
ofstream fout;

int A[5][INF];
int DP[5][INF];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;
		memset(DP, 0, sizeof(DP));
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> A[i][j];
			}
		}

		DP[1][1] = A[1][1];
		DP[2][1] = A[2][1];
		
		for (int j = 2; j <= N; j++)
		{
			for (int i = 1; i <= 2; i++)
			{
				if (i == 1) 
				{
					int tmp = max(DP[1][j - 2] + A[i][j], DP[2][j - 2] + A[i][j]);
					DP[i][j] = max(DP[2][j - 1] + A[i][j], tmp);
				}
				else 
				{
					int tmp = max(DP[2][j - 2] + A[i][j], DP[1][j - 2] + A[i][j]);
					DP[i][j] = max(DP[1][j - 1] + A[i][j], tmp);
				}
			}
		}

		int ans = max(DP[1][N], DP[2][N]);
		cout << ans << endl;

	}

	fin.close();
	fout.close();
	return 0;
}