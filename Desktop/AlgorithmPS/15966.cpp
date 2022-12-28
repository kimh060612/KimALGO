#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, A[100001], DP[1000001];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= n; i++)
	{
		DP[A[i]] = max(DP[A[i]], DP[A[i] - 1] + 1);
	}

	int ans = -987654321;
	for (int i = 1; i <= n; i++) ans = max(ans, DP[A[i]]);

 	cout << ans << endl;

	return 0;
}