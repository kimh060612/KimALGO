#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll A[100001];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + 1 + n);

	ll R[2] = { 0, }, diff = 2e9 + 1;
	for (int i = 1; i <= n; i++)
	{
		int k = (lower_bound(A + 1, A + 1 + n, -1 * A[i]) - A);
		for (int j = k - 1; j <= k; j++)
		{
			if (j <= 0 || j > n || i == j) continue;
			if (diff > abs(A[j] + A[i])) {
				R[0] = A[i];
				R[1] = A[j];
				diff = abs(A[j] + A[i]);
			}
		}
	}
	if (R[0] > R[1]) swap(R[0], R[1]);
	cout << R[0] << " " << R[1] << endl;
	return 0;
}