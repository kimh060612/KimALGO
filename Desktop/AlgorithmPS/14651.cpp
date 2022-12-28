#include <iostream>
#define MOD 1000000009

using namespace std;

int main() {
	int n;
	long long DP[40000][3];
	cin >> n;

	DP[1][0] = 0;
	DP[1][1] = 1;
	DP[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			DP[i][j] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % MOD;
		}
	}

	cout << DP[n][0] % MOD << endl;
}
