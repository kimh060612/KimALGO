#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int DP[101][15];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++) 
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				DP[i][0] = DP[i - 1][1] % 1000000000;
			}
			else if (j == 9)
			{
				DP[i][j] = DP[i - 1][j - 1] % 1000000000;
			}
			else
			{
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= 9; i++)
	{
		sum = (sum + DP[n][i]) % 1000000000;
	}

	cout << sum % 1000000000 << endl;

	fin.close();
	fout.close();
}