#include <iostream>
#define MOD 15746
#define INF 1000001

using namespace std;

int DP[INF], N;

int FIBO(int n)
{
	int &ret = DP[n];
	if (ret != 0)return ret;
	ret = FIBO(n - 1)%MOD + FIBO(n - 2)%MOD;
	return ret;
}

int main()
{
	cin >> N;
	DP[1] = 1;
	DP[2] = 2;
	cout << FIBO(N)%MOD << endl;
	return 0;
}