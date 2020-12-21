#include <iostream>
#include <fstream>
#define MAX 10010
#define max(a,b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

int N;
int PO[MAX];
int DP[MAX];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	for (int i = 1; i <= N;i++)
	{
		cin >> PO[i];
	}

	DP[1] = PO[1];
	DP[2] = PO[1] + PO[2];

	for (int i = 3; i <= N; i++)
	{
		DP[i] = max(DP[i - 2] + PO[i], DP[i - 3] + PO[i] + PO[i - 1]);
		DP[i] = max(DP[i - 1], DP[i]);
	}

	cout << DP[N] << endl;

	fin.close();
	fout.close();
	return 0;
}