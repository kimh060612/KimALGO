#include <iostream>
#include <fstream>
#define max(a, b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int A[501][501];
int DP[501][501];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		DP[N][i] = A[N][i];
	}

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			DP[i][j] = max(A[i][j] + DP[i + 1][j], A[i][j] + DP[i + 1][j + 1]);
		}
	}

	cout << DP[1][1] << endl;

	fin.close();
	fout.close();
	return 0;
}