#include <iostream>
#include <algorithm>

using namespace std;

int DP[1001];

int main()
{
	int n;
	cin >> n;
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 0;
	DP[4] = 1;
	for (int i = 5; i <= 1000; i++)
	{
		if (min({ DP[i - 1], DP[i - 3], DP[i - 4] }) == 1) DP[i] = 0;
		else DP[i] = 1;
	}
	if (!DP[n])cout << "CY" << endl;
	else cout << "SK" << endl;
	return 0;
}