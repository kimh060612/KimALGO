#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, s, sum = 0;
		cin >> s >> n;
		sum = s;
		for (int i = 1; i <= n; i++)
		{
			int q, p;
			cin >> q >> p;
			sum += q * p;
		}
		cout << sum << endl;
	}
	return 0;
}