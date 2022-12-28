#include <iostream>
#include <algorithm>

using namespace std;

int A[500001];
int n, m;

bool isIn(int x)
{
	int s = 1, e = n;
	
	while (s <= e)
	{
		int mid = (e + s) / 2;
		if (A[mid] == x) return true;
		else if (A[mid] < x) s = mid + 1;
		else e = mid - 1;
	}
	return false;
}

int  main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	sort(A + 1, A + 1 + n);

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		int k = isIn(a) ? 1 : 0;
		cout << k << " ";
	}
	cout << endl;
	return 0;
}