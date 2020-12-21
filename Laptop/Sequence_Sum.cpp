#include <iostream>
#include <fstream>
#define INF 100001

using namespace std;

ifstream fin;
ofstream fout;

int A[INF], DP[INF];



int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	DP[1] = A[1];
	//DP[2] = A[1] + A[2];

	for (int i = 2; i <= n; i++)
	{
		DP[i] = A[i] > A[i] + DP[i - 1] ? A[i] : A[i] + DP[i - 1];
	}

	int max = -987654321;
	for (int i = 1; i <= n; i++)
	{
		if (max < DP[i]) max = DP[i];
	}

	cout << max << endl;

	fin.close();
	fout.close();
}