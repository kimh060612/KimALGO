#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		double res = 350.34 * a + 230.90 * b + 190.55 * c + 125.30 * d + 180.90 * e;
		cout << fixed;
		cout.precision(2);
		cout << "$" << res << endl;
	}
	return 0;
}