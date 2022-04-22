#include <iostream>

using namespace std;

int n, s;
int A[100001];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) 
	{
		cin >> A[i];
	}

	int sp = 1, ep = 1, tot = A[1];
	int ans = 987654321;
	for (sp = 1; sp <= n; sp++)
	{
		while (ep <= n && tot < s) {
			ep++;
			if (ep != n + 1) tot += A[ep];
		}
		if (ep > n) break;
		ans = min(ans, ep - sp + 1);
		tot -= A[sp];
	}

	if (ans == 987654321) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}