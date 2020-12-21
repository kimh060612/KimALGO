#include <iostream>
#include <fstream>
#define max(a, b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int A[301], DP[301];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	DP[1] = A[1];
	DP[2] = A[1] + A[2];

	for (int i = 3; i <= N; i++)
	{
		DP[i] = max(DP[i - 2] + A[i], A[i - 1] + DP[i - 3] + A[i]);
	}

	cout << DP[N] << endl;

	fin.close();
	fout.close();
	return 0;
}