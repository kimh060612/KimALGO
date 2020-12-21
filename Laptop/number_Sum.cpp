#include <iostream>
#include <fstream>
#include <memory.h>
#define MAX 2001
#define MOD 100999

using namespace std;

ifstream fin;
ofstream fout;

int DP[MAX];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int T;
	cin >> T;

	DP[0] = 1;
	for (int i = 1; i <= MAX; ++i) {
		for (int j = MAX - i; j >= 0; --j) {
			DP[i + j] = (DP[i + j] + DP[j]) % MOD;
		}
	}

	for (int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;
		cout << DP[N] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}