#include <iostream>
#include <algorithm>
#include <fstream>
#define max(a, b) a > b ? a : b
#define MAX 1001

using namespace std;

ifstream fin;
ofstream fout;

int N, A[MAX], DP[MAX];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	
	DP[1] = A[1];

	for (int i = 1; i <= N; i++)
	{
		int MaxDP = 0;
		for (int j = 1; j <= i; j++)
		{
			if (A[i] > A[j]) MaxDP = max(MaxDP, DP[j]);
		}
		DP[i] = A[i] + MaxDP;
	}

	int Max = -987654321;
	for (int i = 1; i <= N; i++) 
	{ 
		if (Max < DP[i])Max = DP[i]; 
	}

	cout << Max << endl;

	fin.close();
	fout.close();
	return 0;
}