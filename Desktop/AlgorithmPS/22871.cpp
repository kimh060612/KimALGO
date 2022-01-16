#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;

ll A[5001], DP[5001];

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{ 
		cin >> A[i]; 
		DP[i] = 9876543210;
	}

	DP[1] = 0;
	DP[2] = (1 + abs(A[2] - A[1]));

	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			ll t = max(DP[j], (i - j) * (1 + abs(A[i] - A[j])));
			DP[i] = min(DP[i], t);
		}
	}

	cout << DP[n] << endl;
	return 0;
}