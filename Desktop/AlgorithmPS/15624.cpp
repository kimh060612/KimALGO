#include <iostream>
#define MOD 1000000007

using namespace std;

long long DP[1000001];

int main()
{
	int n;
	cin >> n;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 2;
	for (int i = 4; i <= n; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
	}
	cout << DP[n] % MOD << endl;
	return 0;
}