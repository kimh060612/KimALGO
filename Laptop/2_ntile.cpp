#include <iostream>
#include <memory.h>
#define MOD 10007

using namespace std;

int DP[1001];

int FIBO(int n)
{
	int &ret = DP[n];
	if (ret != -1)return ret;

	ret = (FIBO(n - 1) + FIBO(n - 2)) % MOD;
	return ret;

}

int main()
{

	int N;
	cin >> N;

	memset(DP, -1, sizeof(DP));
	DP[1] = 1;
	DP[2] = 2;

	cout << FIBO(N) << endl;

	return 0;
}