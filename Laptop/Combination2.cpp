#include <iostream>
#include <fstream>
#define MOD 10007

using namespace std;

ifstream fin;
ofstream fout;

int N, K;
int DP[1001][1001];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)DP[i][0] = 1;

	DP[1][0] = 1;
	DP[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j])%MOD;
		}
	}

	cout << (DP[N][K]%MOD) << endl;

	fin.close();
	fout.close();
	return 0;
}