#include <iostream>

using namespace std;
typedef long long ll;

ll A[200001], B[200001], DP[3][200001];
ll min(ll a, ll b) { return a < b ? a : b; }

int main()
{
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];

	DP[1][1] = A[1];
	DP[2][1] = B[1];

	for (int i = 2; i <= n; i++)
	{
		DP[1][i] = min(DP[1][i - 1], DP[2][i - 1] + k) + A[i];
		DP[2][i] = min(DP[2][i - 1], DP[1][i - 1] + k) + B[i];
	}

	cout << min(DP[1][n], DP[2][n]) << endl;

	return 0;
}