#include <iostream>

using namespace std;

long long A[100003], DP[100001];

int main()
{
	int n;
	cin >> n;
	A[0] = -9876543210;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		if (A[i] >= A[i - 1]) DP[i] = 1;
		else count += 1;
	}
	A[n + 1] = 9876543210;
	DP[n + 1] = 1;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (A[i + 1] >= A[i - 1] && (DP[i] == 0 || DP[i + 1] == 0)) ans += 1;
	}
	
	if (count == 0) cout << n << endl;
	else if (count > 1) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}