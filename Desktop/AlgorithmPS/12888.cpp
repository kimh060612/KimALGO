#include <iostream>

using namespace std;
typedef long long ll;

ll DP[70];

int main()
{
	int n;
	cin >> n;

	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 3;

	for (int i = 3; i <= n; i++) DP[i] = DP[i - 1] + 2 * DP[i - 2];

	cout << DP[n] << endl;

	return 0;
}