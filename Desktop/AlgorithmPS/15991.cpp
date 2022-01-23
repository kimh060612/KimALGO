#include <iostream>
#define MOD 1000000009

using namespace std;

long long DP[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 2;
	DP[4] = 3;
	DP[5] = 3;
	DP[6] = 6;
	for (int i = 7; i <= 100000; i++)
	{
		DP[i] = (DP[i - 2] + DP[i - 4] + DP[i - 6]) % MOD;
	}

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		cout << DP[a] << "\n";
	}
	return 0;
}