#include <iostream>
#include <fstream>
#define max(a, b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int N;
int T[20], P[20];
int DP[30];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; i--)
	{
		int next = i + T[i];
		if (next > N + 1)DP[i] = DP[i + 1];
		else DP[i] = max(DP[i+1], DP[next] + P[i]);
	}

	cout << DP[1] << endl;

	fin.close();
	fout.close();
	return 0;
}