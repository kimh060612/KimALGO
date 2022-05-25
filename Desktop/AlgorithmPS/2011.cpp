#include <iostream>
#include <string>
#define MOD 1000000

using namespace std;

int DP[5002];

int main()
{
	string s;
	cin >> s;

	DP[0] = 1;
	DP[1] = 1;

	for (int i = 2; i <= s.size(); i++)
	{
		int p = s[i - 2] - '0';
		int c = s[i - 1] - '0';

		if (c != 0) DP[i] = (DP[i] + DP[i - 1]) % MOD;
		int tmp = 10 * p + c;
		if (10 <= tmp && tmp <= 26) DP[i] = (DP[i] + DP[i - 2]) % MOD;
	}

	if (s[0] == '0') cout << 0 << endl;
	else cout << DP[s.size()] << endl;
	return 0;
}