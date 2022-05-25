#include <iostream>
#include <algorithm>

using namespace std;

int A[5000001];

int main()
{
	int n, k;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];

	sort(A + 1, A + 1 + n);
	cout << A[k] << endl;
	return 0;
}