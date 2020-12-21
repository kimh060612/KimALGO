#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

ifstream fin;
ofstream fout;

long long DP[101];

long long FIBO(int n)
{
	long long &ret = DP[n];
	if (ret != -1)return ret;

	ret = FIBO(n - 5) + FIBO(n - 1);
	return ret;
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int T;
	cin >> T;

	memset(DP,-1,sizeof(DP));
	DP[1] = 1; DP[2] = 1; DP[3] = 1; DP[4] = 2; DP[5] = 2;

	for (int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;
		cout << FIBO(N) << endl;
	}

	fin.close();
	fout.close();
	return 0;
}