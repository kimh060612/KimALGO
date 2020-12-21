#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

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
		int DP[15] = {};
		DP[0] = 1;

		for (int j = 1; j <= N; j++) {

			if (j - 1 >= 0)DP[j] += DP[j - 1];
			if (j - 2 >= 0)DP[j] += DP[j - 2];
			if (j - 3 >= 0)DP[j] += DP[j - 3];
		}

		cout << DP[N] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}