#include <iostream>
#include <memory.h>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int DP[501][13];

int f(int n, int bit) {
	if (n < 0) return 0;
	if (n < 1) return bit == 0;
	int& r = DP[n][bit];
	if (r != -1) return r;

	r = 0;
	if (bit == 0) {
		r += f(n - 1, 0);
		r += f(n - 1, 3);
		r += f(n - 1, 9);
		r += f(n - 1, 12);
		r += f(n - 2, 0);
	}
	if (bit == 3) {
		r += f(n - 1, 0);
		r += f(n - 1, 12);
	}
	if (bit == 6) {
		r += f(n - 1, 9);
	}
	if (bit == 9) {
		r += f(n - 1, 0);
		r += f(n - 1, 6);
	}
	if (bit == 12) {
		r += f(n - 1, 0);
		r += f(n - 1, 3);
	}
	return r;
}


int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;
		memset(DP, -1, sizeof(DP));

		cout << f(N, 0) << endl;

	}

	fin.close();
	fout.close();
	return 0;
}