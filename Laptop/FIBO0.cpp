#include <iostream>
#include <fstream>
#define MAX 50

using namespace std;

ifstream fin;
ofstream fout;

int DP[MAX], T;

int FIBO(int n)
{
	int &ret = DP[n];
	if (ret != 0) return ret;
	if (n == 0)return 0;

	ret = FIBO(n - 1) + FIBO(n - 2);
	return ret;
}

void clear(int n)
{
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		DP[i] = 0;
	}
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	DP[1] = 1;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int A;
		cin >> A;
		if (A == 0)cout << "1 0" << endl;
		else if(A == 1) cout << "0 1" << endl;
		else
		{
			int tmp = FIBO(A);
			cout << DP[A-1] <<" "<< DP[A] << endl;
		}
		clear(A);
	}
	fin.close();
	fout.close();
	return 0;
}