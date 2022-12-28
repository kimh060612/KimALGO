#include <iostream>

using namespace std;

long long DP[35];

int main()
{
	int n;
	cin >> n;

	DP[0] = 1;
	DP[1] = 1;

	for (int i = 2; i <= 30; i++) DP[i] = DP[i - 1] + DP[i - 2] * 2;

	if (n % 2 == 1) { cout << (DP[n] + DP[(n - 1) / 2]) / 2 << "\n"; }
	else { cout << (DP[n] + DP[n / 2] + DP[n / 2 - 1] * 2) / 2 << "\n"; }

	return 0;
}