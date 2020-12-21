#include <iostream>
#include <memory.h>
#include <fstream>
#define MAX 1001
#define max(a, b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int N, M;
int MAP[MAX][MAX];
int DP[MAX][MAX];

/*
int AntiSearch(int y, int x)
{
	if (x < 0 || y < 0)return 0;
	int &ret = DP[y][x];
	if (ret != 0)return ret;

	int next = max(max(AntiSearch(y - 1, x), AntiSearch(y, x - 1)), AntiSearch(y - 1, x - 1));
	ret = next + MAP[y][x];

	return ret;
}*/

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> MAP[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int next = max(max(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]);
			DP[i][j] = next + MAP[i][j];
		}
	}

	cout << DP[N][M] << endl;

	fin.close();
	fout.close();
	return 0;
}