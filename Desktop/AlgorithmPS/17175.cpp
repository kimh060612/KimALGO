#include <iostream>
#define MOD 1000000007

using namespace std;

int DP[100];

int fibo(int n)
{
	if (n <= 1) return 1;
	int &ret = DP[n];
	if (ret != 0) return ret;
	return ret = (fibo(n - 1) + fibo(n - 2) + 1) % MOD;
}

int main()
{
	int n;
	cin >> n;
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 3;
	DP[3] = 5;
	cout << fibo(n) % MOD << endl;
	return 0;
}