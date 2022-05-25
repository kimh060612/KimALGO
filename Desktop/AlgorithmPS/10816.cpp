#include <iostream>
#include <algorithm>

using namespace std;

int check[500001], A[20000001];
int n, m;

bool isIn(int x)
{
	int s = 1, e = n;

	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (A[mid] == x) return true;
		else if (A[mid] < x) s = mid + 1;
		else e = mid - 1;
	}
	return false;
}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		A[a + 10000000] ++;
	}

	int cnt = 1;
	for (int i = 0; i <= 20000000; i++)
	{
		if (A[i] != 0)
		{
			check[cnt] = i;
			cnt++;
		}
	}
	sort(check + 1, check + 1 + n);

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		a += 10000000;
		cout << A[a] << " ";
	}

	return 0;
}