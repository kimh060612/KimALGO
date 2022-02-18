#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int k = a * p;
	int l = p > c ? (p - c) * d + b : b;

	int ans = k > l ? l : k;
	cout << ans << endl;
	return 0;
}