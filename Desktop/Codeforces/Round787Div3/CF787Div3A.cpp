#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;
		if (a >= x && b >= y) {
			cout << "YES" << endl;
		}
		else if (a < x && b >= y) {
			if (a + c >= x) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else if (a >= x && y > b)
		{
			if (b + c >= y) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else {
			if (a + b + c >= x + y) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}