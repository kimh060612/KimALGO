#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

ifstream fin;
ofstream fout;

int T;
int DP[101];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;
		memset(DP, 0, sizeof(DP));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j*i <= N; j++)
			{
				if (DP[i*j] == 0)DP[i*j] = 1;
				else DP[i*j] = 0;
			}
		}
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			sum += DP[i];
		}
		cout << sum << endl;
	}

	fin.close();
	fout.close();
	return 0;
}