#include <iostream>
#include <math.h>

using namespace std;

int A[5001], DP[5001];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	DP[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int indicator = 0;
		for (int j = 1; j < i; j++)
		{
			int w = (i - j) * (1 + abs(A[i] - A[j]));
			if (w < k && DP[j] == 1) indicator = 1;
		}
		DP[i] = indicator;
	}

	if (DP[n] == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}