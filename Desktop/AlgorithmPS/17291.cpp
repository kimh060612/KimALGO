#include <iostream>

using namespace std;

int DP[30];

int main()
{
	int n;
	cin >> n;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	DP[4] = 7;
	for (int i = 5; i <= n; i++)
	{
		if (i % 2 == 0) {
			DP[i] = DP[i - 1] * 2 - (DP[i - 4] + DP[i - 5]);
		}
		else {
			DP[i] = DP[i - 1] * 2;
		}
	}
	cout << DP[n] << endl;
	return 0;
}