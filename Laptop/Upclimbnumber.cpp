#include <iostream>
#include <fstream>
#define MOD 10007
#define MAX 1001

using namespace std;

ifstream fin;
ofstream fout;

int N;
int DP[MAX][11];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >>  N;

	for (int i = 1; i <= 10; i++)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				DP[i][j] += DP[i - 1][k];
				DP[i][j] = DP[i][j] % MOD;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += DP[N][i];
	}

	cout << sum % MOD << endl;

	fin.close();
	fout.close();
}