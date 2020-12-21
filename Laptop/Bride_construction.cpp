#include <iostream>
#include <fstream>
#include <memory.h>
#define MAX 31

using namespace std;

ifstream fin;
ofstream fout;

int DP[MAX][MAX];

int Combination(int n, int r)
{
	if (n == r || r == 0)return 1;
	int &ret = DP[n][r];
	if (ret != -1)return ret;
	ret = Combination(n - 1, r - 1) + Combination(n - 1, r);
	return ret;
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int T;
	fin >> T;
	for (int i = 1; i <= T; i++)
	{
		int N, M;
		fin >> N >> M;

		memset(DP, -1, sizeof(DP));

		fout << Combination(M, N) << endl;

	}

	fin.close();
	fout.close();
	return 0;
}