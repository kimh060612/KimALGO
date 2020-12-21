#include <iostream>
#include <fstream>
#define MAX 101

using namespace std;

ifstream fin;
ofstream fout;

int N, K;
int coin[MAX], DP[10001];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	fin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		fin >> coin[i];
	}

	DP[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (coin[i] <= j)DP[j] += DP[j-coin[i]];
		}
	}

	fout << DP[K] << endl;

	fin.close();
	fout.close();
	return 0;
}