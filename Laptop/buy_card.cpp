#include <iostream>
#include <fstream>
#define max(a,b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int N;
int P[1001];
int DP[1001];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			DP[i] = max(DP[i], DP[i - j] + P[j]);
		}
	}

	cout << DP[N] << endl;

	fin.close();
	fout.close();
	return 0;
}