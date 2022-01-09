#include <iostream>

using namespace std;
typedef long long ll;

ll A[1001], DP[1001];
ll max(ll a, ll b) { return a > b ? a : b; }

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		DP[i] = A[i];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (A[i] > A[j]) DP[i] = max(DP[i], DP[j] + A[i]);
		}
	}

	ll ans = -1;
	for (int i = 1; i <= n; i++) ans = max(ans, DP[i]);

	cout << ans << endl;
	return 0;
}